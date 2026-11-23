#include <bits/stdc++.h>

#define ll long long 
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
 
    ll n, k; cin >> n >> k;
    
    vll arr(n+2);
    cf(i,1,n){
        cin >> arr[i];
    }

    vll left(n+2, 0);  
    cf(i,1,n) left[i]=left[i-1]+arr[i];

    ll l=1, r=n;
    ll score=0;

    ll tot = n-k+1;      
    ll M = min(k-1, tot); 
    ll flag = 0;

    cf(s, 1, M){
        score += max(arr[l], arr[r]);
        l++; r--;
    }

    if(M==k-1 && tot>M){
        flag = 1;
        score += left[r]-left[l-1];
    }

    cout << score << "\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

