/*

    Time Complexity : O(logN) where N is the number.

    Space Complexity : O(logN), Hash Table(unordered_set(set)) space.

    Solved using Math + Hash Table.

*/


/***************************************** Approach 1 *****************************************/

class Solution {
private:
    int nextNumber(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1 && !set.count(n)){
            set.insert(n);
            n = nextNumber(n);
        }
        return n==1;
    }
};






/*

    Time Complexity : O(logN) where N is the number.

    Space Complexity : O(1), Constant space.

    Solved using Floyd's Cycle-Finding Algorithm.

*/
