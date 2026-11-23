#include <bits/stdc++.h>
#define ll long long
#define end '\n'
#define f(i,s,e) for(ll i=s; i<e; i++)
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define sz(x) int((x).size())
#define all(a) begin(a), end(a)
#define pll pair<long long, long long>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define MOD(x) ((((x) % mod)+mod)%mod)
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long double ld;

const ll INF = 1e9;
const ll mod = 1e9+7;
ll t, n, m, k, a, b, c, tot;
ll h[200005], sumPiso[200005]; 
vll adj[200005], cost, rots, tr; 
vll app[200005]; vpl pisos;
ll st[1600005];
ll pos; 
string s;

ll alt(ll u, ll p){
    ll ans=0; 
    for(auto v: adj[u]){
        if(v == p) continue; 
        ans=max(ans, alt(v, u)+1); 
    }
    return ans;
}

void traversal(ll u, ll p){
    tr.pb(u);
    h[u]=h[p]+1; 
    app[u].pb(tr.size()-1); 
    for(auto v: adj[u]){
        if(v == p) continue; 
        traversal(v, u); 
        tr.pb(u); 
        app[u].pb(tr.size()-1); 
    }
}

void dfs(ll u, ll p){
    if(cost[u] != 0){
        pisos[h[u]].F = min(pisos[h[u]].F, app[u][0]);
        pisos[h[u]].S = max(pisos[h[u]].S, app[u][app[u].size()-1]);  
        sumPiso[h[u]] += cost[u]; 
    } 
    for(auto v: adj[u]){
        if(v==p) continue; 
        dfs(v, u); 
    }
}

void build(ll pos, ll l, ll r){
    if(l==r) st[pos] = h[tr[l]];
    else{
        ll m=(l+r)/2;
        build(2*pos, l, m); 
        build(2*pos+1, m+1, r);
        st[pos] = min(st[2*pos], st[2*pos+1]); 
    }
}

ll querie(ll pos, ll l, ll r, ll ql, ll qr){
    if(r<ql or l>qr) return INF;
    if(l>=ql && r<=qr) return st[pos]; 
    ll m=(l+r)/2; 
    return min(querie(2*pos, l, m, ql, qr), querie(2*pos+1, m+1, r, ql, qr)); 
}

void solve(){

    ll n; cin >> n;
    cost.assign(n+1, 0);
    ll ans=0, pos=0;
    cf(i,2,n){
        cin >>cost[i]; 
    }
 
    ll x, y;
    f(i,0,n-1){
        cin >> x >> y;
        if(x==1)rots.pb(y);
        if(y==1)rots.pb(x);

        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(auto r: rots){
        //cout<<r<<":\n"; 
        ll a = alt(r, 1)+1; 
        cf(i, 0, a) sumPiso[i]=0; 
        pisos.clear(); 
        pisos.assign(a+5, {INF, -1});
        tr.clear(); 
        traversal(r, 1); 
        //for(auto u: tr) cout<<u<<" "; cout<<"\n"; 
        dfs(r, 1); 
        build(1, 0, tr.size() - 1);
        //cf(i, 1, a) cout<<i<<": "<<sumPiso[i]<<"\n"; 
         cf(i, 1, a){
            //cout<<i<<": "<<pisos[i].F<<" "<<pisos[i].S<<"\n"; 
            //cout<<i<<": "<<querie(1, 0, tr.size()-1, pisos[i].F, pisos[i].S)<<"\n"; 
            if (pisos[i].F == INF) continue;
            if(ans<sumPiso[i]){
                ll o=querie(1, 0, tr.size()-1, pisos[i].F, pisos[i].S); 
                ans = sumPiso[i]; pos=i-o+1; 
            }
            else if(ans==sumPiso[i]){
                ll o=querie(1, 0, tr.size()-1, pisos[i].F, pisos[i].S); 
                if(i-o < pos) pos=i-o+1;
            }
        } 
    }

    cf(i,2,n){
        if(cost[i] > ans){ ans=cost[i]; pos=1; }
    }
    cout<<ans<<" "<<pos<<"\n"; 

}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    while(t--) solve();
}