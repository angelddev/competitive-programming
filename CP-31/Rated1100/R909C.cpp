#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){

    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a)
        cin >> i;
    
    ll current=a[0];
    ll mx=a[0];



    for(int i=1; i<n; i++){
        if(abs(a[i] %2)!=abs(a[i-1]%2)){
            if(current >0)
                current+=a[i];
            else current=a[i];
        }
        else{
            current=a[i];   
        }
        mx=max(mx, current);
    }
    mx=max(mx, current);

    cout << mx << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}