#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define endl '\n'
#define pb push_back 
#define F first 
#define S second 
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 

ll n, m, k; 

void solve(){
    ll n, k, p, m, d;
    vll a;
    cin >> n >> k >> p >> m;
    map<ll, ll> mpult;
    map<ll, ll> mpveces;

    bool flag = 0;

    f(i,0,m){
        cin >> d;
        a.pb(d);
        if(mpveces[d] > 0 && i - mpult[d] < p){
            flag = 1;
        }

        mpult[d] = i;
        mpveces[d]++;
    }
    if(flag){
        cout << "impossible\n";
        return;
    }


    pair<pll, ll> num;
    priority_queue<pair<pll,ll>, vector<pair<pll,ll>>, greater<pair<pll,ll>>> pq;
    cf(i,1,k){
        pq.push({{mpveces[i], mpult[i]}, i});
    }

    // while(!pq.empty()){
    //     auto [x, y] = pq.top();
    //     pq.pop();
    //     cout << y << " " << x.F << endl;
    // }

    f(i,0,n-m){
        auto [x, y] = pq.top();
        pq.pop();

        if(m+i -x.S < p && x.S != 0){
            cout << "impossible\n";
            return;
        }
        a.pb(y);
        pq.push({{x.F+1, m+i}, y});
    }
    f(i,0,n){
        cout << a[i] << " " ;
    }cout << "\n";

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