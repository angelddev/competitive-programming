    #include <bits/stdc++.h>

    #define ll long long 
    #define endl '\n'
    #define all(a) begin(a), end(a)
    #define pll pair<ll, ll>
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vpl vector<pll>
    #define f(i, s, e) for(ll i=s; i<e; i++)
    #define cf(i, s, e) for(ll i=s; i<=e; i++)
    #define rf(i, s, e) for(ll i=s; i>=e; i--)
    #define F first
    #define S second
    #define pb push_back
    using namespace std;

    const ll INF = 1e18;
    const ll MOD = 1e9 +7;
    const int LOG = 30;
    ll st[800009];
    vll arr;
    vvll adj;
    vll reps;
    vll vis;

    void dfs(ll node, ll rep){
        
        vis[node]=1;
        for(auto e : adj[node]){
            if(reps[e]==-1||(reps[e]==rep&&vis[e]==0)){
                reps[e]=rep;
                dfs(e, rep);
            }
        }
    }


    void build(ll pos, ll l, ll r){

        if(l==r) st[pos] = arr[l]; 
        else{
            ll m=(l+r)/2;
            build(2*pos, l, m);
            build(2*pos+1, m+1, r); 
            st[pos] = min(st[2*pos], st[2*pos+1]);
        }

    }

    ll query(ll pos, ll l, ll r){

        if(l == r) return l; 
        ll m=(l+r)/2; 
        if(st[2*pos] <= st[2*pos+1]) return query(2*pos, l, m); 
        else return query(2*pos+1, m+1, r); 

    }

    void update(ll pos, ll l, ll r, ll k, ll v){
        //cout<<pos<<" "<<l<<" "<<r<<"\n";

        if(l==r){
            st[pos] = v;
            return;
        } 
        ll m=(l+r)/2; 
        if(k<=m) update(2*pos, l, m, k, v); 
        else update(2*pos+1, m+1, r, k, v);
        st[pos]=min(st[2*pos], st[2*pos+1]); 

    }


    void solve(){

        ll n, m; cin >> n >> m;
        adj.assign(n+1, vll());
        set<ll> lideres;
        vll lids;
        vis.assign(n+1, 0);

        ll p;
        f(i,0,m){
            cin >> p;
            lids.pb(p);
            lideres.insert(p);
        }

        vll degree(n+1, 0);
        ll x, y;
        f(i,0,n-1){
            cin >> x >> y;

            if(lideres.count(x)){
                if(!lideres.count(y)){
                    adj[x].pb(y);
                    degree[x]++;
                }   
            } else {
                adj[x].pb(y);
                degree[x]++;
            }

            if(lideres.count(y)){
                if(!lideres.count(x)){
                    adj[y].pb(x);
                    degree[y]++;
                }   
            } else {
                adj[y].pb(x);
                degree[y]++;
            }
        }

        if(n==1){
            cout << "YES\n1\n";
            return;
        }

        arr.assign(n+1, INF);
        for(auto l : lideres){
            arr[l]=degree[l];
        }

        build(1, 1, n);
        reps.assign(n+1, -1);

        ll cont=1;
        for(auto l : lids){
            reps[l]=cont;
            cont++;
        }

        vll exists(n+1, 1);
        ll next = query(1, 1, n);
        vll processed(n + 1, 0);
        
        f(i, 0, m){
            
            if(degree[next]<=0) {
                cout << "NO\n";
                return;
            }

            for(auto e : adj[next]){
                if(exists[e]){
                    for(auto e2 : adj[e]){
                        if(lideres.count(e2)&&!processed[e2]){
                            degree[e2]--;
                            update(1, 1, n, e2, degree[e2]);
                        }
                    }
                    processed[next]=1;
                    reps[e]=reps[next];
                    update(1, 1, n, next, INF);
                    exists[e]=0;
                    break;
                }
            }
            //cout<<"\n";
            //f(i, 0, 3*n) cout<<st[i]<<" "; cout<<"\n";

            next = query(1, 1, n);

            //cout<<next<<" ";
            /*update(1, 1, n, next, INF);
            ll next = query(1, 1, n);
            if(degree[next]==INF) break;*/
        }

        cont=1;
        for(auto l : lids){
            dfs(l, cont);
            cont++;
        }

        //cout << next << "\n";
        //update(1, 1, n, next, INF);
        cout << "YES\n";
        cf(i,1,n){
            cout << reps[i] << " ";
        } cout << "\n";

        
        arr.clear();
        adj.clear();
        reps.clear();
        vis.clear();
    }

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 

        ll t; cin >> t;
        while(t--){
            solve(); 
        }
    }