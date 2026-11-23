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

    vll mot(n);
    f(i,0,n){
        cin >> mot[i];
    }

    vvll ranges(n+1, vll(n+1));    
    f(i,0,n){
        map<ll, ll> mp; 
        f(j,i,n){
            pll mnFreq = {INF, INF}, mxFreq = {0, -1};
            mp[mot[j]]++;

            for(auto [val, freq]: mp){
                if(freq>mxFreq.S){
                    mxFreq.S=freq, mxFreq.F=val;
                } else if(mxFreq.S==freq){
                    mxFreq.F=max(val, mxFreq.F);
                }

                if(freq<mnFreq.S){
                    mnFreq.F=val, mnFreq.S=freq;
                } else if(freq==mnFreq.S){
                    mnFreq.F=min(val, mnFreq.F);
                }
            }
            ranges[i][j] = mxFreq.F-mnFreq.F;
        }
    }


    vvll dp(n+1, vll(n+1, -INF));

    // [i] = hasta donde, [1] = tomando k segmentos
    f(i,0,n){
        dp[i][1] = ranges[0][i];
    }

    
    
    // calcular en orden comenznando en i segmento, j representando desde donde, y m representando hasta donde.
    cf(i,2,min(n, k)){
        f(j, i-1, n){
            f(m, j, n){
                dp[m][i]=max({dp[m][i-1], dp[j-1][i-1]+ranges[j][m], dp[m][i]});
            }
        }
    }

    //f(i,0,n){
      //  cout << dp[i][3] << " ";
    //} cout << "\n";

    ll best = -INF;
    cf(i, 1, min(n, k)){
        best = max(best, dp[n-1][i]);
    }

    cout << best << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

