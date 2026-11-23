#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int n; string s; cin >> n >> s;
    set<char> v;
    int sum=0;
    for(int i=0; i<n; i++){
        if(v.find(s[i])==v.end()){
            v.insert(s[i]);
            sum+=n-i;
        }
    }
    cout << sum << endl;

} 


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while(n--){
        solve();
    }
        
}