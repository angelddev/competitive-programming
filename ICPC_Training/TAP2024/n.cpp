#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define rf(i,s,e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define pb push_back
#define F first
#define S second
#define endl '\n'
using namespace std; 

const ll MOD = 1e9+7, INF = 1e18;

ll n, m, k; 

void solve(){

    ll n; cin >> n;
    vector<vll> combs(15);

    combs[0]={0};
    combs[1]={1, 4};
    combs[2]={2, 3};
    combs[3]={1, 1, 3};
    combs[4]={1, 2, 2};
    combs[5]={2, 4, 4};
    combs[6]={3, 3, 4};
    combs[7]={1, 1, 1, 2};
    combs[8]={1, 3, 3, 3};
    combs[9]={4, 2, 2, 2};
    combs[10]={4, 4, 4, 3};
    combs[11]={1, 1, 1, 1, 1};
    combs[12]={2, 2, 2, 2, 2};
    combs[13]={3, 3, 3, 3, 3};
    combs[14]={4, 4, 4, 4, 4};

    vll rems(10);
    ll x;
    f(i,0,n){
        cin >> x;
        rems[x%5]++;
    }
    

    ll ans = 0;
    while(true){
        ll flag = 0;
        for(vll els: combs){
            ll flg2=0;
            vll temp(5);
            for(ll el: els){
                temp[el]++;
            }

            f(i,0,5){
                if(temp[i]>rems[i]) flg2=1; 
            }
            if(flg2==1) continue;

            flag=1;
            f(i,0,5){
                rems[i]-=temp[i]; 
            }
            ans++;
            break;
        }
        if(flag==0) break;
    }
    cout << ans << "\n";
}

int main(){
    #ifdef DEBUG 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif

    ll t=1;
    // cin>>t; 
    while(t--){
        solve(); 
    }
}