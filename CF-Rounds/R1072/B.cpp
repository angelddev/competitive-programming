#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
void solve(){
    long long s, k, m, cnt, rem, start, ans;
    cin >> s >> k >> m;

    cnt = m/k;
    rem= m%k;
    start =(cnt % 2 == 0)?s :min(s, k);
    ans =max(0LL, start -rem);
    cout << ans<< endl;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n; 
    cin >>n;
 
    while(n--)
        solve();
}