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
vvll factors;
vll v;

void criba(){
    
    v.assign(1000008, 0);
    v[1]=1;
    for(ll i=2; i<=1000007; i++){
        if(v[i]!=0) continue;
        v[i]=i;
        for(ll j=i*i; j<=1000007; j+=i){
            if(v[j]==0)
            v[j]=i;
        }
    }
}

void get_factors(ll n){

    vll vec;
    if(n==1){
        vec.pb(1);
        factors.pb(vec);
        return;
    }
    while(n!=1){
        vec.pb(v[n]);
        n/=v[n];
    }
    factors.pb(vec);
}

// bool cmp(vll &a, vll &b){

//     if(a.size()>=b.size()){
//         for(ll i=0; i<b.size(); i++){
//             if(a[i]==b[i]) continue;
//             if(a[i]>b[i]) return false;
//             return true;
//         } return false;
//     }
//     if(b.size()>=a.size()){
//         for(ll i=0; i<a.size(); i++){
//             if(a[i]==b[i]) continue;
//             if(a[i]>b[i]) return false;
//             return true;
//         } return true;
//     }
//     return true;
// }

void solve(){

    ll n, q; cin >> n >> q;

    ll x;
    cf(i,1,n){
        get_factors(i);
    }

    // f(i,0,n){
    //     f(j,0,factors[i].size()){
    //         cout << factors[i][j] << " ";
    //     } cout << "\n";
    // }

    sort(all(factors));

    f(i,0,q){
        ll num=1;
        cin >> x;
        f(j,0,factors[x-1].size()){
            num*=factors[x-1][j];
        }
        cout << num << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    criba();
    ll t=1; 
    while(t--){
        solve(); 
    }
}