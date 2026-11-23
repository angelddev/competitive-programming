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


    ll cont1=0, cont2=0, cont3=0;

    ll fst=-1, scd=-1;

    ll idx=0;
    if(nums[0]==1&&nums[1]==3){
        fst=1;
        idx=2;
    }
    for( ; idx<n; idx++){
        if(cont1>=(cont2+cont3)&&(cont1>0)&&fst==-1){
            fst=idx-1;
            cont1=cont2=cont3=0;
        }
        if((cont1+cont2)>=cont3&&(cont1>0||cont2>0)&&fst!=-1){
            scd=idx-1;
        }
        if(nums[idx]==1)cont1++;
        else if(nums[idx]==2) cont2++;
        else cont3++;
    }
    
    if(fst==-1||scd==-1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}