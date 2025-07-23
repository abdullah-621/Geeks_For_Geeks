#User function Template for python3
#User function Template for python3

class Solution:
    def get_min_max(self, arr):
        
        if not arr:
            return None, None
    
        min_val = arr[0]
        max_val = arr[0]
        
        
        for val in arr:
            
            if val < min_val:
                min_val = val
                
            elif val > max_val:
                max_val = val
        
        return min_val, max_val
                