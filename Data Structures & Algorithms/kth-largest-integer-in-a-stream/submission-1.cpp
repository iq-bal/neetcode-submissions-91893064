class KthLargest {
public:
    priority_queue<int>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
       pq.push(val);
       vector<int>temp;
       for(int i=0; i<k-1; i++){
            temp.push_back(pq.top());
            pq.pop();
       }
       int ans = pq.top();
       for(int i=0; i<temp.size(); i++)
        pq.push(temp[i]);

        return ans; 
    }
};
