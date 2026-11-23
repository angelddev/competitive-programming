#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define endl '\n'
#define pb push_back 
#define F first 
#define S second 
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 

ll n, m, k; 

void solve(){

    ll n, k; cin >> n >> k;

    vll a(n), b(n);
    f(i,0,n) cin >> a[i];
    f(i,0,n) cin >> b[i];

    
    ll ans = 0;
    if(k%2){
        ll best=a[0], cur=a[0], buy = a[0]+b[0];
        ans = max({best, cur, buy});
        f(i,1,n) {
            buy = max({a[i]+b[i], buy+a[i], cur+a[i]+b[i]});
            cur = max(a[i], cur+a[i]);
            best = max({best, cur, buy});
        }
        ans = max({best, cur, buy, ans});
    } else {
        ll best=a[0], cur=a[0];
        f(i,1,n) {
            cur = max(a[i], cur+a[i]);
            best = max(best, cur);
        }
        ans = best;
    }

    cout << ans << "\n";
}

int main(){
    #ifdef DEBUG
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif 

    ll t=1;
    cin>>t; 
    while(t--){
        solve(); 
    }
}