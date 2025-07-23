class Solution:
    def intersection(self, arr1, arr2):
        #code here
        list1 = set(arr1)
        list2 = set(arr2)
        
        intersec_list = list1.intersection(list2)
        
        return sorted(list(intersec_list))
