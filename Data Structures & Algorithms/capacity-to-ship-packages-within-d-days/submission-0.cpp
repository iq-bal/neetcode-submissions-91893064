class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long low = *max_element(weights.begin(),weights.end());
        long long high = accumulate(weights.begin(),weights.end(),0);
        return binarySearch(weights,low,high,days);
    }
    int binarySearch(vector<int>& weights, long long low, long long high, int days){
        int ans = high; 
        while(low<=high){
            long long mid = low + (high-low)/2;
            int sum = 0;
            int g = 0; 
            for(int i=0; i< weights.size(); i++){
                if(sum + weights[i]<=mid)
                    sum += weights[i];
                else
                    (sum = weights[i], g++);
            }
            g++;
            if(g<=days){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid + 1;
        }
        return ans; 
    }
};