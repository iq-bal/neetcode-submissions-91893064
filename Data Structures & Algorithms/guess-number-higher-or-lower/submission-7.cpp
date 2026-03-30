/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int h = n;
        while(true){
            int mid = l + (h-l)/2;
            int x = guess(mid);
            if(x>0)
                l = mid+1;
            else if(x<0)
                h = mid-1;
            else
                return mid;
        }
    }
};