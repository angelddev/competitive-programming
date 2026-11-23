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
vll nums;

vvll st; 
vll lg;

ll rmq(ll l, ll r){
    if (l>r) return r; 
    ll len=r-l+1;
    ll k=lg[len];
    ll idx1=st[k][l];
    ll idx2=st[k][r-(1ll<< k)+1];
    ll idx;
    if(nums[idx1]>=nums[idx2]) return idx1;
    else return idx2;
}


void solve(){
    
    ll n; cin >> n;
    

    vll apps(n+1, -1);
    nums.assign(n+1, 0);
    f(i,0,n){
        cin >> nums[i];
    }
    
    lg.assign(n + 1, 0);
    f(i,2,n +1) lg[i]=lg[i/2]+1;
    
    st.assign(LOG, vll(n+1, 0));
    f(i, 0, n) st[0][i]=i; 
    f(j, 1, LOG) {
        for (ll i=0;  i+(1ll<<j)<=n; i++) {
            ll idx1=st[j-1][i];
            ll idx2=st[j-1][i+(1ll<<(j-1))];
            if(nums[idx1]>=nums[idx2]){
                st[j][i]=idx1;
            } else st[j][i]=idx2;
        }
    }

    ll lstremoved=-1, mxidx=0;
    f(i,0,n){
        if(apps[nums[i]]>lstremoved){
            //cout << "YEP ";
            lstremoved=apps[nums[i]];
            mxidx = rmq(lstremoved+1, i);
            //cout << mxidx << "\n";
        } else{
            if(nums[i]>nums[mxidx]){
                //cout << "HERE " << nums[i] << "\n";
                mxidx=i;
            }  //else cout << "NOPE\n";
        }
        apps[nums[i]]=i;
        cout << nums[mxidx] << " " << mxidx+1 << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}