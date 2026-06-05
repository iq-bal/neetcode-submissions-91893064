class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int h = accumulate(nums.begin(),nums.end(),0);

        int res = h; 
        while(l<=h){
            int mid = l + (h-l)/2;
            if(canSplit(mid,k,nums)){
                res = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return res;
    }
    bool canSplit(int target,int k, vector<int>&nums){
        int currSum = 0;
        int count = 0;
        for(int num : nums){
            currSum+=num;
            if(currSum>target){
                currSum = num;
                count++;
            }
        }
        return count + 1 <=k; 
    }
};

/*
minimize the maximum
f f f t t t
*/