import math

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        # Initial guess for a
        # Starting near the 'elbow' of the curve (sqrt(c/2)) 
        # is often faster for root-finding
        a = 0
        limit = int(math.sqrt(c))
        
        # We use b as our 'partner' value
        b = limit
        
        while a <= b:
            # f(a, b) = a^2 + b^2 - c
            # We want to find where current_sum - c == 0
            current_sum = a*a + b*b
            error = current_sum - c
            
            if error == 0:
                return True
            
            # Instead of a fixed step, we use the 'sign' of the error
            # to decide which direction to move along the curve.
            if error < 0:
                # Undershot: we need more 'magnitude'. 
                # Since we are moving from a=0 upwards, we increase a.
                # The derivative da/db suggests a is the cheaper variable to move.
                a += 1
            else:
                # Overshot: we need less magnitude.
                # We decrease b (moving down the derivative curve).
                b -= 1
                
        return False
        