#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    long long m, k;
    cin >> m >> k;

    queue<pair<long long, int>> q;
    set<long long> v;
    v.insert(m);
    q.push({m, 0});

    while(!q.empty()){
        pair<long long, int> current= q.front();
        if(current.first==k){
            cout << current.second << endl;
            return;
        }
        q.pop();

        if(current.first>k){
            long long floor = current.first/2;
            long long ceiling = (current.first/2)+(current.first%2);
            if(v.find(floor)==v.end()){
                v.insert(floor);
                q.push({floor, current.second+1});
            }
            if(v.find(ceiling)==v.end()){
                v.insert(ceiling);
                q.push({ceiling, current.second+1});
            }
        }
    }

    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) solve();
}