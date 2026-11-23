#include <bits/stdc++.h>

#define ll long long 
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
 
    ll n, m, q; cin >> n >> m >> q;
    vector<set<ll>> cols(m+1), rows(n+1);
    
    cf(i,1,n){
        cf(j,1,m){
            rows[i].insert(j);
        }
    }

    cf(j,1,m){
        cf(i,1,n){
            cols[j].insert(i);
        }
    }

    ll x, y;
    f(i,0,q){
        cin >> x >> y;

        if(rows[x].count(y)&&cols[y].count(x)){
            rows[x].erase(y); cols[y].erase(x);
            continue;
        }

        auto leftROW = rows[x].lower_bound(y);
        auto rightROW = rows[x].upper_bound(y);
        auto leftCOL = cols[y].lower_bound(x);
        auto rightCOL = cols[y].upper_bound(x); 

        if(leftROW==rows[x].begin()){

        } else {
            if(rows[x].size()==0) continue;
            ll val = *prev(leftROW);
            rows[x].erase(val);
            cols[val].erase(x);
        }

        if(leftCOL==cols[y].begin()){

        } else {
            if(cols[y].size()==0) continue;
            ll val = *prev(leftCOL);
            cols[y].erase(val);
            rows[val].erase(y);
        }

        if(rightROW==rows[x].end()){

        } else {
            ll val = *rightROW;
            rows[x].erase(val);
            cols[val].erase(x);
        }

        if(rightCOL==cols[y].end()){

        } else {
            ll val = *rightCOL;
            cols[y].erase(val);
            rows[val].erase(y);
        }
    }


    ll ans = 0;

    cf(i,1,n){
        for(ll val : rows[i]){
            ans++;
        }
    }

   

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

