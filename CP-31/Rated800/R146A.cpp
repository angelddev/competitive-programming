#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    long long n, k;
    cin >> n >> k;

    if(n%k==0 || n%2==0 || (k%2&&k<n)){
        cout << "yes" << endl;
        return;
    }
    cout << "no" << endl;
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while(t--){
        solve();
    }
}