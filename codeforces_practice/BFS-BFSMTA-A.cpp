#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


void solve(){

    long long x;
    cin >> x;

    string s = to_string(x);

    int band0=0, band5=0, cont=0;
    for(int i=s.size()-1; i>=0; i--){
        if(band0&&(s[i]=='0'||s[i]=='5')){
            cout << cont -1 << endl;
            return;
        }
        if(band5&&(s[i]=='2'||s[i]=='7')){
            cout << cont-1 << endl;
            return;
        }

        if(s[i]=='0'&& band0==0){
            band0=1;
        }
        if(s[i]=='5'&& band5==0){
            band5=1;
        }
        cont++;
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    while(n--)
        solve();
}