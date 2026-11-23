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

    ll n, q; cin >> n >> q;
    vpl queries(q), nums(n);

    vll original(n);
    vll pos(n+1);
    f(i,0,n){
        cin >> nums[i].F;
        nums[i].S=i;
        original[i]=nums[i].F;
        pos[nums[i].F]=i;
    }

    f(i,0,q){
        cin >> queries[i].F;
        cin >> queries[i].S;
    }

    ll ans=1;
    sort(all(nums));
    f(i,1,n){
        if(nums[i].S<nums[i-1].S) ans++;
    }

    f(i,0,q){
        ll n1=original[queries[i].F-1], n2=original[queries[i].S-1];
        set<ll> used;

        if(n1<n&&used.count(n1)==0){
            if(pos[n1]>pos[n1+1])
            ans--;
            used.insert(n1);
        }
        if(n1>1&&used.count(n1-1)==0){
            if(pos[n1]<pos[n1-1])
            ans--;
            used.insert(n1-1);
        }

        if(n2<n&&used.count(n2)==0){
            if(pos[n2]>pos[n2+1])
            ans--;
            used.insert(n2);
        }
        if(n2>1&&used.count(n2-1)==0){
            if(pos[n2]<pos[n2-1])
            ans--;
            used.insert(n2-1);
        }

        ll temp=pos[n1];
        pos[n1]=pos[n2];
        pos[n2]=temp;
        swap(original[queries[i].F-1], original[queries[i].S-1]);
        used.clear();
        // SUBS
        if(n1<n&&used.count(n1)==0){
            if(pos[n1]>pos[n1+1])
            ans++;
            used.insert(n1);
        }
        if(n1>1&&used.count(n1-1)==0){
            if(pos[n1]<pos[n1-1])
            ans++;
            used.insert(n1-1);
        }

        if(n2<n&&used.count(n2)==0){
            if(pos[n2]>pos[n2+1])
            ans++;
            used.insert(n2);
        }
        if(n2>1&&used.count(n2-1)==0){
            if(pos[n2]<pos[n2-1])
            ans++;
            used.insert(n2-1);
        }

        cout << ans<< "\n";
    }

    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}