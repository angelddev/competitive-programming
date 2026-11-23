#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 

void solve(){

    string p;
    cin >> p;

    if(p.size()==1){
        if(p[0]<'a'){
            cout << (char)tolower(p[0]) << endl;
        }else cout << (char)toupper(p[0]) << endl;
        
        return;
    }

    int cont=0;
    for(char c : p){
        if(c>='A'&&c<='Z'){
            cont++;
        }
    }

    if(cont == p.size() || cont == p.size()-1){
        if(cont == p.size()-1){
            if(p[0]<'a'){
                cout << p << endl;
                return;
            }
            for(char &c : p){
                c = tolower(c);
            }
            p[0]=toupper(p[0]);
            cout << p << endl;
            return;
        }

        for(char &c : p){
            c = tolower(c);
        }
        cout << p << endl;
        return;
    }

    cout << p << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
        solve();
    
}