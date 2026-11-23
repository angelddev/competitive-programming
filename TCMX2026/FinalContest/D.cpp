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

    ll datta[18][18];
    vll cost1(1<<16, 0);
    vll cost2(1<<16, 0);
    vll cost3(1<<16, 0);

    ll n; cin >> n;
    f(i,0,n){
        cin >> datta[i][0] >> datta[i][1] >> datta[i][2] >> datta[i][3] >> datta[i][4] >> datta[i][5]; 
    }

    ll ans = INF;

    for(ll i = 1; i<(1<<n); i++){
        ll sum1 = 0;
        ll sum2 = 0;
        ll sum3 = 0;
        vll temp1;
        vll temp2;
        vll temp3;
        f(j,0,n){
            if(i&(1<<j)){
                cost1[i]+=datta[j][3];
                cost2[i]+=datta[j][4];
                cost3[i]+=datta[j][5];
                temp1.pb(datta[j][0]);
                temp2.pb(datta[j][1]);
                temp3.pb(datta[j][2]);
            }
        }
        sort(all(temp1));
        sort(all(temp2));
        sort(all(temp3));

        ll pen1 = 0, pen2 = 0, pen3 = 0;
        for(int i = 0; i < temp1.size(); i++){
            pen1+=temp1[i];
            pen2+=temp2[i];
            pen3+=temp3[i];
            sum1+=pen1;
            sum2+=pen2;
            sum3+=pen3;
        }

        if(pen1<=180){
            cost1[i]+=sum1;
        } else cost1[i] = INF;
        if(pen2<=180){
            cost2[i]+=sum2;
        } else cost2[i] = INF;
        if(pen3<=180){
            cost3[i]+=sum3;
        } else cost3[i] = INF;
    }


    for(ll i = 0; i < (1<<n); i++){
        ll rem = ((1<<n)-1)^i;
        for(ll j = rem; ; j=(j-1)&rem){
            ll k = ((1<<n)-1)^i^j;

            ans=min(ans, cost1[i]+cost2[j]+cost3[k]);
            if(j==0) break;
        }
    }

    if(ans<INF){
        cout << ans << "\n";
    } else cout << "-1\n";

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

