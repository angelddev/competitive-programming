#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vpl vector<pll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define F first
#define S second
#define pb push_back
using namespace std; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll dis, t;
    ll n; 
    cin>>n;
    vpl nac;
    f(i, 0, n){
        cin>>dis>>t; 
        if(t >= abs(dis)) nac.pb({t, dis}); 
    }
    sort(nac.begin(), nac.end()); 

    n=nac.size(); 
    vector<ll> dp(n+1,1);

    f(i, 0, n){
        for(ll j=i-1; j>=0; j--){
            if(abs(nac[i].S - nac[j].S) <= abs(nac[i].F - nac[j].F)) dp[i]=max(dp[i], dp[j]+1);
        }    
    }

    ll ans=0;
    f(i, 0, n){
        ans=max(ans, dp[i]);
    }
    cout<<ans<<"\n"; 
}