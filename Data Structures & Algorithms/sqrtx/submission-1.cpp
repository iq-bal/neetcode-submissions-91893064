class Solution {
public:
    int mySqrt(int x) {
        return bSearch(1,x,x);
    }
    int bSearch(int l, int h, int target){
        while(l<=h){
            int mid = l + (h-l)/2;
            if((long long)mid*mid==target)
                return mid;
            if((long long)mid*mid>target)
                h = mid-1;
            else
                l = mid+1;
        }
        return h; 
    }
};