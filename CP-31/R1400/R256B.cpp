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

bool automaton(string st1, string st2){
    ll j=0;
    f(i,0,st1.size()){
        if(st1[i]==st2[j]) j++;
        if(j==st2.size()){
            return true;
        }
    }
    return false;
}

bool automaton2(string st1, string st2){
    vll chars1(27, 0);
    vll chars2(27, 0);
    f(i,0,st1.size()){
        chars1[st1[i]-'a']++;
    }

    f(i,0,st2.size()){
        chars2[st2[i]-'a']++;
    }
    f(i,0,27){
        if(chars2[i]>chars1[i])
        return false;
    }
    return true;
}

bool arrey(string st1, string st2){
    sort(all(st1));
    sort(all(st2));

    if(st1!=st2){
        return false;
    }
    return true;
}

void solve(){

    string s1, s2;
    cin >> s1 >> s2;
    if(s1.size()<s2.size()){
        cout << "need tree\n";
        return;
    }

    if(s1.size()==s2.size()){
        if(arrey(s1, s2)==true){
            cout << "array\n";
            return;
        }
        cout << "need tree\n";
            return;
    }
    
    if(automaton(s1, s2)==true){
        cout << "automaton\n";
        return;
    }

    if(automaton2(s1,s2)==true){
        cout << "both\n";
        return;
    }

    cout << "need tree\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    //ll t; cin >> t;
    //while(t--)
        solve();
}