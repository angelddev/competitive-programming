#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){   
    
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll &i: a){
        cin >> i;
    }

    ll mx=0;
    for(int i=0; i<n; i++){
        mx=max(mx, a[i]);
        if(i%2==1)
            a[i]=mx;
    }

    ll mn=0, sum=0;
    for(int i=2; i<n-1; i++){
        if(i%2==0){
            mn=min(a[i-1], a[i+1]);
            if(a[i]>=mn)
            sum+=(a[i]-mn)+1;
        }
    }

    if(a[0]>=a[1])
        sum+=(a[0]-a[1])+1;
    if(n%2==1&&a[n-1]>=a[n-2])
        sum+=(a[n-1]-a[n-2])+1;

    cout << sum << endl;
}


int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        solve();
    }
}

