class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<vector<int>>allTasks;
        for(int i=0; i<tasks.size(); i++)
            allTasks.push_back({tasks[i][0],tasks[i][1],i});

        sort(allTasks.begin(),allTasks.end());


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        int i = 0;
        vector<int>ans;
        long long int time = 0; 

        while(i<n || !pq.empty()){
            if(pq.empty() && time<allTasks[i][0]){
                time = allTasks[i][0];
            }
            
            while(i<n && allTasks[i][0]<=time){
                pq.push({allTasks[i][1],allTasks[i][2]});
                i++;
            }

            auto p = pq.top();
            pq.pop();

            ans.push_back(p.second);
            time += p.first;
        }
        return ans; 
    }
};