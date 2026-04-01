class Solution {
public:
    vector<int>curr;
    vector<vector<int>>ans; 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target,0);
        return ans; 
    }
    void dfs(vector<int>& candidates,int i, int &target, int current){
        if(current == target){
            ans.push_back(curr);
            return;
        }
        if(i==candidates.size() || current>target){
            return;
        }

        // include the current element
        curr.push_back(candidates[i]);
        dfs(candidates,i+1,target,candidates[i]+current);

        // do not include the current element
        curr.pop_back();
        while(i+1 < candidates.size() && candidates[i]==candidates[i+1])
            i++;
        dfs(candidates,i+1,target,current);
    }
};
