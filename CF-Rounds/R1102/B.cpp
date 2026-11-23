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

ll is_palindrome(ll num){

    string s = to_string(num);

    f(i,0,s.size()/2){
        if(s[i]==s[(s.size()-1)-i]) continue;
        else return 0;
    }
    return true;
}


void solve(){

    ll n; cin >> n;

    
    ll md=n%12;

    ll num=md;
    while(true){
        if(is_palindrome(num)) break;
        num += 12;
    }

    if(num>n){
        cout << -1 << "\n";
    }else{
        cout << num << " " << n-num << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}