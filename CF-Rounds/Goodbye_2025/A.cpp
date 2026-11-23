#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve(){

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    if(s[s.size()-1 ]== 'Y' && s[s.size()-2] == s[s.size()-1]){
        cout << "NO" << endl;
    }
    else
    cout << "YES" << endl;
}

int main(){
    int n; cin >> n;
    while(n--){
        solve();
    }
}