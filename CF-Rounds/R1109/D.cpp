#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
#define all(a) begin(a), end(a)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define F first
#define S second
#define pb push_back
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 +7;
const int LOG = 30;

void solve(){
    ll n, m; cin >> n >> m;
    vll mot(n);
    f(i,0,n){
        cin >> mot[i];
    }

    vll pts(m);
    f(i,0,m){
        cin >> pts[i];
        pts[i]--;
    }
    sort(all(pts));

    vll pfx(n);
    pfx[0]=mot[0];
    f(i,1,n){
        pfx[i]=pfx[i-1]+mot[i];
    }

    ll cur=1;
    vll flip(n, 0);
    for(ll i=m-1; i>=0; i--){
        ll idx=pts[i];
        ll idx2;
        if(i==0){
            idx2=-1;
        } else idx2=pts[i-1];

        ll rest;
        if(idx2==-1){
            rest = 0;
        } else rest = pfx[idx2];
        ll sum=pfx[idx]-rest;

        if(sum*cur<0){
            cur=-cur;
            flip[idx]^=1; 
        }
    }

    ll cf=0;
    for(ll i=n-1; i>=0; i--){
        cf^=flip[i];
        if(cf){
            mot[i]=-mot[i];
        }
    }

    ll sm = 0;
    f(i,0,n){
        sm+=mot[i];
    }
    cout << sm << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}