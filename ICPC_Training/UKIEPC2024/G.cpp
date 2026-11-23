#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpl vector<pll>
#define vvll vector<vll>
#define f(i, s, e) for(ll i=s; i<e; i++)
#define cf(i, s, e) for(ll i=s; i<=e; i++)
#define rf(i, s, e) for(ll i=s; i>=e; i--)
#define all(a) begin(a), end(a)
#define endl '\n'
#define pb push_back 
#define F first 
#define S second 
#define MOD1(x) ((((x)%mod1) + mod1)%mod1)
#define MOD2(x) ((((x)%mod2) + mod2)%mod2)

using namespace std; 

const ll INF = 1e18; 

ll n, m, k, wn, wm; 
vvll hsh;
vvll kmp;
vvll pi;
vll wordhash;
vector<string> word;
vector<string> mat;

const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;


ll p1 = 31, p2 = 53;

void hashear(){
    f(i,0,n){
        ll h1 = 0, h2 = 0, pw1 = 1, pw2 = 1;
        f(j,0,m){
            if(j >=wm){
                hsh[i].pb((h1 << 32) | h2);
                h1 = MOD1(h1 - (mat[i][j- wm]-'a' + 1) * pw1);
                h1 = MOD1(h1*p1 + mat[i][j] - 'a' + 1) ;
                h2 = MOD2(h2 - (mat[i][j- wm]-'a' + 1) * pw2);
                h2 = MOD2(h2*p2 + mat[i][j] - 'a' + 1) ;
            }else{
                if(j > 0){
                    pw1 = MOD1(p1*pw1);
                    pw2 = MOD2(p2*pw2);
                }
                h1 = MOD1(h1*p1 + mat[i][j] - 'a' + 1) ;
                h2 = MOD2(h2*p2 + mat[i][j] -'a' + 1);
            }
        }
        hsh[i].pb((h1 << 32) | h2);
    }
    f(i,0,wn){
        ll h1 = 0, h2 = 0;
        f(j,0,wm){
            h1 = MOD1(h1*p1 + word[i][j]-'a' + 1);
            h2 = MOD2(h2*p2 + word[i][j]-'a' + 1);
        }
        wordhash.pb((h1 << 32) | h2);
    }

}

void kmpear(){

    ll x = (m-(wm-1));
    vvll s(x);
    f(j,0,x){
        f(i,0,wordhash.size()){
            s[j].pb(wordhash[i]);
        } s[j].pb(-1);
    }
    f(j,0,x){
        f(i,0,n){
            s[j].pb(hsh[i][j]);
        } 
    }
    
    ll ss = s[0].size();
    f(i,0,x){
        f(j,1,ss){
            ll k = pi[i][j-1];
            while(k>0 && s[i][j]!=s[i][k]) k = pi[i][k-1];
            if(s[i][j]==s[i][k]) k++;
            pi[i][j] = k;
        }
    }

    ll p = wordhash.size()+1;
    vvll diffs(5000, vll(5000));

    f(j,p,ss){
        f(i,0,x){
            if(pi[i][j]==wordhash.size()){
                diffs[i][j-p-(wordhash.size()-1)]++;
                diffs[i][(j-p)+1]--;
            }
        }
    }

    
    f(j,p+1,ss){
        f(i,0,x){
            diffs[i][j-p]=diffs[i][(j-p)-1]+diffs[i][j-p];
        }
    }

    vvll printtt(n, vll(m+2, 0));
    f(r,0,n){
        f(c,0,x){
            if(diffs[c][r]>0){
                printtt[r][c]++;
                printtt[r][c+wm]--;
            }
        }
    }
    f(r,0,n){
        f(c,1,m){
            printtt[r][c]=printtt[r][c-1]+printtt[r][c];
        }
    }
    f(r,0,n){
        f(c,0,m){
            if(printtt[r][c]>0) cout << mat[r][c];
            else cout << ".";
        } cout << "\n";
    }

}

void solve(){

    cin >> wn >> wm;

    word.assign(wn+1, "");
    f(i,0,wn){
        cin >> word[i];
    }

    cin >> n >> m;

    mat.assign(3009, "");
    f(i,0,n){
        cin >> mat[i];
    }
    hsh.assign(3009, vll());
    kmp.assign(3009, vll(3009, 0));
    pi.assign(3009, vll(3009, 0));
    hashear();
    kmpear();

    cout << "\U0001F60E\n";
}

int main(){
    #ifdef DEBUG
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #else 
        ios_base::sync_with_stdio(0); 
        cin.tie(NULL); 
    #endif 

    ll t=1;
    // cin>>t; 
    while(t--){
        solve(); 
    }
}