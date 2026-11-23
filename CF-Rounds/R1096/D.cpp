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

    ll n; cin>>n;
    vll nums(2*n);
    f(i,0,2*n) cin>>nums[i];

    ll best=0;

    ll fst_idx=-1,scn_idx=-1;
    f(i,0,2*n){
        if(nums[i]==1&&fst_idx==-1) fst_idx=i;
        else if(nums[i]==1&&scn_idx==-1) scn_idx=i;
    }

    if(fst_idx!=-1&&scn_idx!=-1){

        ll l=fst_idx,r=scn_idx;
        ll mex=0,ptr=0;
        map<ll,ll> mex_calc;

        while(l<=r){
            if(nums[l]==nums[r]){
                mex_calc[nums[l]]=1;
                while(mex_calc[ptr]==1) ptr++;
                mex=ptr;
                best=max(best,mex);
                l++,r--;
            }else break;
        }

        l=fst_idx-1,r=scn_idx+1;

        while(l>=0&&r<2*n){
            if(nums[l]==nums[r]){
                mex_calc[nums[l]]=1;
                while(mex_calc[ptr]==1) ptr++;
                mex=ptr;
                best=max(best,mex);
                l--,r++;
            }else break;
        }
    }

    fst_idx=-1,scn_idx=-1;
    f(i,0,2*n){
        if(nums[i]==0&&fst_idx==-1) fst_idx=i;
        else if(nums[i]==0&&scn_idx==-1) scn_idx=i;
    }

    if(fst_idx!=-1&&scn_idx!=-1){

        ll l=fst_idx,r=scn_idx;
        ll mex=0,ptr=0;
        map<ll,ll> mex_calc;

        while(l<=r){
            if(nums[l]==nums[r]){
                mex_calc[nums[l]]=1;
                while(mex_calc[ptr]==1) ptr++;
                mex=ptr;
                best=max(best,mex);
                l++,r--;
            }else break;
        }

        l=fst_idx-1,r=scn_idx+1;

        while(l>=0&&r<2*n){
            if(nums[l]==nums[r]){
                mex_calc[nums[l]]=1;
                while(mex_calc[ptr]==1) ptr++;
                mex=ptr;
                best=max(best,mex);
                l--,r++;
            }else break;
        }
    }

    cout<<best<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    while (t--) {
        solve(); 
    }
}