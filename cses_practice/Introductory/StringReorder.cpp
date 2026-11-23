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
    
    string s; cin >> s;

    vll freqs(30, 0);

    f(i,0,s.size()){
        freqs[s[i]-'A']++;
    }

    vector<char> ans;
   
    ll n = s.size();

    ll last = -1;
    while(ans.size()!=s.size()){
        ll next = -1;
        f(i, 0, 27){
            if(n-freqs[i]<freqs[i]-1){
                cout << "-1\n";
                return;
            }
            if(n-freqs[i]==freqs[i]-1&&i!=last){
                next = i;
            }
        }

        if(next == -1){
            f(i,0,27){
                if(freqs[i]>0&&last!=i){
                    next = i;
                    break;
                }
            }
        }

        last =next;
        freqs[next]--;
        ans.push_back(char(next+'A'));
        n--;
    }

    f(i,0,ans.size()){
        cout << ans[i];
    }

    cout  << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

