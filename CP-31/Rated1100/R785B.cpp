#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    string s; cin >> s;
    vector<int> abc(26, 0);
    vector<char> freq;

    int fst=count(s.begin(), s.end(), s[0]);

    if(fst==s.size()){
        cout << "YES" << endl;
        return;
    }

    int mx=0;
    for(int i=0; i<s.size();i++){
        abc[s[i]-'a']++;
        if(abc[s[i]-'a']>mx){
            mx=abc[s[i]-'a'];
        }
    }

    if(fst==1){
        if(mx>1){
            cout << "NO" << endl;
            return;
        }   
        cout << "YES" << endl;
        return;
    }


    freq.push_back(s[0]); int size=0;
    for(int i=1; i<s.size(); i++){
        if(s[i]!=s[0]){
            freq.push_back(s[i]);
        }
        else {
            size=i;
            break;
        } 
    }

    vector <long long> fstfreq(26, 0);
    for(int i=1; i<size;i++){
        fstfreq[s[i]-'a']++;
        if(fstfreq[s[i]-'a']==2){
            cout << "NO" << endl;
            return;
        }
    }

    for(int i=0; i<s.size(); i++){
        if(s[i]!=freq[i%(size)]){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

    


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}