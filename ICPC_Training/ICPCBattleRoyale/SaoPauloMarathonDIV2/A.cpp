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

    vll diffs(n, -1);
    vpl club(n);

    vpl starts;
    f(i,0,n){
        cin >> club[i].F >> club[i].S;
        if(starts.empty()||club[i].F!=starts.back().F){
            starts.pb({club[i].F, i});
        }
    }


    for(ll i = n-1; i>=1; i--){
        if(club[i].S==club[i-1].S){
            diffs[i-1]=diffs[i];
        } else diffs[i-1]=i;
    }
    
    ll price, MID;
    f(i,0,m){
        cin >> price >> MID;

        ll l=0, r=n-1, pos=-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(club[mid].F<=price){
                pos=mid;
                r =mid-1;
            } else {
                l=mid+1;
            }
        }
        
        if(pos==-1){
            cout << "-1\n";
            continue;
        }
        
        if(club[pos].S==MID){
            ll nxt=diffs[pos];
            if(nxt==-1) cout << "-1\n";
            else cout << nxt+1 << "\n";
        } else cout << pos+1 << "\n";
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}