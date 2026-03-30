class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total_element = n*m;
        return binarySearch(matrix,0,total_element-1,m,target);
    }
    bool binarySearch(vector<vector<int>>& matrix,int l, int h,int m, int target){
        while(l<=h){
            int mid = (l+h)/2;
            int row = mid/m;
            int col = mid%m; 
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]>target)
                return binarySearch(matrix,l,mid-1,m,target);
            return binarySearch(matrix,mid+1,h,m,target);
        }
        return false;
    }
};
