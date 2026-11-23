#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


void solve(){

    int k; cin >> k;
    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 37, 41, 43, 47, 53};


    vector<long long> arr;

    long long t;
    for(int i=0; i<k; i++){
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    int mn=54, nmn;
    for(long long x: arr){
        for(int p: primes){
            if(x%p){
                nmn=p;
                break;
            }
        }
        if(nmn<mn){
            mn=nmn;
        }
    }

    if(mn!=54)
    cout << mn << endl;
    else
    cout << -1 << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    while(n--){
        solve();
    }

}