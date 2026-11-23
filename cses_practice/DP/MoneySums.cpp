#include <bits/stdc++.h>
using namespace std;

#define all(a) begin(a), end(a)
#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvl vector<vll>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define pb push_back
#define F first
#define S second
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define INF 1e18

void solve() {
    
    ll n; cin >> n;
    vll coins(n);
    f(i,0,n){
        cin >> coins[i];
    }
    vll ans(1000005, 0);
    ans[0]=1;
    ll mxSum=0;
    f(i,0,n){
        mxSum+=coins[i];
        for(ll j=mxSum; j>=0; j--){
            if(ans[j]==1)
                ans[j+coins[i]]=1;
        }
    }

    ll cont=0;
    cf(i,1,mxSum){
        if(ans[i]==1) cont++;
    } cout << cont << "\n";
    cf(i,1,mxSum){
        if(ans[i]==1) cout << i << " ";
    } cout << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //ll t; cin >> t; while(t--)
    solve();
}