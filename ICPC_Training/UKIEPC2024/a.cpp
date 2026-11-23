#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define endl '\n'
#define pb push_back 
#define F first 
#define S second 
using namespace std; 

const ll INF = 1e18; 
const ll MOD = 1e9+7; 

ll n, m, k; 

void solve(){

    string s1, s2; cin >> s1 >> s2;


    map<char, ll> letts;
    vector<ll> temp(30);
    f(i,0,s1.size()){
        temp[s1[i]-'a']++;
    }

    f(i,0,30){
        if(temp[i]>letts[i]) letts[i]=temp[i];
    }
    vector<ll> temp2(30);

    f(i,0,s2.size()){
        temp2[s2[i]-'a']++;
    }
    f(i,0,30){
        if(temp2[i]>letts[i]) letts[i]=temp2[i];
    }

    for(pll e : letts){
        f(i,0,e.S) cout << (char)(e.F+'a');
        
    } cout << "\n";

}

int main(){
    #ifdef DEBUG
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif 

    ll t=1;
    // cin>>t; 
    while(t--){
        solve(); 
    }
}