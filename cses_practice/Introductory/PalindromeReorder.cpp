#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 
 

void solve(){
    
    string s; cin >> s;
    vll letters(26, 0);

    ll n=s.size();
    f(i,0,n) letters[s[i]-'A']++;

    ll cont=0;
    f(i,0,26) if(letters[i]%2) cont++;
    if(cont>=2) {
        cout << "NO SOLUTION" << "\n";
        return;
    }

    char mid = '!';
    f(i,0,26){
        if(letters[i]>0){
            if(letters[i]%2){
            mid='A'+(char)i;
            }
            for(int j=0; j<letters[i]/2; j++){
                cout << char('A'+i); 
            }
        }
    }
    if(mid!='!')
    cout << mid;

    for(int i=25; i>=0; i--){
        if(letters[i]>0){
            for(int j=0; j<letters[i]/2; j++){
                cout << char('A'+i); 
            }
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    solve();
}