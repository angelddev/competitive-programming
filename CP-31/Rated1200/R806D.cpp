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

void solve(){
    ll n; cin >> n;

    vector<string> mat(n);
    f(i,0,n)
        cin>>mat[i];

    ll quad=(n+1)/2;
    ll sum=0, s0, s1;
    f(i,0,quad){
        f(j,0,n/2){
            s0=0, s1=0;
            if(mat[i][j]=='1') s1++;
            else {s0++;}
            if(mat[j][n-1-i]=='1')s1++;
            else {s0++;}
            if(mat[n-1-i][n-1-j]=='1')s1++; 
            else {s0++;}
            if(mat[n-1-j][i]=='1')s1++;
            else {s0++;}
            sum+=min(s0,s1);
        }
    }

    cout << sum << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; 
    cin >> t;
    while(t--)
        solve();
        
    return 0;
}