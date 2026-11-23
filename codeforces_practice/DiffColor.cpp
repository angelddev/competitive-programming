#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



void solve(){

    int k;
    cin >> k;

    vector<int> arr;

    int x, p=k;
    while(p--){
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int ls=arr[0], diff=1;
    for(int j=0; j<k; j++){
        if(ls!=arr[j]){
            diff++;
            ls=arr[j];
        }
    }

    if(diff==1){
        cout << arr[0] << endl;
        return;
    }

    int i;
    for(i=0; i<k; i++){
        if(arr[i]>=diff)
            break;
    }

    cout << arr[i] << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--){
        solve();
    }
}