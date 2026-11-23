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
    f(i,0,n){
        cin >> arr[i];
    }

    vvll adj(n+1);
    stack<ll> stk;
    
    
    stk.push(arr[0]);
    f(i,1,n){
        if(arr[i]>stk.top()){
            ll mn = arr[i];
            while(!stk.empty()&&arr[i]>stk.top()){
                mn = min(mn, stk.top());
                adj[arr[i]].pb(stk.top());
                stk.pop();
            }
            stk.push(mn);
        } else stk.push(arr[i]);
    }

    if(stk.size()>1){
        cout << "No" << "\n";
    } else {
        cout << "Yes\n";
        f(i,1,n+1){
            for(ll num : adj[i]){
                cout << i << " " << num << "\n";
            }
        }
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