#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll= long long;

void solve(){
        
    ll n; cin >> n;
    ll w; cin >> w;

    vector<ll> kids(n);
    for(int i=0; i<n; i++){
        cin >> kids[i];
    }

    int sol=0;
    sort(kids.begin(), kids.end());

    int i=0, j=n-1;
    while(i<=j){
        if(kids[i]+kids[j]<=w){
            i++;j--;
        }else j--;

        sol++;
    }

    cout << sol << endl;

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}