#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m, i, j, k, o, p, absmex, flagg;
    cin >> n;

  

    for(i=0;i<n;i++)
    {
       
        absmex=0;
        flagg=0;
        cin >> m;
        vector<int> arr;

        for (j=0; j<m;j++){
            cin >> o;
            arr.push_back(o);
        }

        sort(arr.begin(), arr.end());

        if(arr[0]>0)
         flagg=1;
         
        else{
        for(p=0;p<arr.size()-1;p++){
                if((arr[p+1]-arr[p])>1){
                    absmex = arr[p]+1;
                    flagg=1;
                    break;}
            }
        }
            
            if (!flagg)
                absmex = *(arr.end()-1)+1;
            

        cout << absmex << "\n";
    }

}