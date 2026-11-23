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
const int LOG = 19;
vvll up;

void solve(){

    ll n, q; cin >> n >> q;
    up.assign(n+1, vll(LOG+1));
    ll x;

    cf(i,0,LOG){
        up[0][i]=0;
    }

    cf(i,2,n){
        cin >> x;
        up[i][0]=x;
    }

    cf(i,1,n){
        f(j,1,LOG){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }

    ll y;
    f(i,0,q){
        cin >> x >> y;
        f(j, 0, LOG){
            if(y & (1<<j)){
                x=up[x][j];
            }
        }
        cout << (x==0 ? -1 : x) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}