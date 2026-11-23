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


void solve(){

    ll t, h, u; cin >> t >> h >> u;

    ll ans=0;
    if(t>u){
        ans+=u*4;
        t-=u;
        u=0;
    } else if(t<=u){
        ans+=t*4;
        u-=t;
        t=0;
    }
    ans+=u*3;

    if(t==0){
        ans+=h*3;
        cout << ans << "\n";
        return;
    } 

    if(h==0){
        ans+=t*2+1;
        cout << ans << "\n";
        return;
    }

    if(t==1){
        ans+=5;
        h--;
        ans+=h*3;
        cout << ans << "\n";
        return;
    }
    ll restt=t%2;
    t=t/2;
    if(t>=h){
        ans+=h*7;
        t-=h;
        t=t*2+restt;
        if(t>0)
        ans+=t*2+1;
    } else {
        ans+=t*7;
        h-=t;
        t=restt;
        if(t==1){
            ans+=5;
            h--;
        } 
        ans+=h*3;
    }

    cout << ans << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t;
    cin >> t;
    while(t--){
        solve(); 
    }
}