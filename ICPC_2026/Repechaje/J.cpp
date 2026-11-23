#include <bits/stdc++.h>

#define ll long long 
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
vll arr;
ll pfx[200004];
ll sfx[200003];
map<pair<pll, ll>, ll> mp;


ll n;
ll build(ll l, ll r, ll k){



    if(r-l+1<=k){
        return 0;
    }

    if(mp[{{l, r}, k}]!= 0){
        return mp[{{l, r}, k}];
    }

    ll mid = (l+r)/2;
    if(k==1){
        ll rans = pfx[r]-pfx[mid]-arr[mid]*(r-mid);
        ll lans = sfx[l]-sfx[mid]-(arr[n-1]-arr[mid])*(mid-l);
        //cout << l << " "<< r << " "<< k << " " << rans + lans << "\n"; 
        return lans+rans;
    }

    ll ans = INF;
    f(i,1,k){
        ans = min(ans, build(l, mid, i)+build(mid+1, r, k-i));
    }
    mp[{{l, r}, k}] = ans;

    //cout << l << " "<< r << " "<< k << " " << ans << "\n"; 
    return ans;
}

void solve(){
 
    ll k; cin >> n >> k;
    arr.assign(n, 0);
    f(i,0,n){
        cin >> arr[i];
    }

    pfx[0]=arr[0];
    f(i,1,n){
        pfx[i]= pfx[i-1]+arr[i];
    }

    sfx[n-1]=0;
    rf(i, n-2, 0){
        sfx[i]=sfx[i+1]+(arr[n-1] - arr[i]);
    }


    cout << build(0, n-1, k) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}
