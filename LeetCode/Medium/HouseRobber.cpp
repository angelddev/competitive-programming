class Solution {
public:

    bool feasability(vector<int>& nums, int goal, int k){

        long long cont=0, curr=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=goal&&cont!=1){
                curr++;
                cont=2;
            } cont--;
            if(curr==k) return true;
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        vector<long long> sorted;
        map<long long, long long> check;

        for(int i= 0; i<nums.size(); i++){
            if(check[nums[i]]==0){
                sorted.push_back(nums[i]);
            }
            check[nums[i]]++;
        }

        sort(sorted.begin(), sorted.end());    
        long long l=0, r=sorted.size();

        long long ans=0;
        while(l<=r){
            long long mid = (l+r)/2;
            long long goal = sorted[mid];
            if(feasability(nums, goal, k)){
                r=mid-1;
                ans=goal;
            } else l=mid+1;
        }
        return ans;
    }
};