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

    ll n; cin >> n;

    vll bitss;

    while(n>0){
        bitss.pb(n%2);
        n/=2;
    }

    reverse(all(bitss));
    while(!bitss.empty()&&bitss.back()==0){
        bitss.pop_back();
    }

    ll l = 0, r = bitss.size()-1, mid = -1;    
    while(l<=r){
        if(l==r) mid = bitss[l];
        if(bitss[l]!=bitss[r]||mid == 1){
            cout << "NO\n";
            return;
        }
        l++, r--;
    }
    cout << "YES\n";
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