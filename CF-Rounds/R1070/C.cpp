#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<int> odds, evens;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2) odds.push_back(x);
        else evens.push_back(x);
    }
    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());
    
    
    if(odds.size()==0){
        for(int i=0;i<n;i++){
            cout << "0\n"; 
        } 
    return;
    }

    if(evens.size()==0){ 
        long long current=0; 
        for(int i=0;i<n;i++){ 
            current += odds.front(); 
            odds.pop_front(); 
            cout << current << "\n"; 
        } 
    return; 
    }

    deque<int> sumevens, sumodds, nones=odds, pares=evens;


    long long current =0;
    for(int k=0; k<evens.size();k++){
        current += evens.front(); 
        evens.pop_front(); 
        sumevens.push_back(current);
    }

    long long ocurrent =0;
    for(int k=0; k<odds.size();k++){
        ocurrent += odds.back(); 
        odds.pop_back(); 
        if(ocurrent%2==0){
            ocurrent=0;
        }
        sumodds.push_back(ocurrent);
    }

    cout << nones.front() << "\n";

    int cur, oc=1;
    for(int j=1;j<=n;j++){

        if(j>evens.size()){
            cur=sumodds[j-oc++]+nones.front()+sumevens[j-(evens.size()%j-1)];
            if(cur%2==0)
                cout << "0\n";
            else cout << cur << "\n";
        }
        else{
            cur=nones.front()+sumevens[j-1];
            cout << cur << "\n";
        }
    }


    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
