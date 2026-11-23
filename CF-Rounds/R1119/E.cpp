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
    ll n; cin >> n;

    vll arr(n);
    f(i,0,n){
        cin >> arr[i];
    }

    vpl ranges;
    vpl forced;
    f(i,0,n){
        if(arr[i]>0){
            ranges.pb({max(0LL, i-(arr[i]-1)), min(n-1, i+(arr[i]-1))});
        }
        if(arr[i]!=-1) {
            forced.pb({i+(arr[i]), i-(arr[i])});
        }
    }

    sort(all(ranges));

    vpl restricted;
    if(ranges.size() > 0){
        ll l = ranges[0].F;
        ll r = ranges[0].S;
        f(i, 1, ranges.size()){
            if(ranges[i].F <= r){
                r = max(r, ranges[i].S);
            } else {
                restricted.pb({l, r});
                l = ranges[i].F;
                r = ranges[i].S;
            }
        }
        restricted.pb({l, r});
    }

    ll flag = 1;
    for(pll forc : forced){
        ll p1 = forc.F;
        ll p2 = forc.S;
        ll c1 = 0;
        ll c2 = 0;

        if(p1 < 0||p1>=n) c1 =1;
        else {
            auto it = upper_bound(all(restricted), make_pair(p1, INF));
            if(it!=restricted.begin()){
                it--;
                if(it->F <= p1 && p1 <= it->S) c1 = 1;
            }
        }

        if(p2 < 0 || p2 >= n) c2 = 1;
        else {
            auto it = upper_bound(all(restricted), make_pair(p2, INF));
            if(it!=restricted.begin()){
                it--;
                if(it->F <= p2&&p2<=it->S) c2 = 1;
            }
        }

        if(c1 && c2){
            flag=0;
            break;
        }
    }

    if(!flag){
        cout << -1 << "\n";
        return;
    }

    string ans(n, '1');
    for(pll r : restricted){
        cf(i, r.F, r.S){
            ans[i] = '0';
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}