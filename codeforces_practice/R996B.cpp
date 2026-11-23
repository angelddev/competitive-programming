#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


void solve(){

    int k; cin >> k;

    vector<long long> a(k), b(k);
    for(int i=0; i<k; i++){
        cin >> a[i];
    }
    for(int i=0; i<k; i++){
        cin >> b[i];
    }

    int index=-1;
    for(int i=0; i<k; i++){
        if(b[i]>a[i]){
            if(index!=-1){
            cout << "no" << endl;
            return;
        }
            index=i;
        }
    }

    if(index==-1){
        cout << "yes" << endl;
        return;
    }
    int diff= b[index]-a[index];
    for(int i=0; i<k; i++){
        if(i==index)
        continue;
        if(b[i]>(a[i]-diff)){
            cout << "NO" << endl;
            return;
        }    
    }
    cout << "YES" << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while(n--)
        solve();
}