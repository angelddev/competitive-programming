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


void solve(){

    ll n; cin >> n;

    vll arr(n);
    f(i,0,n){
        cin >> arr[i];
    }


    ll last = -1, ans = 0, a = 0, b = 0;
    f(i,0,n){
        if(arr[i] == 1){
            if(last==-1) {}
            else {
                if(i-last+1>ans){
                    a = last, b = i;
                    ans = i-last+1;
                } 
            }
            last = i;
        }
        else if(arr[i]==-1){
            if(last==-1) last = i;
            else {
                if(i-last+1>ans){
                    a = last, b = i;
                    ans = i-last+1;
                } 
            }
        } 
    }

    if(ans == 0){
        f(i,0,n){
        if(arr[i]==-1)
        
            arr[i] = 1;
        
        }
    }
    else 
    f(i,0,n){
        if(arr[i]==-1)
        if(a==i||b==i){
            arr[i] = 1;
        } else arr[i] = 0;
    }
    
    f(i,0,n){
        cout << arr [i] << " ";
    } cout << "\n";
    


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; cin >> t;
    while(t--){
        solve(); 
    }
}

