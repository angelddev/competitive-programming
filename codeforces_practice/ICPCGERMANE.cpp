#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){

    string s; cin >> s; 
    for(char &c: s)
        c=tolower(c);

    cout << s << endl;

    for(int i=0; i<s.size()-1; i++){
        if(s[i]=='s'&&s[i+1]==s[i]){
            string copy=s;
            copy[i]='B';
            copy.erase(i+1,1);
            cout << copy << endl;
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
        solve();
}