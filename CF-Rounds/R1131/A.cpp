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

    ll n, m; cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;


    vll letts(30);
    f(i,0,s2.size()){
        letts[s2[i]-'a']--;
    }
    f(i,0,s1.size()){
        letts[s1[i]-'a']++;
    }

    ll flag = 0;
    f(i,0,30){
        if(letts[i]!=0&&((char)(i+'a')!='s'&&(char)(i+'a')!='x'&&(char)(i+'a')!='i')){
            cout << "No\n";
            return;
        }
        if((char)(i+'a')=='s'&&letts[i]==1) flag++;
        if((char)(i+'a')=='x'&&letts[i]==1) flag++;
        if((char)(i+'a')=='i'&&letts[i]==1) flag++;
    }

    if(flag==3){
        cout << "Yes\n";
    }
    else cout << "No\n";

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
    cin>>t; 
    while(t--){
        solve(); 
    }
}