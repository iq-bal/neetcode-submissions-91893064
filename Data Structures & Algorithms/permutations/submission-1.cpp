class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        // base case
        if (nums.size() == 1) {
            return {nums};
        }

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[0];
            nums.erase(nums.begin());              // pop front

            vector<vector<int>> perms = permute(nums);

            for (auto& perm : perms) {
                perm.push_back(n);
            }

            result.insert(result.end(), perms.begin(), perms.end());
            nums.push_back(n);
        }

        return result;
    }
};