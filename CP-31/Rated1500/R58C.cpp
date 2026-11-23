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

    ll n;
    cin >> n;
    
    vector<pair<pll, ll>> rg(n);
    f(i,0,n){
        cin >> rg[i].F.F >> rg[i].F.S;
        rg[i].S=i;
    }

    sort(all(rg));

    vll ans(n, -1);
    ll end = rg[0].F.S;
    ans[rg[0].S]=1;

    f(i,1,n){
        if(rg[i].F.F<=end){
            end=max(end, rg[i].F.S);
            ans[rg[i].S]=1;
        } else {
            f(j, i, n){
                ans[rg[j].S]=2;
            }
            break;
        }
    }

    ll cont=1;
    for(ll num : ans){
        if(num==2){
            cont=2;
        }
    }

    if(cont==1){
        cout << "-1\n";
        return;
    }


    for(ll num : ans){
        cout << num << " ";
    } cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}