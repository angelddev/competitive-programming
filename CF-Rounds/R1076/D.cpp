#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    int n; cin >> n; 

    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    vector<ll> pfx(n);
    pfx[0]=b[0]; 
    for(int i=1; i<n;i++)
        pfx[i]=pfx[i-1]+b[i];

    sort(a.begin(),a.end());

    ll mx =0;
    for(int i=0;i<n; i++){
        ll needed= pfx[i];

        if(needed> n) break;
        ll currx= a[n- needed];
        mx =max(mx,currx*(i+1));
    }

    cout << mx<< endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
    
    return 0;
}