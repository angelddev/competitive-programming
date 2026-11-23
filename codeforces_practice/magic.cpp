 #include <bits/stdc++.h>
    using namespace std;
 
 
    void solve(){
 
        int n, p;
 
        cin >> n;
 
        vector<int> arr;
        arr.reserve(n); 

        for(int i=0; i<n; i++){
          cin >> p;
          arr.push_back(p);
        }


        int band=1;

        if(arr[0]%2){
            for(int &p:arr){
                if(!(p%2)){
                    band=0;
                    break;
                }
            }
        }
        else 
        for(int &p:arr){
                if(p%2){
                    band=0;
                    break;
                }
            }

        if(!band){
            sort(arr.begin(), arr.end());
            for(int &x: arr){
                cout << x;
                cout << ' ';
            }   
 
        cout << "\n";
        return;
        }
           
        for(int &x: arr){
            cout << x;
            cout << ' ';
        }
 
        cout << "\n";
    }
 
    int main(){
 
        ios::sync_with_stdio(0);
        cin.tie(0);
 
        int t;
        cin >> t;
 
        for(int i=0; i<t;i++)
            solve();
 
    }