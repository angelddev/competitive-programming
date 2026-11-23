#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
    cin >> arr[i];
    }


    int last=arr[n-1];
    int i=n-1;

    while(i>=0&&arr[i]==last){
        i--;
    }

    int sol=0;
    while(i>=0){
        sol++;
        int curr=(n-1)-i;

        i=i-curr;

        while(i>=0&&arr[i]==last){
            i--;
        }
    }

    cout << sol << '\n';
}

    


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}