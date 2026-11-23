#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 998244353;

void solve(){
    
    ll n, k; cin >> n >> k;

    vll a(n), b(n);
    f(i,0,n){
        cin >> a[i];
    }
    f(i,0,n){
        cin >> b[i];
    }

    ll fst=n-k;
    f(i,0,fst){
        if(b[i]!=-1&&a[i]!=b[i]){
            cout << "NO\n";
            return;
        }
    }
    f(i,k, n){
        if(b[i]!=-1&&a[i]!=b[i]){
            cout << "NO\n";
            return;
        }
    }

    vll seen(n+1, 0);
    f(i,fst, k){
        seen[a[i]]=1;
    }

    f(i,fst,k){
        if(b[i]!=-1&&seen[b[i]]==0){
            cout << "NO\n";
            return;
        } if(b[i]!=-1)seen[b[i]]=0;
    }

    cout << "YES\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}