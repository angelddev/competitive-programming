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

    string s, e;
    ll n;
    cin >> s;
    cin >> n;
    f(i,0,n){
        cin >> e;
        ll band=1;
        if(e.size()<s.size()||e.size()%s.size()!=0){
            cout << "NO\n";
            continue;
        }
        f(i,0,e.size()){
            if(e[i]!=s[i%(s.size())]){
                cout << "NO\n";
                band=0;
                break;
            }
        }
        if(band==1){
            cout << "YES\n";
        }
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