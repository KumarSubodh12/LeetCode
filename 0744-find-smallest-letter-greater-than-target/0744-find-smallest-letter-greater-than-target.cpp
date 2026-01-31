class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = n - 1;
        char ans = letters[0];  // default for wrap-around

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (letters[mid] > target) {
                ans = letters[mid];
                high = mid - 1;  // try to find smaller valid char
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
