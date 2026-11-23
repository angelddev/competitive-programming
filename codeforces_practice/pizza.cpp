#include <bits/stdc++.h>
using namespace std;

void solve(){

    int k;
    cin >> k;

    vector<int> arr(2, 0);
    
    do{
        arr[0]++;
        arr[1]+=2;
    }while(arr[1]<k);

    cout << arr[0]-1 << "\n";
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        solve();
    }

}