#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    long long k; 
    string s;
    cin >> k >> s;

    int sum=0, sw=0;
    for(int i=0; i<k; i++){
        if(s[i]=='.'&&sw==0){
            sw=1;
            if(i+1>=k){
                sum+=1;
                break;
            }
            else if(i+2>=k){
                if(s[i+1]=='.'){
                    sum+=2;
                }else sum+=1;
                break;
            }
            else if(s[i+1]=='.'){
                if(s[i+2]=='.'){
                        cout << 2 << endl;
                        return;
                }
                else
                sum+=2;
            }
            else sum+=1;
        }
        else if(s[i]=='#') sw=0;
    }

    cout << sum << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while(t--){
        solve();
    }
}