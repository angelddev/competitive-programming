#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){

    int n ,m , h;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> copy=a;
    int index, sum;
    for(int j=0; j<m; j++){
        cin >> index;
        cin >> sum;
        a[index-1]+=sum;
        if(a[index-1]>h){
            a=copy;
        }
    }

    for(int x : a){
        cout << x  << " ";
    }
    cout << endl;
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }
}