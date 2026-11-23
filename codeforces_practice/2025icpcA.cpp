#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



int main(){
    vector<int> arr(3);

    cin >>arr[0] >> arr[1] >> arr[2];

    sort(arr.begin(), arr.end());


    if(arr[2]-arr[0]>=10){
        cout << "check again" << endl;
    }

    else cout << "final "<< arr[1] << endl;
    
}