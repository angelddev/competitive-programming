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

const ll INF = 1e9;
const ll MOD = 1e9 +7;

ll t, n, m, k, a[1000006], b; 

void solve(){
    cin>>n; 
    f(i, 0, n){
        cin>>a[i]; 
    }
    ll l=0, r=n-1; 
    ll sl=a[0], sr=a[n-1];
    ll ans=0;
    while(l<r){
        if(sl == sr){
            l++; sl+=a[l];
            r--; sr+=a[r];
        }
        else if(sl < sr){
            l++;
            sl+=a[l];
            ans++;
        }
        else{
            r--; 
            sr+=a[r]; 
            ans++;
        }
    }
    cout<<ans<<"\n"; 

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    t=1; 
    while(t--){
        solve(); 
    }
}