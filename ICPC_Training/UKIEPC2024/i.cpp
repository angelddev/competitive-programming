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
    cin>>n>>m; 
    ll m2=m; 
    ll tot = n; 
    f(i, 0, n-1){
        cout<<"1 1 "<<m2/tot - 1<<" "<<m2/tot<<"\n"; 
        m2-=m2/tot; tot--; 
    }
    bool extra = 0;
    if((m-n+1) % m2 == 0) extra=1; 
    cout<<(m-n+m2)/(m2) +extra<<" "<<m-n+1<<" "<<1<<" "<<m2<<"\n"; 
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
    // cin>>t; 
    while(t--){
        solve(); 
    }
}