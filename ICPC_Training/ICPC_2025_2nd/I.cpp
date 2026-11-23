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
    
    ll q; cin >> q;
    vpl queries(q);
    f(i,0,q){
        cin >> queries[i].first;
        cin >> queries[i].second;
    }

    vll fib(50);
    fib[0]=1;
    fib[1]=1;
    f(i,2,50){
        fib[i]=fib[i-1]+fib[i-2];
    }   

    f(i,0,q){
        ll mx=queries[i].first, iterations=1, sum=2;
        while(mx < queries[i].second){ 
            mx=queries[i].first*sum;
            sum+=fib[iterations];
            iterations++;
        }
        ll ans = iterations; 
        cout << ans << "\n";
    }
}

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}