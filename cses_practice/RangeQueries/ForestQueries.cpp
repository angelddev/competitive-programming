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

    ll n, q; cin >> n >> q;
    vector<vector<char>> forest(n, vector<char>(n));


    f(i,0,n){
        f(j,0,n){
            cin >> forest[i][j];
        }
    }

    vvll pfx(n, vll(n));
    pfx[0][0]=forest[0][0]=='*';

    f(i,1,n){
        pfx[0][i]=pfx[0][i-1]+(forest[0][i]=='*');
    }

    f(i,1,n){
        pfx[i][0]=pfx[i-1][0]+(forest[i][0]=='*');
    }

    f(i,1,n){
        f(j,1,n){
            pfx[i][j]=(pfx[i-1][j]+pfx[i][j-1]+(forest[i][j]=='*'))-pfx[i-1][j-1];
        }
    }

    //f(i,0,n){
    //    f(j,0,n){
    //        cout << pfx[i][j] << " ";
    //    } cout << "\n";
   // }


    ll y1, y2, x1, x2, ry, rx;
    f(i,0,q){
        
        cin >> y1 >> x1 >> y2 >> x2;

        ll ans=pfx[y2-1][x2-1];
        //cout << ans << "T"<< "\n";
        if(y1!=1)
            ans=ans-pfx[y1-2][x2-1];
        if(x1!=1)
            ans=ans-pfx[y2-1][x1-2];
        if(x1!=1&&y1!=1)
            ans=ans+pfx[y1-2][x1-2];

        cout << ans << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}