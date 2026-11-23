#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 998244353;

void solve(){

    ll n, s, t; cin >> n >> s >> t;

    vll robots(n);
    f(i,0,n){
        cin >> robots[i];
    }
    vll spikes(s);
    f(i,0,s){
        cin >> spikes[i];
    }

    sort(all(spikes));

    string instructions; cin >> instructions;
    map<ll, ll> dyingPositions;

    f(i,0,n){
        auto it=upper_bound(all(spikes), robots[i]);
        if(it==spikes.end()){
            dyingPositions[100005]++;
        } else {
            dyingPositions[*it-robots[i]]++;
        }

        auto it2=lower_bound(all(spikes), robots[i]);
        if(it2==spikes.begin()){
            dyingPositions[100005]++;
        }
        else {
            it2--;
            dyingPositions[*(it2)-robots[i]]++;
        }
    }

    ll pos=0;
    f(i,0,t){
        if(instructions[i]=='R')
            pos++;
        else pos--;

        if(dyingPositions[pos]>0){
            n-=dyingPositions[pos];
            dyingPositions[pos]=0;
        }

        cout << n << " ";
        if(n==0){
            for(ll j=i+1; j<t; j++){
                cout << 0 << " ";
                i=j;
            }
        }
    }
    cout << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}