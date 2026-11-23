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

vector<string> mat;
vector<string> cur;
ll n, m;


void flip(){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j<m/2; j++)
            swap(cur[i][j], cur[i][m-1-j]);
    } 
}

ll rotate(ll flag){
        
    vector<string> temp = cur;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = cur[n-1-i][m-1-j];
        }
    }


    return (temp==mat);

}

void rotate(){

    vector<string> temp = cur;
    
    for(int k = 0; k < n/2; k++){
        
        string last = temp[k];

        for(int i = k; i < n-k-1; i++){
            temp[k][i] = cur[i][n-1-k];
        }
        for(int i = k; i < n-k-1; i++){
            temp[i][n-1-k] = cur[n-1-k][n-1-k-(i-k)];
        }
        for(int i = 0; i < n-1-2*k; i++){
            temp[n-1-k][n-1-k-i] = cur[n-1-k-i][k];
        }
        for(int i = 0; i < n-1-2*k; i++){
            temp[n-1-k-i][k] = last[i+k];
        }        
    }

    cur = temp;
    

}

void solve(){

    cin >> n >> m;
    string s;
    f(i,0,n){
        cin >> s;
        mat.pb(s);
    }
    cur = mat;

    ll ans = 1;
    if(m!=n){
        ans+=rotate(1);
        flip();
        ans+=(cur==mat);
        ans+=rotate(1);
        cout << ans << "\n";
        return;
    }

    n=m;
    m=n;
    ll state = 2;

    while(state!=9){
        rotate();
        if(state==5){
            flip();
        }
        ans+=(cur==mat);
        state++;
    }
    
    cout << ans << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

