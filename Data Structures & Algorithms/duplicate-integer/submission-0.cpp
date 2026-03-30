class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>vis;
        for(auto& num : nums){
            if(vis.find(num)!=vis.end())
                return true;
            vis.insert(num);
        }
        return false;
    }
};