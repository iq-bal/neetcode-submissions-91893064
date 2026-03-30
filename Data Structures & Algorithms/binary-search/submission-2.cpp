class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size(),target);
    }
    int binarySearch(vector<int>& nums, int l, int h, int target){
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                l = mid+1;
            else
                h = mid-1;
        }
        return -1; 
    }
};
