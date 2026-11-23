#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    long long n;
    cin >> n ;

    int sum =0, x;
    for(int i=0; i<n-1; i++){
        cin >> x;
        sum+=(-1*x);
    }

    cout << sum << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while(t--){
        solve();
    }
}