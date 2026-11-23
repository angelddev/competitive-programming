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
 

void solve(){
    
    ll n; cin >> n;

    if(n%4==3){
        cout << "YES" << "\n";
        cout << n/2+1 << "\n";
        cout << 1 << " " << 2 << " ";
        for(int i=4; i<=n; i+=3){
            cout << i << " ";
            if(i==n)
            break;
            if(i!=4)
            cout << ++i << " ";
        }
        cout << "\n";
        cout << n/2 << "\n";
        cout << 3 << " ";
        for(int i=5; i<n; i+=3){
            cout << i << " ";
            cout << ++i << " ";
        }
        return;
    }


    if(n%4==0){
        cout << "YES" << "\n";
        cout << n/2 << "\n";
        for(int i=1; i<=n; i+=3){
            cout << i << " ";
            if(i!=1&&i!=n)
            cout << ++i << " ";
        }
        cout << "\n";
        cout << n/2 << "\n";
        for(int i=2; i<n; i+=3){
            cout << i << " " << ++i << " ";
        }
        return;
    }

    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    solve();
}