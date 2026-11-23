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
vll criba;

void cribbbbb(){

    vll p(1000005, 0);
    cf(i,2,1000002){
        if(p[i]==0){
            for(ll j=i*i; j<=1000002; j+=i){
                p[j]=1;
            }
            criba.pb(i);
        }
    }
}

ll check(ll num){

    if(num==1) return 1;
    for(ll ps:criba){
        if(ps*ps>num) break;
        if(num%ps==0){
            while(num!=1&&num%ps==0){
                num/=ps;
            }
            if(num==1){
                return ps;
            } else return -1;
        }
    }
    return num;
}


void solve(){

    ll n; cin >> n;
    vll nums(n), copy(n);
    f(i,0,n){
        cin >> nums[i];
        copy[i]=nums[i];
    }
    sort(all(copy));
    if(copy==nums){
        cout << "Bob\n"; 
        return;
    }

    


    vll primes;
    f(i,0,n){
        ll k=check(nums[i]);
        if(k!=-1){
            primes.pb(k);
        } else {
            cout << "Alice\n";
            return;
        }
    }

    if(n==1){
        cout << "Bob\n";
      return;
    }

    // f(i,0,n){
    //     cout << primes[i] << " ";
    // } cout << "\n";


    f(i,1,n){
        if(primes[i]<primes[i-1]){
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t; 
    cribbbbb();
    while(t--){
        solve(); 
    }
}