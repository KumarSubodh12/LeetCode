class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        //to contain integer overflow
        vector<long long> long_nums(n);
        int unsorted_pairs = 0;             //number of pairs which are not in order
        set<pair<long long, int>> min_pair;          //for aquiring the minimum pair everytime, can also use PQ
        vector<int> nextidx(n);             //to store the next idx of every element
        vector<int> previdx(n);             //to store the prevs idx of all element
        int operations = 0;                 //number of operations to perform;

        long_nums[0] = nums[0];
        nextidx[0] = 1;
        previdx[0] = -1;

        for(int i = 1; i < n; i++){
            long_nums[i] = nums[i];
            if(nums[i] < nums[i-1]) unsorted_pairs++;

            nextidx[i] = i+1;
            previdx[i] = i-1;           //filling the indices

            //insert in set
            min_pair.insert({long_nums[i]+long_nums[i-1], i-1});          //inserting pair of sum of adjacent and index
        }

        while(unsorted_pairs > 0){          //array has unsorted pairs
            int first = min_pair.begin()->second;           //index of smallest sum;
            int second = nextidx[first];

            int left_first = previdx[first];            //left side of first element
            int right_second = nextidx[second];         //right side of second element

            min_pair.erase(begin(min_pair));            //erasing the min sum;

            long long replace = long_nums[first] + long_nums[second];             //the sum of elements to be replaced

            if(long_nums[first] > long_nums[second]) unsorted_pairs--;          //unsorted pairs will decresed by replacing the sum

            //handling sorting on left side
            if(left_first >= 0){
                if(long_nums[left_first] > long_nums[first] && long_nums[left_first] <= replace){
                    //initially it was a bad pair, but after sum it is now sorted
                    unsorted_pairs--;
                }else if(long_nums[left_first] <= long_nums[first] && long_nums[left_first] > replace){
                    //initially it was a sorted pair but now due ot sum it's unsorted
                    unsorted_pairs++;
                }
            }

            //handling sorting on right side
            if(right_second < n){
                if(long_nums[right_second] < long_nums[second] && long_nums[right_second] >= replace){
                    //initially it was a bad pair, but after sum it is now sorted
                    unsorted_pairs--;
                }else if(long_nums[right_second] >= long_nums[second] && long_nums[right_second] < replace){
                    //initially it was a sorted pair but now due ot sum it's unsorted
                    unsorted_pairs++;
                }
            }

            //erasing and inserting the new updated pairs
            if(left_first >= 0){
                min_pair.erase({long_nums[left_first] + long_nums[first], left_first});     //pair stored at left of the current pair
                min_pair.insert({long_nums[left_first] + replace, left_first});                //replaced the sum again with left first
            }

            if(right_second < n){
                min_pair.erase({long_nums[right_second] + long_nums[second], second});    //pair stored at right of the current pair
                min_pair.insert({long_nums[right_second] + replace, first});                //replaced the sum again with first idx as the pair is removed so second idx is removed
                previdx[right_second] = first;
            }

            nextidx[first] = right_second;                          //as the second indice is removed;
            long_nums[first] = replace;

            operations++;

        }

        return operations;

    }
};