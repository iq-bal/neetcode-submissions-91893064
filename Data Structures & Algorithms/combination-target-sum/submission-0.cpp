class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr; 
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums,0,0,target);
        return ans; 
    }
    void dfs(vector<int>& nums, int i, int total, int target){
        if(total==target){
            ans.push_back(curr);
            return;
        }
        if(i==nums.size() || total>target){
            return; 
        }

        //include the current one more time
        curr.push_back(nums[i]);
        dfs(nums, i,nums[i]+total,target);

        // do not include
        curr.pop_back();
        dfs(nums,i+1,total,target);
    }
};
