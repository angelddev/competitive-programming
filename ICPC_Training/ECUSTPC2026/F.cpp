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

ll x1, ya, x2, yb;
char dir;  

void solve(){
    cin>>x1>>ya>>dir>>x2>>yb; 
    x2-=x1; 
    yb-=ya;

    if(dir == 'E'){
        if(yb==0 && x2>=0) cout<<"0\n";
        else if(x2>=0 && yb<0) cout<<"1\n"; 
        else if(yb<=0) cout<<"2\n";
        else cout<<"3\n";
    }
    else if(dir == 'S'){
        if(x2==0 && yb<=0) cout<<"0\n";
        else if(yb<=0 && x2<0) cout<<"1\n"; 
        else if(x2<=0) cout<<"2\n";
        else cout<<"3\n";
    }
    else if(dir == 'W'){
        if(yb==0 && x2<=0) cout<<"0\n";
        else if(x2<=0 && yb>0) cout<<"1\n"; 
        else if(yb>=0) cout<<"2\n";
        else cout<<"3\n";
    }
    else{
        if(x2==0 && yb>=0) cout<<"0\n";
        else if(yb>=0 && x2>0) cout<<"1\n"; 
        else if(x2>=0) cout<<"2\n";
        else cout<<"3\n";
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