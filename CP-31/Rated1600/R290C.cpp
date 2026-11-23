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
vvll adj;
vll visited;
vll ans;
vll indegree;
vector<string> words;
ll flag=0;

void dfs(ll node){
    if(flag) return;
    visited[node]=1;
    for(auto e: adj[node]){
        if(visited[e]==1){
            flag=1;
            return;
        } else {
            if(!visited[e]) dfs(e);
        }
    }
    visited[node]=2;
    ans.pb(node);
}



void solve(){

    ll n; cin >> n;
    string s;
    adj.assign(30, vll());
    visited.assign(30, 0);
    indegree.assign(30, 0);
    f(i,0,n){
        cin >> s;
        words.pb(s);
    }   

    if(n==1){
        f(i,0,26){
            cout << (char)('a'+i);
        }
        return;
    }


    f(i,1,n){  
        if(words[i-1].size() > words[i].size() && 
        words[i-1].substr(0, words[i].size()) == words[i]){
            cout << "Impossible\n";
            return;
        }
        ll j=0;
        while(j<min(words[i-1].size(), words[i].size())&&words[i-1][j]==words[i][j]){
            j++;
        }
        if(j < min(words[i-1].size(), words[i].size())){
            adj[words[i-1][j]-'a'].pb(words[i][j]-'a');
            indegree[words[i][j]-'a']++;
        }
    }

    f(i,0,26){
        if(!visited[i]) dfs(i);
        if(flag) break;
    }

    if(flag){
        cout << "Impossible\n"; return;
    }

    reverse(all(ans));
    f(i,0,ans.size()){
        cout << (char)('a'+ans[i]);
    } cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}