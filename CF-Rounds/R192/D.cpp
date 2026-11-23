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

    string s1, s2; cin >> s1 >> s2;


    vll p1, p2;

    p1.pb(0);
    p2.pb(0);

    f(i,0,s1.size()){
        p1.pb(((s1[i]-'0')+p1.back())%10);
    }
    f(i,0,s2.size()){
        p2.pb(((s2[i]-'0')+p2.back())%10);
    }
    
    if(p2.back()!=p1.back()){
        cout << -1 << "\n";
        return;
    }
    vll best(p2.size()+2, 0);
    vll prevbest(p2.size()+2, 0);
    for(int i = 1; i<p1.size(); i++){
        for(int j = 1; j < p2.size(); j++){
            //cout << "p1: " << p1[i] << " p2:" << p2[j] << " ";
            if(p1[i]==p2[j]){
                best[j]=prevbest[j-1]+1;
            } else best[j]=max(prevbest[j], best[j-1]);
            //cout << best[j] << "\n";
        }
        prevbest=best;
    }

    cout << best[p2.size()-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t; cin >> t;
    while(t--){
        solve(); 
    }
}