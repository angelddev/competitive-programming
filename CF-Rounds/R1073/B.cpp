#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){

    int t; cin >> t;
    vector<int> arr(t);

    for(int i=0; i<t; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    if(arr[0]>0){
        cout << "NO" << endl;
        return;
    }

    if(count(arr.begin(), arr.end(), 0)>1&&count(arr.begin(), arr.end(), 1)<1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    
}

int main(){
    ios::sync_with_stdio();
    cin.tie();

    int n; cin >> n;
    while(n--)
        solve();
}