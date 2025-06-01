class Solution {
  public:
  void addmatrix(vector<vector<int>> mat, vector<int>&brr)
  {
      for(int i = 0; i < mat.size(); i++){
          for(int j = 0; j < mat[i].size(); j++){
              brr.push_back(mat[i][j]);
          }
      }
  }
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        vector<int>arr1;
        vector<int>arr2;
        addmatrix(mat1,arr1);
        addmatrix(mat2,arr2);
        
        int count = 0;
        
        int i = 0;
        int j = arr1.size() - 1;
        
        while(i < arr1.size() && j >= 0)
        {
            if(arr1[i] + arr2[j] == x)
            {
                i++;
                j--;
                count++;
            }
            else if(arr1[i] + arr2[j] > x) j--;
            
            else i++;
        }
        
        return count;
    }
};