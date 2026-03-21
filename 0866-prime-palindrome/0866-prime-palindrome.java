class Solution {
    private boolean isPrime(int val){

        if(val < 2) return false;
        if(val == 2) return true;
        if(val % 2 == 0) return false;
        for(int i=3;i*i<=val;i+=2){
            if(val%i==0)return false;
        }
        return true;
    }
    private boolean isPalindrome(int val){
        int value=val;
        int num=0;
        while(val>0){
            int rem=val%10;
            num=num*10+rem;
            val/=10;
        }
        return num==value;
    }
    public int primePalindrome(int n) {
        
        for(int i=n;i<=Integer.MAX_VALUE;i++){
            if(10000000 < i && i < 100000000)
                i = 100000000;
            if(isPalindrome(i)&&isPrime(i)){
                return i;
            }
        }
        return -1;
    }
}