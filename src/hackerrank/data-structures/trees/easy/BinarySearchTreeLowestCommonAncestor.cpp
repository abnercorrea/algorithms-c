

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
		if (!root) return nullptr;
        
        int h = max(v1, v2), l = min(v1, v2);
        
        if (l <= root->data && h >= root->data) {
            return root;
        }
        else if (l <= root->data) {
            return lca(root->left, v1, v2);
        }
        else {
            return lca(root->right, v1, v2);            
        }
    }

