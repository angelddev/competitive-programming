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
ll cnt=1;
map<ll, ll> divisors;

void check(ll num){
    for(ll i=2; i<=sqrt(num); i++){
        if(num%i==0){
            ll t=0;
            while(num%i==0){
                t++;
                cnt++;
                num/=i;
            }
            divisors[i]=t;
        }
    }

    if(num>1){
        cnt++;
        divisors[num]=1;
    }
}

void solve(){

    ll n; cin >> n;

    if(n==1){
        cout << "N\n";
        return;
    }
    check(n);

    if(divisors.size()==1&&divisors.begin()->S%2==1){
        cout << "Y\n";
        return;
    } 

    ll bnd=0;
    if(divisors.size()==2){
        for(auto it=divisors.begin(); it!=divisors.end(); ++it){
            //cout << it->F << " " << it->S << "\n";
            if(it->S>1){
                bnd++;
            }
        }
        if(bnd>=1){
        cout << "N\n";
        return;
        }
    } else {
        cout << "N\n";
        return;
    }
    cout << "Y\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}