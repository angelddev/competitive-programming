    #include <bits/stdc++.h>
    using namespace std;
    #define endl '\n'
    typedef long long ll;
     
     
void solve(){

    int n; ll x; cin >> n >> x;

    vector<int> coral(n);
    for(int i=0; i<n; i++)
        cin >> coral[i];

    sort(coral.begin(), coral.end());

    ll used=0, j=1;
    while(used<x){
        auto it=upper_bound(coral.begin(), coral.end(), j);
        ll cnt=it-coral.begin();
        
        if(it==coral.end()){
           j+=(x-used)/n;
           break;
        }
        
        ll nj=*it;
        ll diff=nj-j;
        if(cnt>0){
            ll can_add=diff*cnt;
            if(used+can_add<=x){
                used+=can_add;
                j=nj;
            }else{
                j+=(x-used)/cnt;
                used=x;
                break;
            }
        }else j=nj;
    }

    cout << j << endl;
}
     
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
     
        int n; cin >> n;
        while(n--){
            solve();
        }
    }