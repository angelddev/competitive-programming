#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define endl '\n'
#define pb push_back 
#define F first 
#define S second 
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 

ll n, m, k, l; 
ll dis[10004]; 
string s;

ll manhattan(vll &a, vll &b){
    ll ans = 0; 
    f(i, 0, l){
        ans+=abs(a[i]-b[i]); 
    }
    return ans; 
}

void solve(){ 
    cin>>n>>l>>k; 
    vector<pair<string, vll>> pr; 

    f(i, 0, n){
        cin>>s;
        vll v(0); 
        f(j, 0, l){
            ll a;
            cin>>a; 
            v.pb(a); 
        }
        pr.pb({s, v}); 
    }

    vector<string> ans; 
    ll mx = 0, idx;
    f(i, 0, n){
        if(manhattan(pr[0].S, pr[i].S) > mx){
            mx = manhattan(pr[0].S, pr[i].S); 
            idx = i; 
        }
    }
    ans.pb(pr[idx].F); 
    f(i, 0, n){
        dis[i] = manhattan(pr[idx].S, pr[i].S);
    }
    f(x, 1, k){
        ll mx = 0, idx;
        f(i, 0, n){
            if(dis[i] > mx){
                mx = dis[i]; 
                idx = i; 
            }
        }
        ans.pb(pr[idx].F); 
        f(i, 0, n){
            dis[i] = min(dis[i], manhattan(pr[idx].S, pr[i].S));
        }
    }
    for(auto s: ans) cout<<s<<"\n";



}

int main(){
    #ifdef DEBUG
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif 

    ll t=1;
    // cin>>t; 
    while(t--){
        solve(); 
    }
}