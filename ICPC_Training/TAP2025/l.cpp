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

void solve(){

    ll n,c;
    cin >> n >> c;

    vll ter(n+1);
    f(i,0,n){
        cin >> ter[i];
    }
    vll pfx(n+1);
    pfx[0]=ter[0];
    f(i,1,n){
        pfx[i]=pfx[i-1]+ter[i];
    }


    ll lim=1, cont=1;

    while(true){
        if(lim+cont+1>n) break;
        cont++;
        lim+=cont;
    }
    lim=cont;
    //cout << cont << " LIM\n";
    vvll dp(lim+30, vll(n+1));

    dp[1][0]=c-ter[0];
    f(i,1,n){
        dp[1][i]=max(c-ter[i], dp[1][i-1]);
    }
    // f(i,0,n){
    //     cout << dp[1][i] << " P" << i << " "; 
    // }

    ll strt = 2;
    cf(i,2,lim){
        for(ll j = strt ; j<n; j++){
            //cout << "TOMA " << i << " " << j << "\n";
            ll toEl = pfx[j]-pfx[(j-i)];
            //cout << toEl << "\n";
            dp[i][j]=max({dp[i-1][j], (c-toEl)+dp[i-1][(j-i)], dp[i][j-1]});
            //cout << dp[i][j] << "\n";
        }
        strt+=i+1;
    }
    cout << dp[lim][n-1] << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}