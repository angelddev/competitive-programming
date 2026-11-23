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
    
    ll n, k; cin >> n >> k;

    ll ones, zeroes;
    if(n%2){
        ones = n/2+1;
        zeroes = n/2;
    } else {
        ones = n/2;
        zeroes = n/2;
    }

    ll pairs1 = (k+1)/2, pairs0=k/2;
    
    if((ones-1)+(zeroes-1)<k){
        cout << "-1\n";
        return;
    }
     
    string ans="1";
    if(n == 1){
        cout << ans << "\n";
        return;
    }

    ll cont = 2;
    while(pairs1 > 0){
        pairs1--;
        ans += "1";
        cont++;
    }
    ans+="0";
    while(pairs0 > 0){
        pairs0--;
        ans += "0";
        cont++;
    }

    ll c = 0;
    for(ll i = cont; cont < n; cont++){
        if(c%2==0)
        ans+="1";
        else ans+="0";
        c++;
    }
    
    ll c1 = count(all(ans), '1');
    ll c0 = count(all(ans), '0');
    if(c1 > ones){
        ans.pop_back();
        ans = "0" + ans;
    } else if(c0 > zeroes){
        ans.pop_back();
        ans += "1";
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}