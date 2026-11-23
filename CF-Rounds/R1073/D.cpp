#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){

    int t; cin >> t;
    string s; cin >> s;
    int countl=count(s.begin(), s.end(), '(');
    vector<int> lefts;
    for(int i=0; i<s.size();i++){
        if(s[i]=='(')
        lefts.push_back(i);
    }

    while(!lefts.empty()){
        int countr=0;
        for(int i=lefts.back(); i<s.size();i++){
            if(s[i]==')'){
                countr++;
            }
            if(countr==countl){
                if(count(s.begin(), s.begin()+countl, ')')>=1){
                cout << countl*2 << endl;
                return;
                }
                else {cout << -1 << endl;
                return;}
            }
        }
        countl--;
        lefts.pop_back();
    }

    cout << -1 << endl;
    
}

int main(){
    ios::sync_with_stdio();
    cin.tie();

    int n; cin >> n;
    while(n--)
        solve();
}