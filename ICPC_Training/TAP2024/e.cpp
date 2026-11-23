#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define rf(i,s,e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define pb push_back
#define F first
#define S second
#define endl '\n'
using namespace std; 

const ll MOD = 1e9+7, INF = 1e18;

ll n, m, k; 

void solve(){
    ll A, s, l, r;
    cin>>A>>s>>l>>r; 
    ll tot=0; 
    cf(k, 2, r-l+1){
        if(2*s % k != 0) continue; 
        ll st; 
        cf(a, 0, k-1){
            ll b = k-a-1; 
            if((b-a)!=0 && (2*s - 2*k*A)/k % (b-a) == 0){
                ll d = ((2*s - 2*k*A)/k)/(b-a); 
                if(d>= 0 && A-a*d >=l && A+b*d <=r){
                    cout<<d<<" "<<a<<" "<<b<<"\n";
                    tot++; 
                }
            }
        }
    }
    if(s == A) tot++; 
    cout<<tot<<"\n"; 
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