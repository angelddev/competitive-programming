#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

void solve(){

    ll n; cin >> n;
    vector<long long> a(n);

    for(ll &i :a ){
        cin >> i;
    }

    ll curr=a[0], mx=a[0];
    for(ll j=1; j<n; j++){
        if(curr<0){
            curr=0;
        }
        curr+=a[j];
        mx=max(curr, mx);
    }

    cout << mx << endl;
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}