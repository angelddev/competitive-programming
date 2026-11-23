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
    vll visited;

    void cribb(ll n){
        f(i,2,n){
            if(visited[i]==0){
                for(ll j=i*i; j<=n; j+=i){
                    visited[j]=1;
                }
            }
        }
    }

    void solve(){
        ll n; cin >> n;
        visited.assign(n+15, 0);
        cribb(n+2);

        if(n<=2){
            cout << 1 << "\n";
        } else cout << 2 << "\n";
        
        cf(i,2,n+1){
            cout << visited[i]+1 << " ";
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