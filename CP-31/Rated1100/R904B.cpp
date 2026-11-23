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

    ll n; cin >> n;
    string s; cin >> s;
    reverse(all(s));
    queue<ll> zeroes;

    f(i,0,n){
        if(s[i]=='0'){
            zeroes.push(i);
        }
    }
    
    ll sum=0;
    vll ans(n);
    f(i,0,n){
        if(s[i]=='1'){
            while(!zeroes.empty()&&zeroes.front()<i){
                zeroes.pop();
            }
            if(zeroes.empty()){
                f(j,i,n){
                    ans[j]=-1;
                }
                break;
            }
            sum+=(zeroes.front()-i);
            swap(s[i], s[zeroes.front()]);
            ans[i]=sum;
            zeroes.pop();
        }
        else ans[i]=sum;
    }
    
    f(i,0,n) cout << ans[i] << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}


