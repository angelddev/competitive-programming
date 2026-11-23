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
    ll a, b; cin >> a >> b;
    vll freqs(a+b+1, 1), nums;
    ll x;
    f(i,0,a){
        cin >> x;
        freqs[x]=1;
    }
    f(i,0,freqs.size()){
        if(freqs[i]==1)
        nums.pb(i);
    }

    sort(nums.begin(), nums.end());

    ll divisibleByAlice=0, nonDivisable=0;
    f(i,0,b){
        cin >> x;
        ll sz=nums.size();

        if(freqs[x]==1) divisibleByAlice++;
        ll p=0, band=1, band2=1;
        while(nums[p]<=(x/2)&&(band2==1||band==1)){
            if(x%nums[p]==0&&band==1){
                divisibleByAlice++;
                band=0;
            }

            if(x%nums[p]!=0&&band2==1){
                band2=0;
                nonDivisable++;
            }
            p++;
        }
    }


    if(b%2==0){
        cout << "Bob" << "\n";
    }

    else if(divisibleByAlice>n/2)
}
 
int main(){
    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}