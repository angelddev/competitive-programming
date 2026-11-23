#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve(){

     int l, a, b, mx, current;
    cin >> l >> a >> b;

    mx=a;
    for(int i=1; i<l; i++){
        current = (a+i*b)%l;
        if(current>mx){
            mx=current;
        }
        if(current==a){
            break;
        }
    }

    cout << mx;
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