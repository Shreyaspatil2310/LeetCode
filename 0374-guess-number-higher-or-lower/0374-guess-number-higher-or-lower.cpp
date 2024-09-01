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
        int start = 1, end = n;
        while (start <= end) {
            int mid = start + (end - start) / 2; // Prevents potential overflow
            int result = guess(mid);
            if (result == 0) {
                return mid; // The guessed number is correct
            } else if (result < 0) {
                end = mid - 1; // The number is lower, so adjust the end
            } else {
                start = mid + 1; // The number is higher, so adjust the start
            }
        }
        return -1; // Should never reach here if the number is always in the range
    }
};
