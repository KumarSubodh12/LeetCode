class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        
        int left = 1;
        int right = 0;
        
        for(int bananas : piles){
            right = Math.max(right, bananas);
        }
        
        int ans = right;
        
        while(left <= right){
            int mid = left + (right - left)/2; 
            
            long hours = 0;
           
            for(int bananas : piles){
                hours += (bananas + mid - 1) / mid;  
            }
            
            if(hours <= h){
                ans = mid;      
                right = mid - 1; 
            }else{
                left = mid + 1;
            }
        }
        
        return ans;
    }
}