#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){

    ll n; cin >> n;
    set<pair<ll, ll>> equals;
    vector<pair<ll, ll>> original(n); 
    ll first, second;

    for(ll i=0; i<n; i++){
        cin >> first >> second;
        if(first==second)
            equals.insert({first, second});
        original[i]={first,second};
    }

    vector<pair<ll,ll>> forbiddenRanges;
    if(equals.size() >= 2){
        auto prev = equals.begin();
        auto it = std::next(prev);

        ll len = 1;                      
        ll start_value = prev->first;    

        for(; it != equals.end(); ++it){
            if(it->first == prev->first + 1){
                ++len;                   
            } else {
                if(len > 1)            
                    forbiddenRanges.push_back({start_value, prev->first});
                len = 1;
                start_value = it->first;
            }
            prev = it;
        }

    
        if(len > 1)
            forbiddenRanges.push_back({start_value, prev->first});
    }


    set<pair<ll, ll>> last;
    string ans;
    for(int i=0; i<n;i++){
        if(original[i].first==original[i].second){
            if(last.find(original[i])==last.end()){
                last.insert(original[i]);
                cout << 1;
            } else cout << 0;
        }
        else {
            auto it = upper_bound(forbiddenRanges.begin(),forbiddenRanges.end(), make_pair(original[i].first, LLONG_MAX));
            if(it!= forbiddenRanges.begin()){
                --it;
            if(it->first <= original[i].first && original[i].second <= it->second){
                cout << 0;    
            }
}           else cout << 1;
        }
    }

    cout << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--);
        solve();
}