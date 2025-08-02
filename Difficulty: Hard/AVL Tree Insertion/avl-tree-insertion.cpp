/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution {
  public:
   int getheight(Node *root)
{
  if (!root)
    return 0;
  else
  {
    return root->height;
  }
}

// calculate Banlance
int getBalance(Node *root)
{
  return getheight(root->left) - getheight(root->right);
}

// right rotation
Node *rightRotation(Node *root)
{
  Node *child = root->left;
  Node *rightChild = child->right;
  child->right = root;
  root->left = rightChild;
  
  root->height = 1 + max(getheight(root->left), getheight(root->right));
  child->height = 1 + max(getheight(child->left), getheight(child->right));
  
  return child;
}
// left rotation
Node *leftRotation(Node *root)
{
  Node *child = root->right;
  Node *leftChild = child->left;
  child->left = root;
  root->right = leftChild;
  
  root->height = 1 + max(getheight(root->left), getheight(root->right));
  child->height = 1 + max(getheight(child->left), getheight(child->right));
  
  return child;
}
    
    Node* insertToAVL(Node* root, int key) {
        if (!root)
  {
    return new Node(key);
  }
  // root exist

  if (key > root->data)
    root->right = insertToAVL(root->right, key);

  else if (key < root->data)
  {
    root->left = insertToAVL(root->left, key);
  }

  else
  {
    return root;
  }

  // update height
  root->height = 1 + max(getheight(root->left), getheight(root->right));

  // check balanc factor
  int balance = getBalance(root);

  // LL case
  if (balance > 1 && key < root->left->data)
  {
    return rightRotation(root);
  }
  // RR case
  else if (balance < -1 && key > root->right->data)
  {
    return leftRotation(root);
  }
  // LR case
  else if (balance > 1 && key > root->left->data)
  {
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }
  // RL case
  else if (balance < -1 && key < root->right->data)
  {
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }
  // No unbanancing
  else
  {
    return root;
  }
}
};