#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 

void solve(){
    
    ll n; cin >> n;
    vector<pair<pll, ll>> people(n);
    f(i,0,n){
        cin >> people[i].first.first;
        cin >> people[i].first.second;
        people[i].second=i;
    }
    sort(people.begin(), people.end());
    
    vll ans(n);
    priority_queue<pll, vpl, greater<pll>> pq;

    pq.push({people[0].first.second, 1});
    ans[people[0].second] = 1;

    ll nxt_room=2;
    f(i,1,n){
        if(people[i].first.first>pq.top().first){
            ll reuse = pq.top().second;
            ans[people[i].second]=reuse;
            pq.pop();
            pq.push({people[i].first.second, reuse});
        } else{
            pq.push({people[i].first.second, nxt_room});
            ans[people[i].second]=nxt_room;
            nxt_room++;
        }   
    }

    cout << nxt_room-1 << "\n";
    f(i,0,n) cout << ans[i] << " ";
    cout << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}