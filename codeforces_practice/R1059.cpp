#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;

int main(){
    int n; cin >> n; 
    while(n--){
        int t; cin >> t;
        string s; cin >> s;
        deque<int> a;
        
        ll l=0, r=t-1;
        while(l<=r){
            if(s[l]==s[r]){
                l++, r--;
            } else if(s[r]>s[l]){
                a.push_back(r+1);
                r--;
            } else {
                a.push_back(l+1);
                l++;
            }
        }
        sort(a.begin(), a.end());
        cout << a.size() << endl;
        for(int i : a){
            cout << i << " ";
        }
        cout << endl;
    }
}