#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


void solve(){

    long long k; cin >> k;

    long long ans=0;
    for(long long i=0; i*4<=k; i++){
        if((k-(i*4))%2==0){
            ans++;
        }
    }

    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while(n--)
        solve();
}