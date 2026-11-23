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

    tuple<ll, ll, ll> extendedGcd(ll a, ll b){
        if(b==0){
            if(a>0) return {a, 1, 0};
            else return {-a, -1, 0};
        }
        else {
            auto[d, x, y] = extendedGcd(b, a%b);
            return{d, y, x-y*(a/b)};
        }
    }


    ll modularInverse(ll a, ll m){
        auto[d, x, y] = extendedGcd(a, m);

        if(d!=1) return -1;
        if(x<0) return x+=m;
        return x;
    }

    void solve(){

        ll n; cin >> n;

        ll gauss = n*(n+1)/2;

        if(gauss%2){
            cout << "0\n";
            return;
        }

        vll dp(200005, 0);
        dp[0] = 1;
        cf(i, 1, n){
            for(ll j = gauss/2; j>=i; j--){
                dp[j]+= dp[j-i];
                dp[j]%=MOD;
            }
        }

        cout << (dp[gauss/2]*modularInverse(2, MOD))%MOD << "\n";

    }

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 

        ll t = 1; //cin >> t;
        while(t--){
            solve(); 
        }
    }

