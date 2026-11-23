#include <bits/stdc++.h>
using namespace std;

void solve(){

    int k;
    cin >> k;

    int arr[k];

    for(int i=0; i<k; i++){
        cin >> arr[i];
    }

    int max=0, cont=0;

    for(int i=0; i<k; i++){
        if(arr[i]<max)
            cont++;

        if (max<arr[i]){
            max=arr[i];
        }
    }

    cout << cont << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    while(n--){
        solve();
    }
}