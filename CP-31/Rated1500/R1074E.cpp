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

    map<ll, vll> deathdistance;
    map<ll, ll> checked;
    set<ll> deadrobot;
    ll n, m, k;
    string s;
    cin >> n >> m >> k;

    vll robots(n), spikes(m);
    f(i,0,n){
        cin >> robots[i];
    }
    f(i,0,m){
        cin >> spikes[i];
    } sort(all(spikes));
    cin >> s;

    f(i,0,n){
        auto it=upper_bound(all(spikes), robots[i]);
        if(it==spikes.end()){}
        else deathdistance[*it-robots[i]].pb(robots[i]);

        auto it2=lower_bound(all(spikes), robots[i]);
        if(it2==spikes.begin()&&spikes[0]==robots[i]){}
        else if(it2==spikes.begin())
            deathdistance[*(it2)-robots[i]].pb(robots[i]);
        else deathdistance[*(--it2)-robots[i]].pb(robots[i]);
    }


    ll curr=0;
    ll ans=n;
    f(i,0,k){
        if(s[i]=='L') curr--;
        else curr++;

        if(checked[curr]==0&&deathdistance[curr].size()!=0){
            vll nodes = deathdistance[curr];
            checked[curr]=1;
            f(i,0,nodes.size()){
                if(deadrobot.find(nodes[i])==deadrobot.end()){
                    deadrobot.insert(nodes[i]);
                    ans--;
                }
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}