class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        int right = nums[n-1];

        while(low<=high){
            int mid = low + (high-low)/2;
            // if(nums[mid]<nums[(mid-1+n)%n] && nums[mid]<nums[mid+1+n]%n)
            //     return nums[mid];
            if(nums[mid]>right)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nums[low]; 
    }
};
