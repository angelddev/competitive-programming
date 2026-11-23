#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int sol=0;
    for (char x : s){
        if(x!=s[n-1])
            sol++;
    }

    cout << sol << "\n";
}


int main(){
    int n;

    cin >> n;
    while(n--)
        solve();

}