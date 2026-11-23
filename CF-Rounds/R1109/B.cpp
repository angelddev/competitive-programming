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
const ll MOD = 1e9 +7;
const int LOG = 30;

void solve(){
    ll n; cin >> n;
    vll st(n+1);
    f(i,0,n){
        cin >> st[i];
    }

    if(n==1){
        cout << "YES\n";
        return;
    }

    
    ll rest = 0;
        rest = st[0]-1;
        st[0]=1;
        
        st[1]+=rest;    
    f(i,1,n){
        if(st[i]<=st[i-1]){
            cout << "NO\n";
                return;
        }
        if(st[i]<i+1){
            cout << "NO\n";
            return;
        }
        rest = st[i]-(i+1);
        st[i]=i+1;
        st[i+1]+=rest; 
    }

    cout << "YES\n";


    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}