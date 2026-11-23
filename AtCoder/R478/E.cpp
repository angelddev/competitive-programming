#include <bits/stdc++.h>

#define ll long long 
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

vvll adjEQUAL;
vvll adjLESS;
vvll radj;
vll vis;
vll val;
vll order, comp;
ll cnt = 0;
stack <ll> stk;


void dfs(ll node){
    vis[node] = 1;

    for(ll v: adjLESS[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    for(ll v: adjEQUAL[node]){
        if(!vis[v]){
            dfs(v);
        }
    }

    stk.push(node);
}

void dfs2(ll node){
    vis[node] = 1;
    for(ll v: radj[node]){
        if(!vis[v]){
            comp[v] = comp[node];
            dfs2(v);
        }
    }
    
}

void dfs3(ll node){

    vis[node] = 1;
    ll mx = 0;
    for(ll v: adjLESS[node]){
        if(!vis[v]){
            dfs3(v);
        }
        mx = max(mx, val[comp[v]]+1);
    }

    for(ll v: adjEQUAL[node]){
        if(!vis[v]){
            dfs3(v);
        }
        mx = max(mx, val[comp[v]]);
    }

    if(mx==0){
        val[comp[node]] = 1;
    } else val[comp[node]] = mx;
}



void solve(){
    ll n, m; cin >> n >> m;

    vis.assign(n+1, 0);
    adjLESS.assign(n+1, vll());
    adjEQUAL.assign(n+1, vll());
    radj.assign(n+1, vll());
    val.assign(n+1, 0);
    comp.assign(n+1, -1);

    ll t, x,y;
    f(i,0,m){
        cin >> t >> x >> y;
        if(t==0){
            adjEQUAL[y].pb(x);
        } else {
            adjLESS[y].pb(x);
        }
        radj[x].pb(y);
    }

    cf(i,1,n){
        if(!vis[i]) dfs(i);
    }

    //cout << "TOPOTIME BABY!!!!\n";
    vis.assign(n+1, 0);
    ll cur = 0;
    while(!stk.empty()){
        
        ll node = stk.top();
        stk.pop();
        //cout << node << " ";
        if(!vis[node]){
            comp[node] = ++cur;
            dfs2(node);
        } 
    }
    //cout << "\n";

    cf(i,1,n){
        for(ll v: adjLESS[i]){
            if(comp[i]==comp[v]){
                cout << "No\n";
                return;
            }
        }
    }

    vis.assign(n+1, 0);
    cf(i,1,n){
        if(val[comp[i]]==0){
            dfs3(i);
        }
    }
    

    cout << "Yes\n";
    cf(i,1,n){
        cout << val[comp[i]] << " ";
    }
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

