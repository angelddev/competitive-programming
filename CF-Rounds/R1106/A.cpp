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
    ll n, c;
    cin >> n >> c;

    vll a(n), b(n);
    f(i,0,n){
        cin >> a[i];
    }
    f(i,0,n){
        cin >> b[i];
    }
    ll sum2=0;

    f(i,0,n){
        if(a[i]<b[i]){
            sum2=-1;
            break;
        }
        sum2+=a[i]-b[i];
    }


    sort(all(a));
    sort(all(b));

    ll sum=c;
    f(i,0,n){
        if(a[i]<b[i]) {
            cout << "-1\n";
            return;
        }
        sum+=a[i]-b[i];
    }

    if(sum2==-1){
        cout << sum << "\n";
    } else cout << min(sum2, sum) << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}