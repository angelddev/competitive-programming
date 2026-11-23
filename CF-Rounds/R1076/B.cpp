#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int &i: a)
        cin >> i;
    
    vector<int> p;
    p=a;
    sort(p.rbegin(), p.rend());


    if(p==a){
        for(int x : a){
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    set<int> nums(a.begin(), a.end());

    int index=0, looking=p[0];
    for(int i=0; i<n; i++){
        if(a[i]!=p[i]){
            index=i;
            looking=p[i];
            break;
        }
    }

    int right=index;
    for(int i=index; i<n; i++){
        if(a[i]==looking)
        right=i;
    }

    reverse(a.begin()+index, a.begin()+right+1);
    
    for(int x: a)
    cout << x << " ";

    cout << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
    
}