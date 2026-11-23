#include<bits/stdc++.h>
 
#define ll long long 
#define all(a) begin(a), end(a)
#define pll pair<ll, ll> 
#define vll vector<ll>
#define vvl vector<vll>
#define vpl vector<pll> 
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i<e; i--)
#define MOD(x) ((((x)%mod) + mod)%mod)
#define F first
#define S second
#define pb push_back 
using namespace std; 
typedef long double ld;
 
const ll INF = 1e18; 
const ll mod = 1e9 + 7;
 
ll t, n, m, k, a, b, tot; 
 
void solve(){
 
    ll n, mnGrade; cin >> n >> mnGrade;

    vll scores(n);
    ll total=0;
    f(i,0,n){
        cin >> scores[i];
        total+=scores[i];
    }

    ll mnCnt=INF;
    for(ll mask=0; mask<(1<<n); mask++){
        ll temp=0;
        ll cnt=0; 
        f(i,0,n){
            if(mask&(1<<i)){
                temp+=scores[i];
                cnt++;
            }
        }
        if((temp)*100>=mnGrade*total){
            mnCnt=min(cnt, mnCnt);
        }
    }

    vvl mnScores;
    for(ll mask=0; mask<(1<<n); mask++){
        ll temp=0;
        ll cnt=0; 
        vll positions;
        f(i,0,n){
            if(mask&(1<<i)){
                temp+=scores[i];
                cnt++;
                positions.pb(i+1);
            }
        }

        if(temp*100>=mnGrade*total&&cnt==mnCnt){
            positions.pb((temp*100)/total);
            mnScores.pb(positions);
        }
    }

    ll sz=mnScores.size();
    cout << mnCnt << " " <<  sz << "\n";
    f(i,0,sz){
        ll sz2=mnScores[i].size();
        cout << mnScores[i][sz2-1];
        f(j,0,sz2-1){
            cout <<" "<< mnScores[i][j];
        }
        
        cout << "\n";
    }

}
 
int main(){
    ll t=1; 
    while(t--){
        solve(); 
    }
}