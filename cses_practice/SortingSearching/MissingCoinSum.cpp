#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){

    ll n; cin >> n;
    vector<ll> a(n);

    for(ll &i: a){
        cin >> i;
    }

    sort(a.begin(), a.end());
    ll cnt=0;
    for(int i=0; i<n; i++){
        if(cnt+1<a[i])
        break;
        cnt+=a[i];
    }    
    cout << cnt+1 << endl;


}

int main(){
    ios::sync_with_stdio();
    cin.tie();

    solve();
}