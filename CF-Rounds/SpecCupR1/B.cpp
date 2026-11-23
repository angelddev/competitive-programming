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

void solve(){

    ll n, m; cin >> n >> m;

    ll x;
    deque<ll> odds, evens;
    ll ans=0;
    cf(i,1,n){
        cin >> x;
        if(i%2) odds.pb(x); 
        else evens.pb(x);
        ans+=x;
    }
    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());

    vll parities;
    f(i,0,m){
        cin >> x;
        if(x%2) parities.pb(1);
        else parities.pb(0);
    }

    bool forcedodd = false, forcedeven = false;

    f(i,0,m){
        if(parities[i]){
            if(!odds.empty()){
                if(!forcedodd){
                    ans -= odds.front();
                    odds.pop_front();
                    forcedodd = true;
                } 
                else if(odds.front() > 0){
                    ans -= odds.front();
                    odds.pop_front();
                }
            }
        }
        else{
            if(!evens.empty()){
                if(!forcedeven){
                    ans -= evens.front();
                    evens.pop_front();
                    forcedeven = true;
                }
                else if(evens.front() > 0){
                    ans -= evens.front();
                    evens.pop_front();
                }
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    while(t--){
        solve(); 
    }
}