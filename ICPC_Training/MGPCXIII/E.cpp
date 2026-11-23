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
    
    ll n, m, t;
    
    cin >> n >> m >> t;
    vvll mat(n+2, vll(m+2));
    cf(i,1,n){
        cf(j,1,m){
            cin >> mat[i][j];
        }
    }

    vector<pair<pll, pll>> ubs(t+1);
    pll p;
    f(i,0,t){
        cin >> p.F >> p.S;
        ubs[i].F=p;
    }
    f(i,0,t){
        cin >> p.F >> p.S;
        ubs[i].S=p;
    }


    ll sG=0, sA=0;
    f(i,0,t){
        pll u1 = ubs[i].F;
        pll u2 = ubs[i].S;

        set<pll> shared;
        vll dirs = {1, -1, 0};
        for(ll d : dirs){
            for(ll d2 : dirs){

                if(u1.F+d == u2.F+d2 && u1.S==u2.S){
                    shared.insert({u1.F+d, u1.S});
                }
                if(u1.S+d == u2.S+d2 && u1.F==u2.F){
                    shared.insert({u1.F, u1.S+d});
                }
                if(u1.F+d == u2.F && u1.S == u2.S+d2){
                    shared.insert({u1.F+d, u1.S});
                }
                if(u1.F == u2.F+d2 && u1.S+d == u2.S){
                    shared.insert({u1.F, u1.S+d});
                }
            }
        }

        for(ll d : dirs){
            if(shared.count({u1.F+d, u1.S})==0){
                sA+=mat[u1.F+d][u1.S];
                mat[u1.F+d][u1.S]=0;
            }
            if(shared.count({u1.F, u1.S+d})==0){
                sA+=mat[u1.F][u1.S+d];
                mat[u1.F][u1.S+d]=0;
            }
            if(shared.count({u2.F+d, u2.S})==0){
                sG+=mat[u2.F+d][u2.S];
                mat[u2.F+d][u2.S]=0;
            }
            if(shared.count({u2.F, u2.S+d})==0){
                sG+=mat[u2.F][u2.S+d];
                mat[u2.F][u2.S+d]=0;
            }
        }
        shared.clear();
    }

    cout << sA << " " << sG << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}