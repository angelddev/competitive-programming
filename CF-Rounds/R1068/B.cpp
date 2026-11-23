#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    long long mx=0, mn=0;

    for(int i=0;i<n;i++){
        long long new_mx = max(mx - a[i], b[i] - mn);
        long long new_mn = min(mn - a[i], b[i] - mx);
        mx = new_mx, mn = new_mn;
    }

    cout << mx << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    while(n--)
        solve();
}