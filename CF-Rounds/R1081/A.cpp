#include<bits/stdc++.h>
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 

ll countdiffs(ll strt, ll end, string word){
    ll diffs=0;
    f(i,strt,end){
        if(word[i]!=word[i+1]){
            diffs++;
        }
    }
    return diffs;
}

void solve(){
    
    ll n; cin >> n;
    string s; cin >> s;
    if(n==1){
        cout << 1 << "\n";
        return;
    }

    ll tot=1;

    s=s+s;

    ll mx=0;
    cf(i,0,n){
        mx=max(countdiffs(i, (i+n)-1, s), mx);
    }

    cout << mx+1 << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}