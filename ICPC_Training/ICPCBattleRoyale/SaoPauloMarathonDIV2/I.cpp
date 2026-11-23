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

set<string> r;
int L=11; 

void rec(string s, int p, string a){

    int pos=a.length();

    if(pos==L){
        if(p==s.size())
            r.insert(a); 
        return;
    }

    if(L-pos < s.size()-p)
        return;

    if(pos==0){
        if(p<s.size()&&s[p]=='1')
            rec(s, p+1, a+"1");
        rec(s, p, a+"1");
    } 
    else if(pos==1){
        if(p<s.size()&&s[p]!='0')
            rec(s, p+1, a+s[p]);
        rec(s, p, a+"1");
        rec(s, p, a+"9");
    }
    else if(pos==2){
        if(p<s.size()&&s[p]=='9')
            rec(s, p+1, a+"9");
        rec(s, p, a+"9");
    } 
    else{
        if(p<s.size())
            rec(s, p+1, a+s[p]);
        rec(s, p, a+"1"); 
        rec(s, p, a+"9");
    }
}

void solve(){

    string s; cin>>s;

    rec(s, 0, "");

    cout << r.size() << "\n";

    for(auto x:r)
        cout << x << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll t=1;
    while(t--){
        solve(); 
    }
}