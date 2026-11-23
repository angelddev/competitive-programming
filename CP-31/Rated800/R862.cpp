#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){

    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int sum=0;
    for(int i=0; i<n-1;i++){
        if((arr[i]+arr[i+1])%2==0){
            sum++;
        }
        else continue;
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