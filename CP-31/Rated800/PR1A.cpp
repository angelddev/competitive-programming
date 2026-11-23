#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){

    int n, a,b; cin >> n >> a >> b;
    if((a==b&&a==n)||n-(b+a)>=2){
        cout << "yes" << endl;
    }
    else cout << "no" << endl;


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while(t--){
        solve();
    }
}