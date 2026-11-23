#include <bits/stdc++.h>
using namespace std;

void solve(){   
    
    int s, k, j, b, i, escudo=0, cont = 0, sol=0;
    cin >> s >> k; 

    string str;
    cin >> str;
    vector<int> arr;
    for (char c : str)
    arr.push_back(c - '0');


    for(i=0; i<s; i++){
        if (!escudo && arr[i]==1){
            sol++;
            escudo++;
            cont=0;
        }

        if(arr[i]==1&&escudo==1)
            cont=0;

        if(!arr[i])
            cont++;

        if(cont==k-1)
        escudo=0;
    }

    cout << sol << "\n";
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        solve();
    }
}

