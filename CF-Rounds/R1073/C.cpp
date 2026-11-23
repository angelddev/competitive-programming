#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){

    int t; cin >> t;
    string s; cin >> s;

    string copy=s;
    sort(copy.begin(), copy.end());
    if(copy==s){
        cout << "Bob" << endl;
        return;
    }
    vector<int> solution;
    int Z= count(s.begin(), s.end(), '0');
    for(int i=0; i<Z; i++){
        if(s[i]=='1'){
            solution.push_back(i+1);
        }
    }

    for(int i=Z; i<t; i++){
        if(s[i]=='0'){
            solution.push_back(i+1);
        }
    }

    cout << "Alice" << endl << solution.size() << endl;
    for(int x : solution){
        cout << x << " ";
    }
    cout << endl;
    
}

int main(){
    ios::sync_with_stdio();
    cin.tie();

    int n; cin >> n;
    while(n--)
        solve();
}