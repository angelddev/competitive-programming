#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


void solve(){
    long long k, x, sum=0;
    cin >> k;

    long long p=0;

    for(int i=0; i<k; i++){
        cin >> x;
        sum+=x;
        if(x==0)
            p++;
    }

    cout << min(k-p, sum-(k-1)) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    while(n--)
        solve();
}