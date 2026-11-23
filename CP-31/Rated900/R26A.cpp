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
    vll cribba;
    vll visited;

    void cribb(){
        f(i,2,3002){
            if(visited[i]==0){
                cribba.pb(i);
                for(ll j=i*i; j<=3002; j+=i){
                    visited[j]=1;
                }
            }
        }
    }

    bool is_almost(ll num){

        ll cnt=0;
        for(ll i = 2; i*i<=num; i++){
            if(num%i==0){
                while(num % i == 0){
                    num /= i;
                }
                cnt++;
                if(cnt>2) return 0;   
            }
        }

        if(num>1) cnt++;
        return cnt==2;

    }

    void solve(){
        ll n; cin >> n;
        visited.assign(3002, 0);
        cribb();

        ll ans=0;
        
        
        cf(i,6,n){
            if(is_almost(i)==1){
                ans++;
            }
        }

        cout << ans << "\n";
    }




    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 

        ll t=1; 
        while(t--){
            solve(); 
        }
    }