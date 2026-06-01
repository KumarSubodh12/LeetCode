class Solution {
public:
    int minimumCost(vector<int>& candies) {
        sort(candies.rbegin(), candies.rend());

        int cost = 0;

        for (int i = 0; i < candies.size(); i++) {
            if ((i + 1) % 3 != 0) {
                cost += candies[i];
            }
        }

        return cost;
    }
};