#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){

    int n;
    int sum=0;
    cin >> n;
    while(n>10){
        sum+=9;
        n=n/10;
    }
    int last=n%10;
    if(last==0){
        last+=10;
    }
    cout << sum+last<< endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while(t--){
        solve();
    }
}