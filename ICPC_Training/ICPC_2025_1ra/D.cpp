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

    ll k; cin>> k;
    vll ings(k+1);
    f(i,0,k) cin >> ings[i];
    ll n; cin >> n;
    vvll order(n+1, vll(k+1));
    vll sumPerDay(k+1, 0);

    //fill matrix and sum of ingredients per day
    f(i,0,n){
        f(j,0,k){
            cin >> order[i][j];
            sumPerDay[j]+=order[i][j];
        }
    }

    ll mnDay=INF, mnOrder=INF;
    
    f(i,0,k){
        if(sumPerDay[i]==0) continue;
        ll days=ings[i]/sumPerDay[i];

        if(days<=mnDay){
            ll norder=0;
            ll rest=ings[i]-sumPerDay[i]*days;
            for(ll j=0; j<n; j++){
                if(order[j][i]>rest){
                    norder=j;
                    break;
                }
                rest-=order[j][i];
            }

            if(days==mnDay){
                mnOrder=min(mnOrder, norder);
            } else {
                mnDay=days;
                mnOrder=norder;
            }
        }
    }

    cout << mnDay+1 << " " << mnOrder+1 << "\n";
   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}