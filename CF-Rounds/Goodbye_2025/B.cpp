#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

void solve(){

    string s;
    cin >> s;

    int cont=0;
    if(s[0]=='u'){
        s[0]='s';
        cont++;
    }

    if(s[s.size()-1]=='u'){
        s[s.size()-1]='s';
        cont++;
    }


    for(int i=1; i<s.size()-1; i++){
        if(s[i]=='u'){
            if(s[i+1]=='u'){
                s[i+1]='s';
                cont++;
            }
        }
    }

    cout << cont << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while(n--){
        solve();
    }
}