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
vvll dp;
ll OS = 7200;
vll cnt;
vll fcnt;

void solve(){

    ll n;
    cin >> n;
    if(n==1){
        cout << "0\n";
        return;
    }

    cout << dp[n][OS] << "\n";
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    dp.assign(809, vll(15000, 0));
    cnt.assign(25, 0);
    fcnt.assign(25, 0);
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            if(i!=j)
            cnt[(i-j)+9]++;
        }
    }
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i!=j)
            fcnt[(i-j)+9]++;
        }
    }

    dp[0][OS]=1;
    for(int pos = 0; pos < 800; pos++){

        for(ll diff = -9*pos; diff<=9*pos; diff++){
            
            ll ways=dp[pos][OS+diff];
            if(ways==0) continue;
            for(int delta = -9; delta<=9; delta++){
                
                ll waydelta;
                if(pos==0){
                    waydelta = fcnt[delta+9];
                } else waydelta = cnt[delta+9];

                if(waydelta==0) continue;
                ll val = delta+diff;
                dp[pos+1][val+OS]+= ways*waydelta;
                dp[pos+1][val + OS] %= MOD;
            }
        }
    }

    while(t--){
        solve(); 
    }
}