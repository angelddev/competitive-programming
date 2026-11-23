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
const ll MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    vll a(n), b(n);
    f(i, 0, n) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(all(b));
    ll m=b[n/2]; 

    vll prl(n+1, 0), prg(n+1, 0);

    f(i, 0, n) {
        if(a[i]<m)  
            prl[i+1]=prl[i]+1;
        else prl[i+1]=prl[i];
        if(a[i]>m)  
            prg[i+1]=prg[i]+1;
        else prg[i+1]=prg[i];
    }

    vll dp(n+1, -INF);
    dp[0] = 0;

    ll len, ls, gr;
    f(l, 0, n) {
        if (dp[l]<=-INF) continue;

        for (ll r=l+1;r<=n; r+=2) {
            len = r-l;

            ls=prl[r]-prl[l];
            gr=prg[r]-prg[l];

            if (ls <= len/2 && gr <=len/2) {
                dp[r] = max(dp[r], dp[l] + 1);
            }
        }
    }

    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while (t--) solve();
}