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

bool comp(pll a, pll b){
    if(a.F>b.F){
        return true;
    }
    if(a.F<b.F) return false;

    if(a.S < b.S) return true;
    return false;
}

void solve(){
 
    ll n, m , h; cin >> n >> m >> h;

    pll rudolf;
    vpl ans;
    f(i,0,n){
        vll temp;
        ll x;
        f(j,0,m){
            cin >> x;
            temp.pb(x);
        }

        sort(all(temp));
        ll cur = 0, solved = 0, penalty = 0;

        f(j,0,temp.size()){
            if((cur+temp[j])>h) break;
            cur+=temp[j];
            penalty+=cur;
            solved++;
        }
        if(i==0) rudolf = {solved, penalty};
        ans.pb({solved, penalty});
    }

    sort(all(ans), comp);

    // for(pll el : ans){
    //     cout << el.F << " " << el.S << "\n";
    // }

    ll pos;
    f(i,0,n){
        if(ans[i]==rudolf){
            cout << i+1 << "\n";
            break;
        }
    }
    //cout << (prev(upper_bound(all(ans), rudolf, comp)))-ans.begin() << "\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

