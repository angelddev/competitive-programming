#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
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
   
    ll n; cin >> n;
    string s; cin >> s;

    vector<string> letts(26);
    for(ll i=0; i<26; i++) letts[i] = string(1,'a'+i);
    for(ll i=0; i<26; i++){
        if(s.find(letts[i])>=n){
            cout << letts[i] << "\n";
            return;
        }
    }
    
    vector<string> letts2(26*26);
    ll cont=0;
    for(ll i=0; i<26; i++){
        for(ll j=0; j<26; j++){
            letts2[cont] = letts[i]+string(1,'a'+j);
            if(s.find(letts2[cont])>=n){
            cout << letts2[cont] << "\n";
            return;
            }
            cont++;
        }        
    }

    for(ll j=0; j<26*26; j++)
        for(ll k=0; k<26; k++){
            if(s.find(letts2[j]+string(1,'a'+k))>=n){
            cout << letts2[j]+string(1,'a'+k) << "\n";
            return;
            }
        }

    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}