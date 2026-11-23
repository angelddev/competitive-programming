#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define endl '\n'
#define pb push_back 
#define F first 
#define S second 
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 

ll n, m, k; 

void solve(){

    ll n; cin >> n;
    vll arr(n);
    ll cont1 = 0, sm = 0, flg = 0;
    f(i,0,n){
        cin >> arr[i];
        if(arr[i]==1) cont1++;
        if((i!=0&&i!=n-1)&&arr[i]>1) flg = 1;
        sm+=arr[i];
    }

    if(cont1==n){
        cout << "-1 \n";
        return;
    }
    if((cont1==n-1)){
        if((arr[0]!=1||arr[n-1]!=1)){
            cout << max(arr[0], arr[n-1]) << "\n";
        } else cout << sm-1 << "\n";
    } else {
        if(flg) cout << sm-1 << "\n"; 
        else cout <<  arr[0]+arr[n-1]-1 << "\n";
    }




}

int main(){
    #ifdef DEBUG
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif 

    ll t=1;
    cin>>t; 
    while(t--){
        solve(); 
    }
}