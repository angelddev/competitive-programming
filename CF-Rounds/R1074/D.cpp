#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int n, m;
    long long h; 
    cin >> n >> m >> h;
    
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<long long> copy = a;
    vector<int> dirty;
    int index;
    long long sum;
    for(int j=0; j<m;j++){
        cin >> index>> sum;
        int idx =index-1;
        a[idx] += sum;
        dirty.push_back(idx);

        if(a[idx] > h){
            for(int i:dirty){
                a[i] = copy[i];
            }
            dirty.clear(); 
        }
    }

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }
}