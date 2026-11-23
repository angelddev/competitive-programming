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


void solve(){

    ll n;
    cin >> n;

    vll teas(n+1), people(n+1);
    cf(i,1,n){
        cin >> teas[i];
    }
    cf(i,1,n){
        cin >> people[i];
    }

    teas[0]=0;
    vll pfx(n+1);
    pfx[1]=people[1];
    cf(i,2,n){
        pfx[i]=pfx[i-1]+people[i];
    }


    vll ans(n+1, 0);
    vll diff(n+2, 0);
    cf(i,1,n){
        diff[i]+=diff[i-1];
        auto it = upper_bound(pfx.begin()+i, pfx.end(), teas[i]+pfx[i-1]);
        if(it==pfx.end()){
            diff[i]++;
        } else {
            ll r = it-pfx.begin();
            diff[i]++;
            diff[r]--;
            ans[r]+=teas[i]-(pfx[r-1]-pfx[i-1]);
        }
    }


    //cout << "DIFFS:\n";
    //cf(i, 1, n){
      //  cout << diff[i] << "\n";
    //}

    cf(i,1,n){
        ans[i]+=diff[i]*people[i];
    }

    cf(i, 1, n){
        cout << ans[i] << " ";
    } cout << "\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    while(t--){
        solve(); 
    }
}