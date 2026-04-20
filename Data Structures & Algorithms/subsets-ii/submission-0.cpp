class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ans;
    }
    void dfs(vector<int>&nums, int currIndex){
        if(currIndex==nums.size()){
            ans.push_back(curr);
            return;
        }
        // take the current element
        curr.push_back(nums[currIndex]);
        dfs(nums,currIndex+1);

        // do not take the current index
        curr.pop_back();
        while(currIndex+1<nums.size() && nums[currIndex]==nums[currIndex+1])
            currIndex++;
        
        dfs(nums,currIndex+1);
    }
};