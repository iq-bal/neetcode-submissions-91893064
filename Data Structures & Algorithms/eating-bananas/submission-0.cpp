class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans=high;
        binarySearch(piles,low,high,h,ans);
        return ans; 
    }
    void binarySearch(vector<int>& piles,int low, int high, int h, int &ans){
        while(low<=high){
            int mid = low + (high - low) / 2;
            int total_time_required = 0;
            for(int i=0; i<piles.size(); i++)
                total_time_required += (piles[i] + mid - 1) / mid;
            if(total_time_required<=h){
                high = mid-1;
                ans = mid; 
            }  
            else{
                low = mid+1;
            } 
        }
    }
};
