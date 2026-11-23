#include <bits/stdc++.h>
using namespace std;
#define endl '\n';


void solve(){

    int k, x;
    cin >> k;
    vector<int> odds, even;



    for(int i=0; i<k; i++){
        cin >> x;
        if(x%2){
            odds.push_back(x);
        }else even.push_back(x);
    }

    if(odds.size()==0){
        cout << 0 << endl;
        return;
    }


    sort(odds.begin(), odds.end());
    sort(even.begin(), even.end());
    long long sum;

    if(odds.size()%2){

        int n=odds.size();
        auto it = odds.begin()+n/2;
        sum = accumulate(even.begin(), even.end(), 0LL);
        sum+= accumulate(it, odds.end(), 0LL);
    }
    else{

        int n=odds.size();
        auto it = odds.begin()+(n+1)/2;
        sum = accumulate(even.begin(), even.end(), 0LL);
        sum+= accumulate(it, odds.end(), 0LL);
    }

    cout << sum << endl;;


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    while(n--)
        solve();
}