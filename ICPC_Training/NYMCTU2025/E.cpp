#include <bits/stdc++.h>

#define ll long long 
#define endl '\n'
#define all(a) begin(a), end(a)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpl vector<pll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define F first
#define S second
#define pb push_back
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 +7;

string mult(string num1, int n2){

    string ans = "";
    ll carry = 0;
    for(ll i = num1.size()-1; i>=0; i--){
        ll n1=(num1[i]-'0')*n2+carry;
        carry=n1/10;
        ans=to_string(n1%10)+ans;
    }

    ans=to_string(carry)+ans;

    ll idx=0;

    while(ans[idx]=='0')
        idx++;
    return ans.substr(idx);
}


string block(string num){

    string ans = "1";
    f(i,0,num.size())
    ans = mult(ans, num[i]-'0');
    //cout << ans << "\n";
    return ans;
}


string sums(string num, string num2){
    
    if(num2.size()>num.size()){
        while(num.size()!=num2.size()){
            num='0'+num;
        }
    }
    if(num.size()>num2.size()){
        while(num.size()!=num2.size()){
            num2='0'+num2;
        }
    }

    string ans = "";
    ll carry = 0;
    for(ll i = num.size()-1; i>=0; i--){
        ll n1=(num[i]-'0')+(num2[i]-'0')+carry;
        carry=n1/10;
        ans=to_string(n1%10)+ans;
    }
    ans=to_string(carry)+ans;

    ll idx=0;
    while(ans[idx]=='0')
        idx++;
    return ans.substr(idx);
}

void solve(){

    string s; cin >> s;

    string temp;
    vector<string> blocks;
    for(int  i = 0; i < s.size(); i++){
        if(s[i]=='+'){
            //cout << temp << "\n";
            string Tans = block(temp);
            blocks.pb(Tans);
            temp.clear();
        }
        else if(s[i]=='*') continue;
        else temp.pb(s[i]);
    }
    string Tans = block(temp);
    blocks.pb(Tans);

    // for(string bl : blocks){
    //     cout << bl << "\n";
    // }
    string ans = "0";
    f(i,0,blocks.size())
    ans = sums(ans, blocks[i]);

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll t=1;
    while(t--){
        solve(); 
    }
}