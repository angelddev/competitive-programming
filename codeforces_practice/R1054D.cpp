#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    

    if(n<=3||count(s.begin(), s.end(), 'a')==n||count(s.begin(), s.end(), 'b')==n){
        cout << 0 << endl;
        return;
    }

    char lastChar=s[n-1], otherChar;
    if(lastChar=='a'){
        otherChar='b';
    } else otherChar='a';

    ll swaps=0, allr=0, allc=0;
    for(int i=n-1; i>=0; i--){
        if(s[i]!=lastChar)
            swaps++;
        else allr+=swaps;
    }

    ll k=count(s.begin(),s.end(), otherChar);
    ll L=(n-k)/ 2;
    ll R=L + k -1;
    swaps=0;
    for(int i=R; i<n; i++){
        if(s[i]==lastChar) 
            swaps++;
        else allc+=swaps;
    }

    swaps=0;
    for(int i=L-1; i>=0; i--){
        if(s[i]==lastChar) 
            swaps++;
        else allc+=swaps;
    }


    cout << min(allc, allr) << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    while(n--){
        solve();
    }
}