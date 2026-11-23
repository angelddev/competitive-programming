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

    ll n; cin >> n;

    ll sz=5+(n-1)*2;
    cf(i,1,sz){
        int idx=0;
        if(i==1){
            while(idx!=n){
                cout << " ";
                idx++;
            }
            cf(i,0,n){
                cout << "_";
            }
            cout << "\n";
        }
        else if(i==(sz+1)/2){
            cout << "/";
            f(i,0,n){
                cout << "_";
            }
            f(i,0,sz-4){
                cout << " ";
            }
            cout << "\\";
            cf(i,0,n){
                cout << "_";
            }
            cout << "\n";
        } else if(i==sz){
            f(i,0,2*n){
                cout << " ";
            }
            cout << "\\";
            cf(i,0,n){
                cout << "_";
            }
            cout << "/";
            cout << "\n";
        } else if(sz!=5){
            if(i<sz/2){
                int wait = n-(i-1);
                f(i,0,wait){
                    cout << " ";
                }
                cout << "/";
                int wait2 = n+2*(i-2);
                cf(i,0,wait2) cout << " ";
                cout << "\\";
                cout << "\n";
            } else {
                if(i>sz/2&&i!=sz-1){
                    int wait = (n)+(i-(sz+1)/2)-1;
                    cf(i,0,wait) cout << " ";
                    cout << "\\";
                    int wait2 = (n)+2*(sz-i-1);
                    cf(i,0,wait2) cout << " ";
                    cout << "/\n";
                }
            }


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