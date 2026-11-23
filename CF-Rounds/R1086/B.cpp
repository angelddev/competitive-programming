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

    ll n, k, p, m; cin >> n >> k >> p >> m;
    vpl nums(n);
    f(i,0,n) {
        cin >> nums[i].first;
        if(i==p-1){
            nums[i].second=1;
        } else{
            nums[i].second=0;
        }
    }

    if(n==k){
        cout << m/nums[p-1].first << "\n";
        return;
    }
    if(nums[p-1].first>m){
        cout << 0 << "\n";
        return;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    queue<pll> end;
    ll ans=0;

    if (k>=p){
    m -= nums[p-1].first;
    ans++;
    deque<pll> deck;
    for (ll i = 0; i<n;++i) if (i!=p-1) deck.push_back(nums[i]);

    for (ll i =0; i<k&&!deck.empty(); ++i) {
        pq.push(deck.front().first);
        deck.pop_front();
    }
    while (!deck.empty()) { end.push(deck.front()); deck.pop_front(); }
    end.push({ nums[p-1].first, 1 });
    }  else {
        f(i,0,k){
            pq.push(nums[i].first);
        }
        f(i,k,n){
            end.push(nums[i]);
        }
    }

    while (!pq.empty() &&m>=pq.top()) {
        ll s=pq.top();
        m-=pq.top();
        pq.pop();
        end.push({s,0});

        if(end.front().second==1){
            if(m>=end.front().first){
                ll x=end.front().first;
                m-=end.front().first;
                ans++;
                end.pop();
                end.push({x,1});
                pq.push(end.front().first);
                end.pop();
            } else {
                cout << ans << "\n";
                return;
            }
        } else {
            pq.push(end.front().first);
            end.pop();
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    ll t; cin >> t;
    while(t--)
        solve();
}