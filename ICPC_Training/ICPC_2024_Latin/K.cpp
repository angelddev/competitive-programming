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

ll is_vocal(char c){
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y')
        return 1;
    return 0;
}

void solve(){

    ll n; cin >> n;
    string s;
    vector<string> words;
    f(i,0,n){
        cin >> s;
        string ns="";
        f(i,0,min((ll)3, (ll)s.size())){
            ns+=s[i];
        }
        words.pb(ns);
    }

    if(n<=2){
        cout << words.size()<< "\n";
        return;
    }

    

    ll l=0, r=2, ans=words.size();
    while(r-l==2){
        ll cr=r, cl=l;
        if(is_vocal(words[cr][0])){
            //cout << "A";
            r=min((ll)words.size()-1, r+3);
            l+=3;
            continue;
        }
        
        if(is_vocal(words[cr-1][0])){
            //cout << "B";
            r=min((ll)words.size()-1, r+2);
            l+=2;
            continue;
        }
        if(is_vocal(words[cl][0])){   
            //cout << "C";
            r=min((ll)words.size()-1, r+1);
            l++;
            continue;
        }
        if(words[cr-1].size()>1&&is_vocal(words[cr-1][1])){   
            //cout << "D";
            r=min((ll)words.size()-1, r+2);
            l+=2;
            ans++;
            continue;
        }
        if(words[cr-2].size()>1&&is_vocal(words[cr-2][1])){   
            //cout << "E";
            r=min((ll)words.size()-1, r+1);
            l++;
            ans++;
            continue;
        }
        if(words[cr-2].size()>2&&is_vocal(words[cr-2][2])){   
            //cout << "F";
            r=min((ll)words.size()-1, r+1);
            l++;
            ans+=2;
            continue;
        }
        cout << "*\n"; return;
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1; 
    while(t--){
        solve(); 
    }
}