class Solution {
public:
    priority_queue<int>pq;
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];
        for(int i=0; i<stones.size(); i++)
            pq.push(stones[i]);
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(pq.size()==0)
                return x;
            int y = pq.top();
            pq.pop();
            if(x==y)
                continue;
            else
                pq.push(abs(x-y));
        }
        return pq.size()>0 ? pq.top() : 0 ;
    }
};
