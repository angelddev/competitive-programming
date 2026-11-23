#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n; cin >> n;

    vector<int> o(n), c(n);

    for(int i=0; i<n;i++){
        cin >> o[i];
    }
    for(int i=0; i<n;i++){
        cin >> c[i];
    }

    pair<int, int> temp;
    auto sol=make_tuple(0,0,0);
    temp.first=0;
    temp.second=0;

    int longest=0, i;
    for(i=0; i<n-1; i++){
        if(c[i]<=c[i+1]){
            longest++;
            if(longest==1)
                temp.first=i;
            temp.second=i+1;
        }
        else {
            longest=0;
            if(temp.second-temp.first>=get<2>(sol)){
                for(int i=temp.first; i<=temp.second; i++){
                    if(o[i]!=c[i]){
                        get<0>(sol)=temp.first;
                        get<1>(sol)=temp.second;
                        get<2>(sol)=temp.second-temp.first;
                        break;
                    }
                }
            }
        }
    }
    if(temp.second-temp.first>=get<2>(sol)){
                for(int i=temp.first; i<=temp.second; i++){
                    if(o[i]!=c[i]){
                        get<0>(sol)=temp.first;
                        get<1>(sol)=temp.second;
                        get<2>(sol)=temp.second-temp.first;
                        break;
                    }
                }
            }

    

    cout << get<0>(sol)+1 << " " << get<1>(sol)+1 << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}