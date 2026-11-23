#include <bits/stdc++.h>
using namespace std;


void solve(){

    string s;
    int k; 
    cin >> k >> s;

    int i;
    for(i=0; i<k;i++){
        if(s[i]=='1'){
            break;
        }
    }

    int mx=0, cont=0, band=0;
    for(int j=i;j<2*k;j++){
        if(j==k){
            j=0;
        }
        if(s[j]=='1'){
            mx=max(mx,cont);
            cont=0;
        }
        else
            cont++;
        if(band==1&&j==i)
        break;
            band=1;
        
    }

    mx=max(mx,cont);


    cout << mx << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;cin >> n; 

    while(n--){
        solve();
    }
}