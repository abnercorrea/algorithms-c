
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
        if (! root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* n = q.front();
            cout << n->data << ' ';
            q.pop();
            if (n->left) q.push(n->left);  
            if (n->right) q.push(n->right);  
        }
    }

