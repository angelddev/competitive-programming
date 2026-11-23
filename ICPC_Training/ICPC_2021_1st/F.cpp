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

    ll n; cin >> n;
    ld t; cin >> t;

    cin.ignore();
    ll delay =(ll)(t*1000);

    string s;
    while(getline(cin, s)){

        if(s.length() >= 25 && s.find("-->") != string::npos){
            ll hours=stoll(s.substr(0,2));
            ll minutes=stoll(s.substr(3,2));
            ll seconds=stoll(s.substr(6,2));
            ll milliseconds=stoll(s.substr(9,3));

            ll amount=milliseconds + seconds*1000 + minutes*60*1000 + hours*3600*1000;
            amount+=delay;

            ll h=amount / (3600*1000);
                amount%=(3600*1000);
            ll m=amount/ (60*1000); 
                amount%=(60*1000);
            ll sec= amount /1000; 
                amount%= 1000;
            ll ms = amount;

            string newstring1="";
            if(h < 10) newstring1 += "0";
            newstring1 += to_string(h) + ":";

            if(m < 10) newstring1 += "0";
            newstring1 += to_string(m) + ":";

            if(sec < 10) newstring1 += "0";
            newstring1 += to_string(sec) + ",";

            if(ms < 100) newstring1 += "0";
            if(ms < 10) newstring1 += "0";

            newstring1 += to_string(ms);

            ll hours2=stoll(s.substr(17,2));
            ll minutes2=stoll(s.substr(20,2));
            ll seconds2=stoll(s.substr(23,2));
            ll milliseconds2=stoll(s.substr(26,3));

            ll amount2=milliseconds2 + seconds2*1000 + minutes2*60*1000 + hours2*3600*1000;
            amount2+=delay;

            ll h2 = amount2 / (3600*1000); amount2 %= (3600*1000);
            ll m2 = amount2 / (60*1000); amount2 %= (60*1000);
            ll sec2 = amount2 / 1000; amount2 %= 1000;
            ll ms2 = amount2;

            string newstring2="";
            if(h2 < 10) newstring2 += "0";
            newstring2 += to_string(h2) + ":";

            if(m2 < 10) newstring2 += "0";
            newstring2 += to_string(m2) + ":";

            if(sec2 < 10) newstring2 += "0";
            newstring2 += to_string(sec2) + ",";

            if(ms2 < 100) newstring2 += "0";
            if(ms2 < 10) newstring2 += "0";
            newstring2 += to_string(ms2);

            cout << newstring1 << " --> " << newstring2 << "\n";
        } 
        else {
            cout << s << "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}