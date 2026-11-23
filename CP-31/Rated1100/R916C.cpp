#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){

    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    vector<int> pfx(n);
    pfx[0]=a[0];
    for(int i=1; i<n;i++){
        pfx[i]=pfx[i-1]+a[i];
    }

    int top=min(k, n);
    int mx=0, mxb=b[0];
    for(int i=0; i<top; i++){
        mxb=max(b[i], mxb);
        mx=max(mx, pfx[i]+mxb*(k-(i+1)));
    }

    cout << mx << endl;
}


int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    int n; cin >> n;
    while(n--){
        solve();
    }
}