#include <bits/stdc++.h>
using namespace std;

void solve(){

    long long n, k; cin >> n >> k;

    vector<long long> o(n);

    for(int i=0; i<n;i++){
        cin >> o[i];
    }

    sort(o.begin(), o.end());

    vector<long long> pfx(n);
    pfx[0]=o[0];

    for(int i=1; i<n; i++){
        pfx[i]=pfx[i-1]+o[i];
    }

    long long pt1=n-k-1, pt2=1;


    long long mx=pfx[pt1];
    for(int i=0; i<k; i++){
        mx=max(mx, pfx[pt1+1]-pfx[pt2]);
        pt1++;
        pt2+=2;
    }

    cout << mx << endl;
}

    


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}