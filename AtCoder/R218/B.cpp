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

    set<ll> st;
    ll x;
    f(i,0,n){
        cin >> x;
        st.insert(x);
    }

    vll nums;
    for(auto i : st){
        nums.pb(i);
    }

    ll prev=nums[0];
    f(i,1,nums.size()){
        ll tmp=nums[i];
        nums[i]=nums[i]-prev;
        prev=tmp;
    }

    ll win;
    if(nums[0]==0) win = 1;
    else win = 0;
    f(i,0,nums.size()){
        if(nums[i]==1) continue;
        else win^=1;
        //cout << nums[i] << " " <<win << "\n";
    }

    if(win==1) cout << "Alice\n";
    else cout << "Bob\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}