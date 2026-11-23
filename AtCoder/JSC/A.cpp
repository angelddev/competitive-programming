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


bool sorty(pll a, pll b) {
    if (a.first != b.first) {
        return a.first < b.first; 
    }
    return a.second > b.second;   
}

void solve(){


    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll n, m; cin >> n >> m;
    cf(i,1,n){
        pq.push(i);
    }

    vector<pll> intervals;
    f(i,0,m){
        pll p;
        cin >> p.F >> p.S;
        intervals.pb(p);
    }

    sort(all(intervals), sorty);

    int lbound=0, rbound=0;
    vll ans(n+1);
    for(auto ints : intervals){
        ll l = ints.F, r = ints.S;
        if(r<rbound){
            continue;
        }
        while(lbound<l){
            pq.push(ans[lbound]);
            lbound++;
        }
        while(rbound<=r){
            ll num = pq.top();
            pq.pop();
            ans[rbound]=num;
            rbound++;
        }
    }

    cf(i,1,n){
        if(ans[i]==0) cout << 1 << " ";
        else cout << ans[i] << " ";
    } cout << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}