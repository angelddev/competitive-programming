#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define vll vector<ll>

void solve(){

    ll n, m, k;

    cin >> n >> m >> k;
    
    ll amount= n*m;
    
    ll ans=0;
    if(amount%k==0){
        ans=amount/k;
    } else ans=amount/k+1;

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
