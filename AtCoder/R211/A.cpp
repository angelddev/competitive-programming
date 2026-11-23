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


    ll contDiff=0, contNormal=0;
    vll nums(10);
    cf(i,1,9){
        cin >> nums[i];
        if(i!=5){
            contNormal+=nums[i];
        }
    }

    if(nums[5]>0){
        if(contNormal<nums[5]){
            cout << (nums[5]-1)-contNormal << "\n";
        } else cout << 0 << "\n";
        return;
    }
    
    ll flag = 0;
    cf(i,1,9){
        if(nums[i]>0&&nums[10-i]>0){
            flag=1;
        }
    }

    if(flag==0||contDiff>2){
        cout << 0 << "\n";
    }
    else cout << 1 << "\n";


    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}