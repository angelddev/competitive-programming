#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){

    int k;
    cin >> k;

    if(k<=3){
        cout << k << endl;
        return;
    }
    if(k%2==1){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;


    while(n--)
        solve();
}