#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){

    string s;
    cin >> s;


    if(count(s.begin(), s.end(), '0')==0){
        cout << s.size()*s.size() << endl;
        return;
    }
    if(count(s.begin(), s.end(), '1')==0){
        cout << 0 << endl;
        return;
    }


    int largest=0, temp=0;
    for(int i=0; i<s.size()*2; i++){
        if(s[i%s.size()]=='1'){
            temp++;
        }
        else {
            largest=max(largest, temp);
            temp=0;
        }
    }

    largest=max(largest, temp);
    int k=s.size();
    largest=min(largest, k);

    ll s1=(largest+1)/2;
    ll s2 =(largest+2)/2;


    cout << s2*s1 << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while(n--){
        solve();
    }
}

