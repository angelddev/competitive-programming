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

void solve() {

    ll n, k;
    cin >> n >> k;

    vll a(n);
    map<ll, ll> mp;
    f(i,0,n){
        cin >> a[i];
        mp[a[i]]++;
    }

    vll v, c;
    for(auto [val, frq]: mp){
        v.pb(val);
        c.pb(frq);
    }

    ll m = v.size();
    vector<ll> loss(m, 0);
    vector<ll> can(m, 0);

    ll r=m-1;
    ll cur=0;

    rf(i,m-1,0){
        while(r > i && v[r] > v[i]+k){
            if(loss[r]) cur--;
            r--;
        }
        if(cur>0) can[i]=1;

        ll t =0;
        ll rem=c[i]-1;

        if(rem==0){
            t=can[i];
        } else {
            if(can[i]||(rem%2!=0))t=1;
        }
        loss[i]=!t;
        if(loss[i])cur++;
    }

    f(i,0,m){
        ll rem=c[i]-1;
        ll t=0;
        if(rem==0){
            t=can[i];
        } else {
            if(can[i]||(rem%2!=0))t=1;
        }

        if(t==1){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}