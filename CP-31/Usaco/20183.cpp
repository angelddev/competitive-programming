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

    vll arr(n);
    ll idx = 1;

    cin >> arr[0];

    ll x;
    f(i,1,n){
        cin >> x;
        if(x==arr[idx-1]) continue;
        arr[idx]=x;
        idx++;
    }

    // f(i,0,idx){
    //     cout << arr[i] << " ";
    // } cout << "\n";

    pll imp1 = {-1, -1}, imp2 = {-1, -1};
    f(i,0,idx-1){
        if(arr[i]>arr[i+1]){
            imp1.F = arr[i];
            imp1.S = i;
            imp2.F = arr[i+1];
            imp2.S = i+1;
            break;
        }
    }

    if(imp1.F == -1){
        cout << 0 << "\n";
        return;
    }

    ll sw1 = 0, sw2= 0;
    ll idx1 = imp1.S+1;
    ll idx2 = imp2.S-1;

    while(idx1 < idx-1 && arr[imp1.S] > arr[idx1]){
        idx1++;
        sw1++;
    }

    while(idx2>0&&arr[imp2.S]<arr[idx2]){
        idx2--;
        sw2++;
    }

    cout << max(sw1, sw2) << "\n";


}

int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1;
    while(t--){
        solve(); 
    }
}