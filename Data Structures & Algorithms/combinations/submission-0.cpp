class Solution {
public:
    vector<vector<int>>ans; 
    vector<int>curr; 
    vector<vector<int>>reply; 
    vector<vector<int>> combine(int n, int k) {
        vector<int>vec;
        for(int i=0; i<n; i++)
            vec.push_back(i+1);
        dfs(vec,0);
        for(auto& v: ans){
            if(v.size()==k)
                reply.push_back(v);
        }
        return reply; 
    }
    void dfs(vector<int>&vec, int i){
        if(i==vec.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(vec[i]);
        dfs(vec,i+1);

        curr.pop_back();
        dfs(vec,i+1);
    }
};