#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){

    int t; cin >> t;
    vector<int> arr(t);
    for(int i=0; i<t;i++){
        cin >> arr[i];
    }
    int longest=0, temp=0;
    for(int i=0; i<t-1;i++){
        if(arr[i+1]==arr[i]+1){
            temp+=1;
            if(temp>longest){
               longest=temp;
            }
        }
        else temp=0;
    }

    cout<< longest-1 << endl;
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while(n--){
        solve();
    }
}