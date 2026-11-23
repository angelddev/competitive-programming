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

vll primes;
void sieve(){

    vll vis(1e6+6, 0);
    cf(i,2,1e6){
        if(!vis[i]){
            primes.pb(i);
            for(ll j = i; j <= 1e6; j+=i){
                vis[j]=1;
            }
        }
    }

}

void solve(){
 
    string s; cin >> s;

    ll n = min(10ll, (ll)(s.size()));
    string temp;
    f(i,0,n){
        temp.pb(s[i]);
    }
    reverse(all(temp));
    
    ll act = 0;
    ll num = 0;
    f(i,0,n){
        num += ((ll)(temp[i]-'0'))*pow(10, act++);
    }

    sieve();
    vpl ans;

    for(ll pr : primes){
        ll tmp = 0;
        if(pr>num) break;
        if(num%pr==0){
            while(num!=0&&num%pr==0){
                tmp++;
                num/=pr;
            }
        }
        if(tmp>0)
        ans.pb({pr, tmp});
    }

    if(num>1) ans.pb({num, 1});
    ll rest = s.size()-n;
    ll flag2=0, flag5=0;
    if(rest>0){
        for(pll &e : ans){
            if(e.F==2){
                flag2=1;
                e.S+=rest;
            } 
            if(e.F==5){
                flag5=1;
                e.S+=rest;
            } 
        }
    } else{
        flag2=1, flag5=1;
    }

    if(!flag2){
        ans.pb({2, rest});
    }
    if(!flag5){
        ans.pb({5, rest});
    }

    
    cout << ans.size() << "\n";
    for(pll e : ans){
        cout << e.F << " " << e.S << "\n";    
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t = 1; //cin >> t;
    while(t--){
        solve(); 
    }
}

