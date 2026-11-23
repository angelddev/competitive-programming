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

ll n, k; 

void solve(){
    cin>>n>>k; 

    if(k<n*(n-1)/2 or k>(n-1)*(n-1)){
        cout<<-1<<"\n"; 
        return; 
    }
    //cout<<"NO se\n";
    ll sum=(n-1)*(n-1); 
    vll difs; 
    difs.pb(0); 
    cf(i, 1, n-1){
        sum-=n-1; 
        sum+=i; 
        if(sum == k){
            difs.pb(i); 
            break; 
        }
        else if(sum > k){
            difs.pb(i);
        }
        else{
            difs.pb(i+k-sum); 
            break;
        }
    }
    while(difs.size()!=n) difs.pb(n-1); 
    //for(auto u: difs) cout<<u<<" "; cout<<"\n";
    set<ll> disp; 

    cf(i, 1, n) disp.insert(-i); 
    cf(i, 1, n){
        ll num = n - difs[i-1]; 
        if(disp.count(-num)){
            cout<<num<<" "; 
            disp.erase(-num); 
        }
        else{
            cout<<-(*disp.begin())<<" ";
            disp.erase((*disp.begin()));
        }
    }cout<<"\n";
    //for(auto u: disp) cout<<u<<" "; cout<<"\n"; 

    cf(i, 1, n) disp.insert(i); 
    cf(i, 1, n){
        ll num = 1 + difs[i-1]; 
        if(disp.count(num)){
            cout<<num<<" "; 
            disp.erase(num); 
        }
        else{
            cout<<(*disp.begin())<<" ";
            disp.erase((*disp.begin()));
        }
    }cout<<"\n";
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}