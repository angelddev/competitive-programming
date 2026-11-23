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
#define ld long double
using namespace std; 

const ll MOD = 1e9+7, INF = 1e18;

ll n, m, k;

ld dis(ld x1, ld y1, ld x2, ld y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void solve(){
    ld l, w, r, b; 
    ld x, y, xc, yc;
    vector<ld> disR, disB; 
    cin>>n>>l>>w>>xc>>yc; 
    f(i, 0, n){
        cin>>x>>y;
        disR.pb(dis(x, y, xc, yc));  
    }
    f(i, 0, n){
        cin>>x>>y;
        disB.pb(dis(x, y, xc, yc));  
    }
    sort(all(disR)); 
    sort(all(disB)); 

    if(disR[0] < disB[0]){
        ll tot=0; 
        f(i, 0, n){
            if(disR[i] < disB[0]) tot++; 
        }
        cout<<"A "<<tot<<"\n"; 
    } 
    else{
        ll tot=0; 
        f(i, 0, n){
            if(disB[i] < disR[0]) tot++; 
        }
        cout<<"R "<<tot<<"\n"; 
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
    // cin>>t; 
    while(t--){
        solve(); 
    }
}