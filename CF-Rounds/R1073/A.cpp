#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){

    int t; cin >> t;
    vector<pair<int, int>> arr(t);
    for(int i=0; i<t; i++){
        cin >> arr[i].first;
        arr[i].second=i%2;
    }


    vector<pair<int, int>> copy=arr;
    sort(copy.begin(), copy.end());

    for(int i=0; i<t-1; i++){
        if(copy[i].second+copy[i+1].second==2||copy[i].second+copy[i+1].second==0){
            cout << "NO" << endl;
            return;
        }
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