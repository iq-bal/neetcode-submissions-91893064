class Solution {
public:
    priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>>pq;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(auto& e: points){
            int x = e[0];
            int y = e[1];
            double d = sqrt(x*x+y*y);
            pq.push(make_pair(d,vector<int>{x,y}));
        }
        vector<vector<int>>ans;
        for(int i=0; i<k; i++){
            auto t = pq.top();
            pq.pop();
            vector<int> temp = t.second;
            ans.push_back(temp);
        }
        return ans; 
    }
};
