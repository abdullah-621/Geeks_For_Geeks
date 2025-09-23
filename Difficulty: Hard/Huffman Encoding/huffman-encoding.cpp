class Solution {
  public:
  
    
    class Node
    {
        public:
        
        int freq;
        char ch;
        Node *left, *right;
        
        Node(int f, char c)
        {
            freq = f;
            ch = c;
            left = right = nullptr;
        }
    };
    
    class comp
    {
        public:
        
        bool operator()(Node *a, Node *b)
        {
            return a->freq > b->freq;
        }
    };
    
    void preorder(Node *root,string &temp, vector<string>&ans)
    {
        if(!root)
        {
            return;
        }
        
        if(!root->left && !root->right)
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back('0');
        preorder(root->left, temp, ans);
        temp.pop_back();
        
        temp.push_back('1');
        preorder(root->right, temp, ans);
        temp.pop_back();
        
        
    }
    
  
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        
        priority_queue<Node *, vector<Node *>, comp>pq;
        
        
        for(int i = 0; i < N; i++)
        {
            pq.push(new Node(f[i], S[i]));
        }
        
        
        while(pq.size() > 1)
        {
            Node *first = pq.top();
            pq.pop();
            Node *second = pq.top();
            pq.pop();
            
            Node *root = new Node(first->freq + second->freq, '&');
            
            root->left = first;
            root->right = second;
            
            pq.push(root);
        }
        
        // access the root of the tree which root remain store on this pq (last node)
        Node *root = pq.top();
        // Now root hold this tree root
        pq.pop();
        
        
        vector<string>ans;
        string temp;
        
        preorder(root,temp, ans);
        
        
        return ans;
        
    }
};