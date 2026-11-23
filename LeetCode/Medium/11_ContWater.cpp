class Solution {
public:
    using ll = long long;

    int maxArea(vector<int>& height) {
        ll mx=0, temp;
        ll l=0, r=height.size()-1;
        while(l<r){
            temp=min(height[l], height[r])*(r-l);
            mx=max(temp, mx);

            if(height[l]>height[r]){
                r--;
            } else l++;
        }
        cout << mx << "\n";
    }
};