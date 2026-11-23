
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
    vll nums(n);
    f(i,0,n){
        cin >> nums[i];
    }

    vll nums2(n);
    f(i,0,n){
        cin >> nums2[i];
    }

    vll pos(n, -1);
    vll vis(n);
    f(i,0,n){
        f(j,0,n){
            if(nums2[j]>=nums[i]&&vis[j]==0){
                pos[i]=j;
                vis[j]=1;
                break;
            }
        }
    }

    f(i,0,n) if(pos[i]==-1){
        cout << "-1\n"; return;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (pos[i] > pos[j])
                ans++;
    cout << ans << "\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}