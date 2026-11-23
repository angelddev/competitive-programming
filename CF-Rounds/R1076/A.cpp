#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    int n, s, x;

    cin >> n >> s >> x;

    int sum=0;
    vector<int> a(n);
    for(int &i : a){
        cin >> i;
        sum+=i;
    }


    if(sum>s){
        cout << "NO" << endl;
        return;
    }

    int left=s-sum;
    if(left%x==0){
        cout << "YES" << endl;
    } else
    cout << "NO " << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
    
}