#include<bits/stdc++.h>
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--) 
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;


const ll INF = 1e18; 
const ll mod = 998244353;

void solve(){

    ll n, m; cin >> n >> m;

    vvl correct(n, vll(m, 0));
    ll cont=1;
    f(i,0,n){
        f(j,0,m){
            correct[i][j]=cont++;
        }
    }

    vvl mat (n, vll(m));
    f(i,0,n){
        f(j,0,m){
            cin >> mat[i][j];
        }
    }

    //check if possible
    //rows
    f(i,0,n){
        ll g =(mat[i][0]-1)/m;
        f(j,0,m){
            if((mat[i][j]-1)/m!=g){
                cout << "*\n";
                return;
            }
        }
    }
    f(j,0,m){
        ll g =(mat[0][j]-1)%m;
        f(i,0,n){
            if((mat[i][j]-1)%m!=g){
                cout << "*\n";
                return;
            }
        }
    }

    vll row1, row2, column1, column2;
    f(i,0,n){
        row1.pb(mat[i][0]);
        row2.pb(correct[i][0]);
    }
    f(j,0,m){
        column1.pb(mat[0][j]);
        column2.pb(correct[0][j]);
    }

    ll swapsr=n;
    ll swapsc=m;
    vll visitedr(n, 0), visitedc(m, 0);
    vll prow(n), pcol(m);

    f(i,0,n) prow[i]=(row1[i]-1)/m;
    f(j,0,m) pcol[j]=(column1[j]-1)%m;

    ll cycles=0;
    f(i,0,n){
        if(visitedr[i]==0){
            cycles++;
            ll idx=i;
            while(visitedr[idx]==0){
                visitedr[idx]=1;
                idx=prow[idx];
            }
        }
    }
    swapsr-=cycles;

    cycles=0;
    f(i,0,m){
        if(visitedc[i]==0){
            cycles++;
            ll idx=i;
            while(visitedc[idx]==0){
                visitedc[idx]=1;
                idx=pcol[idx];
            }
        }
    }
    swapsc-=cycles;

    cout << swapsc+swapsr << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}