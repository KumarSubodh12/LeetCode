class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int n=nums.size(), bias=511, bMask=1023;
        const int mbias=bias%n;
        for(int& x: nums) x+=bias;// pass the ref. modified x>=0
        for(int i=0; i<n; i++){
            int j=(i+nums[i]-mbias+n)%n; //Ensure j>=0
            // the converted number is put from 10th-bit on
            // including the sign
            nums[i]+=((nums[j]& bMask)-bias)<<10;
        }
        for( int& x: nums) x>>=10;//Use bit shift to obtain correct x
        return nums;
    }
};