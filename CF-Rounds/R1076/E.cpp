#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    ll n; cin >> n;
    ll x;
    vector<ll> dp(n+1, 10e9);
    for(ll i=0; i<n; i++){
        cin >> x;
        dp[x]=1;
    }

    for(ll i=1; i<=n;i++){
        if(dp[i]==1){
            continue;
        }
        ll k=sqrt(i);
        for(int j=1; j<=k; j++){
            if(i%j==0){
                dp[i]=min(dp[i], dp[i/j]+dp[j]);
            }
        }
    }

    for(ll i=1; i<=n;i++){
        if(dp[i]>=10e9)
        dp[i]=-1;
    }

    for(int i=1; i<=n; i++){
        cout << dp[i] << " ";
    }

    cout << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
    
    return 0;
}