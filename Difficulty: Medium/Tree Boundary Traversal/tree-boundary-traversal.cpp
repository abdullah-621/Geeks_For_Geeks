/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  bool isleaf(Node *root)
  {
      return !root->left && !root->right;
  }
  
//   Add left Node
  void left_Boundary(Node *root, vector<int>&result)
  {
      if(!root || isleaf(root)) return;
      
      result.push_back(root->data);
      
      if(root->left) left_Boundary(root->left,result);
      
      else if(root->right) left_Boundary(root->right,result);
  }
  
//   Add leaf Node
  void leaf_Boundary(Node *root, vector<int>&result)
  {
      if(root == nullptr) return;
      
      if(isleaf(root)) 
      {
      result.push_back(root->data);
      return;
      }
      leaf_Boundary(root->left,result);
      leaf_Boundary(root->right,result);
  }
  
//   Add right Node
  
  void right_Boundary(Node *root, vector<int>&result)
  {
      if(!root || isleaf(root)) return;
      
      
      if(root->right) right_Boundary(root->right,result);
      
      else if(root->left) right_Boundary(root->left,result);
      
      result.push_back(root->data);
  }
  
  
    vector<int> boundaryTraversal(Node *root) 
    {
        // code here
        vector<int>result;
        
        if(!root) return result;
        
        // Add root data if it's not a leaf
        if(!isleaf(root)) result.push_back(root->data);
        
        left_Boundary(root->left,result);
        leaf_Boundary(root,result);
        right_Boundary(root->right,result);
        
        return result;
    }
};