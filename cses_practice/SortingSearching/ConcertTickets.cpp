#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll= long long;

void solve(){
        
    int n, m; cin >> n >> m;

    multiset<int> tickets;
    vector<int> people(n);
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        tickets.insert(x);
    }

    for(int i=0; i<m; i++){
        cin >> people[i];
    }

    int i;
    for(i=0; i<m; i++){
        if(tickets.empty()){
            for(int j=i; j<m; j++){
                cout << -1 << endl;
            }
            return;
        }
        auto it = tickets.lower_bound(people[i]);
        if(*it==people[i]){
            cout << *it << endl;
            tickets.erase(it);
        }
        else if(it==tickets.begin()){
            cout << -1 << endl;
        }
        else{
            cout << *prev(it) << endl;
            tickets.erase(prev(it));
        }
    }
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}