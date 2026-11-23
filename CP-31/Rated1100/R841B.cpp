#include <bits/stdc++.h>
using namespace std;
#define enld '\n'
typedef long long ll;

void solve(){

    ll n; cin >> n;
    ll sum=0;
    for(ll i=1; i<n; i++){
        sum+=i*i;
        sum+=i*(i+1);
    }

    sum+=n*n;

    cout << ((2022*sum)%((ll)10e9+7)) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}