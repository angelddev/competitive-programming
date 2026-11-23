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



void solve(){

    ll n; cin >> n;

    ll l, r;
    vpl ranges(n);

    vll ends(n);
    vll starts(n);
    
    f(i,0,n){
        cin >> l >> r;
        ends[i]=r;;
        starts[i]=l;
        ranges[i]={l, r};
    }
    sort(all(ends));
    sort(all(starts));

    ll mx = 0;
    f(i,0,n){

        l = ranges[i].F;
        r = ranges[i].S;

        auto it = upper_bound(all(starts), r);
        auto it2 = lower_bound(all(ends), l);

        ll subL=0, subR=0;
        subR = it-starts.begin();
        subR = n-subR;
        subL = (it2-ends.begin());
        mx = max(mx, (n-subL)-subR);
    }
    
    cout << n-mx << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1;
    while(t--){
        solve(); 
    }
}