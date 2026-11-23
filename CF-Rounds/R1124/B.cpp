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
 
    
    ll n;
    cin >> n;

    vvll numbers(n+1);
    vll arr(n+1);
    f(i,0,n){
        cin >> arr[i];
        ll curr = arr[i];
        for(ll st=0; st<50; st++) {
            numbers[i].pb(curr);
            ll nxt = 0, temp=curr;
            while(temp>0) {
                ll d=temp%10;
                nxt+=d*d;
                temp/=10;
            }
            curr = nxt;
        }
    }

    ll ans = 0;
    f(i,0,n){
        f(j,i+1,n){
            ll flag = 0;
            f(k,0,numbers[i].size()){
                    if(numbers[i][k]==numbers[j][k]){
                        flag = 1;
                        break;
                    }
            }
            if(flag==1) ans++;
        }
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}


