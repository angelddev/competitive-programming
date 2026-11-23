#include <bits/stdc++.h>

#define ll long long 
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
ll st[9000000];


void update(ll node, ll l, ll r, ll pos, ll val){
    
    if(l==r){
        st[node] = val; 
        return;
    }

    ll mid = (l+r)/2;
    if(pos<=mid){
        update(2*node, l, mid, pos, val);
    } else update(2*node+1, mid+1, r, pos, val);

    st[node] = st[2*node]+st[2*node+1];
}

ll query(ll node, ll l, ll r, ll lq, ll rq){

    if(l>=lq&&r<=rq){
        return st[node]; 
    } 
    if(l>rq||r<lq){
        return 0;
    }

    ll mid = (l+r)/2;
    return query(2*node, l, mid, lq, rq)+query(2*node+1, mid+1, r, lq, rq);

}

void solve(){
 
    ll n, m; cin >> n >> m;
    map<string, ll> people;
    map<string, ll> prices;

    string s;
    f(i,0,n){
        cin >> s;
        people[s] = i;
    }    

    ll x;
    f(i,0,m){
        cin >> s >> x;
        prices[s] = x;
    }


    ll q;
    cin >> q;
    ll t, l ,r;
    string p;
    f(i,0,q){
        cin >> t;
        if(t==1){
            cin >> s >> p;
            update(1, 0, n, people[s], prices[p]);
            update(1, 0, n, people[s]+1, -prices[p]);
        } else if(t==2){
            cin >> l >> r >> s;
            if(r<l){
                update(1, 0, n, 0, prices[s]);
            }
            update(1, 0, n, l, prices[s]);
            update(1, 0, n, r+1, -prices[s]);   
        } else {
            cin >> s;
            cout << query(1, 0, n, 0, people[s]) << "\n";
        }
    }





}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

