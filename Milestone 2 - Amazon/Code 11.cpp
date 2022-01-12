// Serialize and Deserialize a Binary Tree

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> vec;
    //Function to serialize a tree and return a list containing nodes of tree.
    void help(Node* root)
    {
        if(!root)
        return;
        
        help(root->left);
        vec.push_back(root->data);
        help(root->right);
    }
    vector<int> serialize(Node *root) 
    {
       help(root);
       return vec;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       struct Node*newroot = new Node(-1);
       Node* temp = newroot;
       int n = A.size();
       for(int i=0;i<n;i++)
       {
           temp->right = new Node(A[i]);
           temp = temp->right;
       }
       return newroot->right;
    }

};