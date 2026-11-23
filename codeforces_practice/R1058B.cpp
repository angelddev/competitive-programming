#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int k; cin >> k;
    vector<long long> b(k);

    for(int i=0; i<k; i++){
        cin >> b[i];
    }
    vector<int> a(k);
    a[0] = 1;
    int next_val = 2;
    for(int j=1; j<k; j++){
        long long diff= b[j]-b[j-1];
        int prev_pos = j+1-diff; 

        if(prev_pos == 0){
            a[j] = next_val++;
        }
        else {
            a[j] = a[prev_pos - 1];
        }
    }
    for(int i=0; i<k; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}