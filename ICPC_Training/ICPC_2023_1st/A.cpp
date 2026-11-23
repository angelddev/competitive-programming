#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define vll vector<ll>
#define f(i,s,e) for(ll i=s; i<e; i++)

void solve(){

    ll n, x; cin >> n;
    string s;
    ll ans=0;
    vector<string> strings;
    map<string, ll> playing;
    f(i,0,n){
        cin >> x;
        ans++;
        getline(cin, s);
        string temp="";
        temp+=s[0];
        f(i,0,s.size()){
            if(s[i]==' '){
                temp+=s[i+1];
            }
        }
        ll band=0;
        f(i,0,strings.size()){
            if(temp==strings[i]){
                band=1;
                ans--;
                if(playing[temp]==1){
                    playing[temp]=0;
                    ans--;
                }
                break;
            }
        }
        if(band==0){
            strings.push_back(temp);
            playing[temp]=1;
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
