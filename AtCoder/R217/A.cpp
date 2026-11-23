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
    
    if(n==1){
        cout << 1 << "\n";
        return;
    }
    if(n==2){
        cout << 1 << " " << 2 << "\n";
        return;
    }
    deque<ll> imp;
    deque<ll> p;
    for(int i = 4; i <= n; i+=2){
        p.pb(i);
    }
    for(int i = 3; i <= n; i+=2){
        imp.pb(i);
    }

    vll ans;
    ans.pb(2);
    ll imC=0, pC=0;

    ll flag=1;
    while(!p.empty()||!imp.empty()){
        if(imC==1&&imp.empty()){
            ans.pb(1);
            flag=0;
            imC=0;
            continue;
        }
        else if(pC==1&&p.size()==1&&imp.empty()){
            ans.pb(1);
            flag=0;
            pC=0;
            continue;
        }
        if(imC<2&&!imp.empty()){
            ans.pb(imp.front());
            imp.pop_front();
            imC++;
        } 
        
        else if(pC<2&&!p.empty()){
            ans.pb(p.front());
            pC++;
            p.pop_front();
        } else {
            pC=0;
            imC=0;
        }
    }
    if(flag==1)
    ans.pb(1);

    ll x = 0, sm=0;
    for(ll i : ans){
        sm+=x;
        x^=i;
        cout << i << " ";
    }
    sm+=x; 
    //cout << sm << " ";
    cout<<"\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}