#include <bits/stdc++.h>

#define ll long long 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
template<typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll INF = 1e18;
const ll MOD = 1e9 +7;


void solve(){

    ll n, r, l;
    cin >> n >> r >> l;
    pbds<ll> A;
    r--, l--;
    f(i,0,n){
        A.insert(i+1);
    }

    set<ll> ans;
    ll lptr=n-1;
    ll rptr=0;

    /**ll sz=A.size()-1;
        rptr=(rptr+r)%sz;
        lptr = (lptr - l) % sz;
        if (lptr < 0) lptr += sz;

    cout << lptr << " " << rptr << "\n";
    

    A.erase(*A.find_by_order(lptr));

    for(ll num : A) cout << num << " ";
    cout << "\n"; 

    sz=A.size()-1;
    rptr=(rptr)%sz;
    if(lptr==0){
        lptr=sz-1;
    } else lptr-=1;

    cout << lptr << " " << rptr << "\n";**/


while(A.size() > 2){
        ll sz = A.size(); 
        rptr = (rptr + r) % sz;
        lptr = (lptr - (l % sz) + sz) % sz;

        ll valR = *A.find_by_order(rptr);
        ll valL = *A.find_by_order(lptr);

        if(lptr == rptr){
            ans.insert(valR);
            A.erase(valR);
            sz = A.size();
            if (sz > 0) {
                rptr %= sz;
                lptr = (lptr - 1 + sz) % sz;
            }
        } else {
            ll low = min(lptr, rptr);
            ll high = max(lptr, rptr);
            
            A.erase(valL);
            A.erase(valR);
            
            sz = A.size();
            if (sz > 0) {
                if (rptr == low) rptr %= sz; 
                else rptr = (high - 1) % sz;
                if (lptr == low) lptr = (low - 1 + sz) % sz;
                else lptr = (high - 2 + sz) % sz;
            }
        }
    }

    for(ll num: A){
        ans.insert(num);
    }
    for (ll num : ans){
        cout << num << " ";
    } cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}