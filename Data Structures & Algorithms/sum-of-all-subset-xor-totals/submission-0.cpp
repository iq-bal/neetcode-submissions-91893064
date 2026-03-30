class Solution {
public:
    int ans =0; 

    void dfs(vector<int>&nums, int i, int currXor){
        if(nums.size()==i){
            ans += currXor;
            return;
        }

        // do not take the current element
        dfs(nums,i+1,currXor);
        
        //take the current element
        dfs(nums,i+1, currXor^nums[i]);
    }
    int subsetXORSum(vector<int>& nums) {
        dfs(nums,0,0);
        return ans;
    }
};