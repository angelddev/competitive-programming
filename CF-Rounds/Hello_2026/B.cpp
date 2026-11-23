#include <bits/stdc++.h>
using namespace std;

void solve(){

    int k, m; cin >> k >> m;

    vector<int> arr(k);
    for(int i=0; i<k; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    set<int> s(arr.begin(), arr.end());

    vector<int> a(s.begin(), s.end());

    int diff=arr.size()-s.size();

    for(int i=0;i<k-m+1-diff;i++){
        a.pop_back();
    }

    for(int i=0; i<a.back();i++){
        if(i!=a[i]){
            cout << i << "\n";
            return;
        }
    }
    cout << a.back()+1 << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;cin >> n; 

    while(n--){
        solve();
    }
}
