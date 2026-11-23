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
 
    

    map<ll, ll> nums;
    ll x, n; cin >> n;
    f(i,0,n){
        cin >> x;
        nums[x]++;
    }

    ll ans = 0;
    deque<ll> dq;
    vpl temp;
    for(pll el : nums){
        if(el.S>=2){
            ans+=2;
        } else ans++;
        temp.pb({el.F, el.S});
    }

    sort(temp.rbegin(), temp.rend());
    f(i,0,temp.size()){
        temp[i].S--;
        dq.push_front(temp[i].F);
        while(temp[i].S){
            temp[i].S--;
            dq.push_back(temp[i].F);
        }
    }

    cout << ans << "\n";
    for(ll el : dq){
        cout << el << " ";
    } cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

