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


void solve(){
 
    ll n, k; cin >> n >> k;

    vll arr(n+1);
    cf(i,1,n){
        cin >> arr[i];
    }

    vll spices(k+1);
    cf(i,1,k){
        cin >> spices[i];
    }

    vll sfx(n+2);    
    rf(i,n,1){
        sfx[i]=sfx[i+1]+arr[i];
    }

    vvll dp(n+1, vll(1<<k, INF));
    dp[0][0] = 0;
    cf(i,1,n){
        cf(msk, 1, (1<<k)-1){
            if(__popcount(msk)>i) continue;
            cf(g, __popcount(msk), i){
                ll temp = msk, cont = 0;
                while(temp>0){
                    if(temp%2){
                        dp[i][msk] = min({dp[i][msk], dp[g-1][msk^(1<<cont)]+(abs(spices[cont+1]-(sfx[g]-sfx[i+1])))*(abs(spices[cont+1]-(sfx[g]-sfx[i+1])))});
                    }
                    temp/=2;
                    cont++;
                }
            }
        }
    }

    
        // cf(msk, 1, (1<<k)-1){
        //     if(__popcount(msk)>1) continue;
        //     cout << msk << " " << dp[1][msk] << "\n";
        // }
    
    cout << dp[n][(1<<k)-1] << "\n";



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

