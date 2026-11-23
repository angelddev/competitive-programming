#include <bits/stdc++.h>
using namespace std;


void solve(){

    int i, j, n;


    cin >> n;
    string so, sc;
    cin >> so >> sc;



    for(i=0;i<n;i++)
    {
        int band=0;
        for(j=0;j<n;j++){

            if(so[i]==sc[j]){
                band=1;
                sc[j]='-';
                break;
            } 

        }
        if (band==0){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

}



int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i=0; i<t;i++)
        solve();

}
