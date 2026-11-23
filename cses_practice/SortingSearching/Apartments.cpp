#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll= long long;

void solve(){
    
    int n, m, k;

    cin >> n >> m >> k;

    vector<int> people(n);
    vector<int> sizes(m);
    for(int i=0; i<n; i++){
        cin >> people[i];
    }

    for(int i=0; i<m; i++){
        cin >> sizes[i];
    }

    sort(sizes.begin(), sizes.end());
    sort(people.begin(), people.end());

    int i=0, j=0, sol=0;
    while(i!=people.size() && j!=sizes.size()){
        if(people[i]<=sizes[j]+k&&people[i]>=sizes[j]-k){
            sol++;
            i++;j++;
        }
        else if(people[i]>sizes[j]){
            j++;
        }
        else i++;
    }

    cout << sol << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}