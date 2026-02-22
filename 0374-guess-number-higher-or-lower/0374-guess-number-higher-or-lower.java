/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
       int low = 1;
        int high = n;  //10 3

        while (low <= high) {
            int mid = low + (high - low) / 2;  //4

            int ans = guess(mid);  // check mid number is == pick number 
                                   // if mid == pick --> ans = 0   
                                   // if mid > pick --> ans = -1  
                                   // if mid < pick --> ans = 1   

            if (ans == 0) {
                return mid;       // correct number
            } 
            else if (ans < 0) {    // your guess is higher  4
                high = mid - 1;
            } 
            else {                 // your guess is lower
                low = mid + 1;
            }
        }

        return -1;   // not actually reached
    }
}