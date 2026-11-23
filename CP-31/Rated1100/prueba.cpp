#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    string s; cin >> s;
    int n=s.length();
    set<int> val;

    for(int i=0; i<n; i++){
        val.insert(s[i]); 
    }
    int k=val.size(); 
    for(int i=k; i<n; i++){
        if(s[i] != s[i-k]){
            cout<<"NO\n"; 
            return; 
        }
    }
    cout<<"YES\n";
}

    


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}