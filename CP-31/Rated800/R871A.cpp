#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){

    int n; cin >> n;
    vector<int> a(n);
    for(int &i:a)
        cin >> i;

    int longest=0;
    int mx=0;
    for(int i=0; i<n; i++){
        if(a[i]==0)
        longest++;
        else{
            mx=max(longest,mx);
            longest=0;
        }
    }

    mx=max(longest,mx);

    cout << mx << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while(t--){
        solve();
    }
}