class KthLargest {
public:
    priority_queue<int>pq;
    int k;
    vector<int>nums;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums; 
    }
    
    int add(int val) {
       nums.push_back(val);
       vector<int>v = nums;
       sort(v.begin(),v.end(),greater<int>());
       for(int i=0; i<v.size(); i++){
            if(i+1==k)
                return v[i];
       }
    }
};
