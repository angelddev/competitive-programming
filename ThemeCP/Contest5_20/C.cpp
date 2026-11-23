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

    vector<set<ll>> sizes(n+1);
    ll x, mx = 0;
    cf(i,1,n){
        cout << "? " << i << " ";
        cout << n << " ";
        cf(j,1,n){
            cout << j << " ";
        }
        cout << endl;
        cin >> x;
        mx = max(mx, x);
        sizes[x].insert(i);
    }

    if(mx == 1){
        cout << "! " << 1 << " " << 1 << endl;
        return;
    }

    vll weGood;
    ll discarded = sizes[mx].size()-1;
    weGood.pb(*sizes[mx].begin());
    for(ll i = mx-1; i>=1; i--){
        vll temp;
        for(ll j = i-1; j>=1; j--){
            for(ll el3 : sizes[j]){
                temp.pb(el3);
            }
        }   
        if(i == 1){
            for(ll el1 : sizes[1]){
                cout << "? " << weGood[0] << " ";
                cout << mx << " ";
                for(ll el : weGood){
                    cout << el << " ";
                }            
                cout << el1 << endl;
                cin >> x;
                if(x==mx){
                    cout << "! " << mx << " ";
                    for(ll el : weGood){
                        cout << el << " ";
                    }            
                    cout << el1 << endl;
                    return;
                }
            }
        }

        for(ll el1 : sizes[i]){
            cout << "? " << weGood[0] << " ";
            cout << weGood.size() + temp.size() + 1 << " ";
            for(ll el : weGood){
                cout << el << " ";
            }            
            for(ll el : temp){
                cout << el << " ";
            } 
            cout << el1 << endl;
            cin >> x;
            if(x==mx){
                discarded-=sizes[mx].size()-1;
                weGood.pb(el1);
                break;
            }
        }   
    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

