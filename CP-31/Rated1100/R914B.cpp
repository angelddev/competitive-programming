#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
typedef long long ll;

void solve(){

    ll n; cin >> n;
    vector<pair<ll,ll>> b(n);
    for(int i=0; i<n; i++){
        cin >> b[i].first;
        b[i].second=i;
    }
    sort(b.begin(), b.end());
    
    vector<ll> pfx(n);
    pfx[0]=b[0].first;

    for(int i=1;i<n; i++){
        pfx[i]=pfx[i-1]+b[i].first;
    }

    vector<pair<ll, ll>> c(n);
    c[n-1].second=n-1;
    c[n-1].first=b[n-1].second;
    for(int i=n-2; i>=0; i--){
        c[i].first=b[i].second;
        if(pfx[i]>=b[i+1].first){
            c[i].second=c[i+1].second;
        } else c[i].second=i;
    }

    sort(c.begin(), c.end());
    for(int i=0; i<n; i++){
        cout << c[i].second << " ";
    }
    cout << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    int t; cin >> t;
    while(t--){
        solve();
    }


}