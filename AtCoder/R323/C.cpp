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

    ll n, m; cin >> n >> m;

    vll val(m+1), pfx(m+1);
    f(i,0,m){
        cin >> val[i];
    }

    ll mx = 0;
    vector<string> scores(n+1);
    f(i,0,n){
        string s;
        cin >> s;

        ll temp = i+1;
        f(i,0,s.size()){
            if(s[i]=='o') temp+=val[i];
        }
        scores[i]=s;
        mx = max(temp, mx);
    }


    f(i,0,n){
        string s = scores[i];
        ll temp = i+1;

        vll best;
        f(i,0,s.size()){
            if(s[i]=='o'){
                temp+=val[i];
            } else best.pb(val[i]);
        } 

        sort(all(best));
        reverse(all(best));

        ll it = 0, ans = 0;
        while(temp<mx){
            temp+=best[it];
            it++;
            ans++;
        }

        cout << ans << "\n";
    }

    


 
    


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

