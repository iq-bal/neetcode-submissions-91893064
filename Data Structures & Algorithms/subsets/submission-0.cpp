class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void dfs(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // take nums[i]
        subset.push_back(nums[i]);
        dfs(nums, i + 1);

        // do not take nums[i]
        subset.pop_back();
        dfs(nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};