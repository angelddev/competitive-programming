#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n; cin >> n;
    vector<long long> arr(n);
    long long negatives=0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]<0)
            negatives++;
    }

    vector<long long>pfx(n);
    sort(arr.begin(), arr.end());

    for(int i=0;i<n;i++){
        if(arr[i]<0)
            arr[i]=arr[i]*-1;
        else break;
    }

    sort(arr.begin(), arr.end());

    pfx[0]=arr[0];
    for(int i=1; i<n;i++){
        pfx[i]=arr[i]+pfx[i-1];
    }

    if(count(arr.begin(), arr.end(), 0)>=1||negatives%2==0){
        cout << pfx[n-1] << endl;
    }

    else cout << pfx[n-1]-pfx[0]*2 << endl;
}

    


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}