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
#define ld long double
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 
const ld eps = 1e-9;

ll n, m, k; 
ld p, y, r;

ld fun(ld e){
    ld w = e-p;   
    ld n = (y + r - (ld)2*e + p)/(ld)2;  
    ld s = (y - r - (ld)2*e + p)/(ld)2;
    return max({abs(w),abs(n),abs(s), abs(e)}); 
}

void solve(){
    cin>>p>>r>>y;
    ld left = -10, right = 10; 
    ll cnt = 0;
    while(right-left > eps){
        //cout<<left<<" "<<right<<" "<<right-left<<"\n"; 
        ld m1 = left + (right-left)/(ld)3, m2 = right - (right-left)/(ld)3; 
        if(fun(m1) < fun(m2)) right = m2; 
        else left = m1; 
        cnt++;
    }
    ld e = left; 

    ld w = e-p;   
    ld n = (y + r - (ld)2*e + p)/(ld)2;  
    ld s = (y - r - (ld)2*e + p)/(ld)2;

    cout<<fixed<<setprecision(12)<<n<<" "<<e<<" "<<s<<" "<<w<<"\n"; 
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