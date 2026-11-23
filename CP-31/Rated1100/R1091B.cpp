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

        ll n, k; cin >> n >> k;
        vll nums(n+1);
        f(i,0,n){
            cin >> nums[i];
        }

        ll x;
        cin >> x;
        x--;
        ll std = nums[x];

        ll lstr=-1;
        f(i, x, n){
            if(std^nums[i]) lstr=i;
        }

        ll lstl=-1;
        f(i, 0, x){
            if(std^nums[i]){ lstl=i; break;};
        }

        if(lstr==-1&&lstl==-1) {
            cout << 0 << "\n";
            return;
        }


        ll mxl=0, mxr=0;
        if(lstr==-1){
            ll act=std;
            mxl=0;
            cf(i,lstl,x){
                if(act^nums[i]){
                    act=act^1;
                    mxl++;
                }
            }

            cout << mxl << "\n";
            return;
        }

        if(lstl==-1){

            ll act=std;
            mxl=0;
            cf(i,x,lstr){
                if(act^nums[i]){
                    act=act^1;
                    mxr++;
                }
            }
            mxr++;
            cout << mxr << "\n";
            return;
        }

        ll act=std;
            mxl=0;
            cf(i,lstl,x){
                if(act^nums[i]){
                    act=act^1;
                    mxl++;
                }
            }
        act=std;
            mxr=0;
            cf(i,x,lstr){
                if(act^nums[i]){
                    act=act^1;
                mxr++;
            }
        }

        mxr++;
        cout << max(mxl, mxr) << "\n";
    }

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 

        ll t; cin >> t; 
        while(t--){
            solve(); 
        }
    }