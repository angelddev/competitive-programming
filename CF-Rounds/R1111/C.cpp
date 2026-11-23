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

    vll a(n), b(n);
    ll flag = 0;
    f(i,0,n){
        cin >> a[i];
        if(a[i]==1) flag = 1;
    }
    f(i,0,n){
        cin >> b[i];
        if(b[i]==0&&flag==1) flag=2;
    }

    ll cha=0, chb=0;
    f(i,0,n){
        if(a[i]==1&&a[i]!=b[i]){
            cha++;
        }
        if(a[i]==0&&a[i]!=b[i]){
            chb++;
        }
    }

    if(cha==0&&chb==0){
        cout << 0 << "\n";
        return;
    }

    if(cha==0){
        if(flag==2){
            cout << 2 << "\n";
            return;
        }
        f(i,0,n){
            if(a[i]==0&&a[i]!=b[i]){
                cout << "-1\n";
                return;
            }
        }
    cout << 0 << "\n"; return;
    } else {
        if(cha%2==1){
            cout << 1 << "\n";
        } else cout << 2 << "\n";
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