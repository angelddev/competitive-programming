#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    vector<ll> f(n+1,0);
    vector<ll> c(n+1,0);

    
    for(ll i=0;i<n;i++){
        cin >> a[i];
        f[a[i]]++;
    }

    for(ll i=1;i<=n;i++){
        if(f[i]%k){
            cout << 0 << endl;
            return;
        }
        f[i]/=k;
    }

    ll l=0,s=0;

    for(ll r=0;r<n;r++){
        c[a[r]]++;
        while(c[a[r]]>f[a[r]]){
            c[a[l]]--;
            l++;}
        s+=(r-l+1);
    }
    cout<<s<<endl;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;cin>>t;
    while(t--)
        solve();

}