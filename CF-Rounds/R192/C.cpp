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

    vll nums(n);
    f(i,0,n){
        cin >> nums[i];
    }

    vll szs;
    ll len=1;
    f(i, 1, n) {
        if (nums[i]==nums[i-1]) len++;
        else {
            szs.pb(len);
            len=1;
        }
    }
    szs.pb(len);

    sort(all(szs));
    vll uni;
    f(i, 0, szs.size()) {
        if (i==0||szs[i]!=szs[i-1]) {
            uni.pb(szs[i]);
        }
    }
    ll sz=szs.size();
    vll suff(sz+1,0);
    rf(i,sz-1,0) {
        suff[i]=suff[i+1]+szs[i];
    }

    ll ans=0;

    for(ll u:uni){
        auto it=lower_bound(all(szs), u);
        ll idx=distance(begin(szs), it);

        ll cnt=sz-idx;
        ll sum=suff[idx];

        if (cnt>0) {
            if ((m-sum)%cnt==0) {
                ll x =(m-sum)/cnt;
                if (x+u-1>=0) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}