#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
   
    int k;

    cin >> k;
    vector<int> arr(k);
    int x;
    for(int i=0; i<k;i++){
        cin >> x;
        arr[i]=x;
    }

    sort(arr.begin(), arr.end());

    if(arr[1]-arr[0]>=arr[0])
    {
        cout << arr[1]-arr[0] << endl;
    }
    else cout << arr[0] << endl;
    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}