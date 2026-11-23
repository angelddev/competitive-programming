#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int escudo=0, sol=0;
    for(int i= 0; i< n; i++){
        if(s[i]=='1'){
            escudo=k;
        }
        else {
            if(escudo<=0)
                sol++;
            escudo--;
        }
    }

    cout << sol << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    while(n--)
        solve();
}