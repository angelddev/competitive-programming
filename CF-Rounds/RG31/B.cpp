#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<string> a(n);
    vector<char> b;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    string sol = a[0], front=a[0];
    int cont=1;

    for (string &x : a){
        if(cont==1){
            cont++;
            continue;
        }

        if (x + sol < sol + x)
            sol = x + sol;
        else
            sol = sol + x;
    }
        
    cout << sol << endl;
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