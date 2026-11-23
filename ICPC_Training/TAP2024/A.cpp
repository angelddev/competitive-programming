#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define rf(i,s,e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define pb push_back
#define F first
#define S second
#define endl '\n'
using namespace std; 

const ll MOD = 1e9+7, INF = 1e18;

ll n, m, k; 

void solve(){

    ll n, m; cin >> n >> m;

    vll trips(n);
    vll temp(m);
    vll emplyes;

    f(i,0,n){
        cin >> trips[i];
    }

    f(i,0,m){
        cin >> temp[i];
        temp[i]*=-1;
    }

    ll mx = temp[0];
    emplyes.pb(temp[0]);
    f(i,1,m){
        if(temp[i]>mx){
            emplyes.pb(temp[i]);
            mx = temp[i];
        }
    }

    m = emplyes.size();
    

    f(i,0,n){
        ll num = trips[i]*-1;
        while(true){
            auto it = lower_bound(all(emplyes), num);
            if(it==emplyes.end()) break;
            ll act1 = num*-1, act2 = (*it)*-1;
            num = (act1%act2)*-1; 
        }
        cout << num*-1 << " ";
    } cout << "\n";
    
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
    // cin>>t; 
    while(t--){
        solve(); 
    }
}