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
const int LOG = 30;

void solve(){
    
    ll n, q; cin >> n >> q;
    vll b(n);
    string s;
    cin >> s;
    f(i,0,n){
        b[i]=s[i]-'0';
    }

    vll pat1(n);
    vll pat2(n);

    f(i,0,n){
        if(i%2){
            pat1[i]=0;
            pat2[i]=1;
        } else {
            pat1[i]=1;
            pat2[i]=0;
        }
    }

    vll mis1(n);
    vll mis2(n);
    f(i,0,n){
        if(b[i]!=pat1[i]){
            mis1[i]=0;
        } else mis1[i]=1;
        if(b[i]!=pat2[i]){
            mis2[i]=0;
        } else mis2[i]=1;
    }

    vll pfx1(n);
    vll pfx2(n);
    
    ll am = 0;
    f(i,0,n){
        if(mis1[i]==0&&(i==0||mis1[i-1]==1)){
            am++;
            pfx1[i]=am;
        } else {
            if(i==0){
                pfx1[i]=0;
            } else 
            pfx1[i]=pfx1[i-1];
        }
    }

    am=0;
    f(i,0,n){
        if(mis2[i]==0&&(i==0||mis2[i-1]==1)){
            am++;
            pfx2[i]=am;
        } else {
            if(i==0){
                pfx2[i]=0;
            } else 
            pfx2[i]=pfx2[i-1];
        }
    }

    ll l, r, k;
    f(i,0,q){
        cin >> l >> r >> k;
        l--, r--;
        ll rest1;
        if(l==0){
            rest1 = 0;
        } else rest1 = pfx1[l-1];
        ll rest2;
        if(l==0){
            rest2 = 0;
        } else rest2 = pfx2[l-1];

        ll ac1=pfx1[r]-rest1;
        if(l>0&&mis1[l]==0 && mis1[l-1]==0) ac1++;

        ll ac2=pfx2[r]-rest2;
        if(l>0 && mis2[l]==0 && mis2[l-1]==0) ac2++;
        if(min(ac1, ac2)<=k){
            cout << "YES\n";
        } else cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}