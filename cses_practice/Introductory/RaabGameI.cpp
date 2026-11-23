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
 
    ll n, a, b; cin >> n >> a >> b;
    if((a==0||b==0)){
        if (a>0||b>0){
        cout << "NO\n"; return;}
    }

    ll ties = n-(a+b); 
    n = n-ties;
    if(ties<0) { cout << "NO\n"; return; }
    vpl ans;

    vll vis1(n+1), vis2(n+1);
    rf(i, n, (n-a)+1){
        if(i-b<1||vis1[i]||vis2[i-b]){
            cout << "NO\n"; return; 
        }

        vis2[i-b] = 1;
        vis1[i] = 1;
        ans.pb({i, i-b});
    }

    rf(i, n, (n-b)+1){
        if(i-a<1||vis1[i-a]||vis2[i]){
            cout << "NO\n"; return; 
        }

        vis1[i-a] = 1;
        vis2[i] = 1;
        ans.pb({i-a, i});
    }

    cf(i,n+1,n+ties){
        ans.pb({i, i});
    }

    

    if(ans.size()!=n+ties){
        cout << "NO\n"; return; 
    }

    cout << "YES\n";
    f(i,0,n+ties){
        cout << ans[i].F << " ";
    } cout << "\n";

    f(i,0,n+ties){
        cout << ans[i].S << " ";
    } cout << "\n";




}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

