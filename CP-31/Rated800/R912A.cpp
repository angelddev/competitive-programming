#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

void solve(){

    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for(int i= 0; i<n; i++){
        cin >> arr[i];
    }

    if(k>=2){
        cout << "yes" << endl;
        return;
    }
    vector<int> dog = arr;
    sort(dog.begin(), dog.end());
    if(arr==dog){
        cout << "yes" << endl;
    }
    else cout << "no" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while(t--){
        solve();
    }
}