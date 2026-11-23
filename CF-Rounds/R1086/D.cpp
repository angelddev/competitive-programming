#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 998244353;

vector<string> reachability;
vvl adj;
vll checked;
ll n;
void dfs(ll node){
    checked[node]=1;
    for(ll friends: adj[node]){
        if(checked[friends]==0){
            dfs(friends);
        }
    }
}

void solve(){

    reachability.clear();
    adj.clear();

    cin >> n;
    string s;
    f(i,0,n){
        cin >> s;
        reachability.pb(s);
    }

    //check for relfexibility
    f(i,0,n){
        if(reachability[i][i]=='0'){
            cout << "No\n";
            return;
        }
    }

    //check for no mutual reach
    f(i,0,n){
        f(j,0,n){
            if(i!=j && reachability[i][j]=='1'){
                if(reachability[j][i]=='1'){
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    //check for connectivity
    checked.assign(n,0);
    adj.assign(n, vll());
    f(i,0,n){
        f(j,i+1,n){
            if(reachability[i][j]=='1'||reachability[j][i]=='1'){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    dfs(0);
    f(i,0,n){
        if(checked[i]==0){
            cout << "No\n"; return;
        }
    }

    //check for no diamonds
    
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}