#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    for(int &i: a)
        cin >> i;
    for(int &j: b)
        cin >> j;


    int k, m;
    vector<pair<int, int>> queries(q);
    for(int i=0; i<q; i++){
        cin >> k >> m;
        queries[i].first=k;
        queries[i].second=m;
    } 
    
    int ultmax=0;
    vector<int> c(n);
    for(int i=n-1; i>=0; i--){
        ultmax = max({ultmax, a[i], b[i]});
        c[i]=max(ultmax, a[i]);
    }

    vector<ll> pfx(n);
    pfx[0]=c[0];
    for(int i=1; i<n; i++){
        pfx[i]=pfx[i-1]+c[i];
    }

    for(int i=0; i<q; i++){
        if(queries[i].first==1){
            cout << pfx[queries[i].second-1] << " ";
        } else
        cout << pfx[queries[i].second-1]-pfx[queries[i].first-2] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
    
}