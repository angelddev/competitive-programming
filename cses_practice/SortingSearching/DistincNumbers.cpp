#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll= long long;

void solve(){
    int n; cin >> n;

    set<int> s;
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}