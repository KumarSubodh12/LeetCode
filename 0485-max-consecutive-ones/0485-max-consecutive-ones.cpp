class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int current = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                current++;
                maxOnes = max(maxOnes, current);
            } else {
                current = 0;
            }
        }

        return maxOnes;
    }
};