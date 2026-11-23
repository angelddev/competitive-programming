#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 
 

void solve(){
    
    ll n; cin >> n;


    vector<pll> dog1(n);
    vector<pll> dog2(n);
    vector<pll> dog3(n);

    ll x;
    f(i,0,n){
        cin >> x; dog1[i]={x,i};
    }
    f(i,0,n){
        cin >> x; dog2[i]={x,i};
    }
    f(i,0,n){
        cin >> x; dog3[i]={x,i};
    }

    sort(dog1.rbegin(), dog1.rend());
    sort(dog2.rbegin(), dog2.rend());
    sort(dog3.rbegin(), dog3.rend());

    ll mx=0;
    f(i,0,3){
        ll sum=0;
        sum+=dog1[i].first;
        f(j,0,3){
            if(dog1[i].second==dog2[j].second) continue;
            sum+=dog2[j].first;
            f(k,0,3){
                if(dog3[k].second==dog2[j].second||dog3[k].second==dog1[i].second) continue;
                sum+=dog3[k].first;
                mx=max(sum, mx);
                sum-=dog3[k].first;
            }
            sum-=dog2[j].first;
        }
        sum-=dog1[i].first;
    }

    cout << mx << endl;
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
    solve();
}