#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int n, q; cin >> n >> q;

    deque<pair<int, int>> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second=0;
    }

    vector<int> query(q);
    for(int i=0; i<q; i++){
        cin >> query[i];
    }

    
    for(int i=0; i<q;i++){
        int pos=0;
        for(int j=0;j<arr.size();j++){
            pos++;
            if(arr[j].second==1){
                pos--;
                continue;
            }
            if(arr[j].first==query[i]){
                pair<int, int> k = {query[i], 0};
                arr[j].second=1;
                arr.push_front(k);
                break;
            }
        }
        cout << pos << endl;
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
        solve();
}