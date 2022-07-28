
https://leetcode.com/problems/binary-tree-postorder-traversal/
https://www.youtube.com/watch?v=2YBhNLodD8Q&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=12
https://www.youtube.com/watch?v=NzIGLLwZBS8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=13
https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root)return v;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(node || !st.empty()){
            while(node){
                st.push(node);
                node=node->left;
            }
            auto t=st.top()->right;
            if(t)node=t;
            else{
                auto t=st.top();
                st.pop();
                v.push_back(t->val);
                while(!st.empty() and t==st.top()->right){
                    t=st.top();
                    st.pop();
                    v.push_back(t->val);
                }
            }
        }
       return v;
    }
};

// METHOD 2 USING TWO STACK!!!

/* vector<int> postorderTraversal(TreeNode* root) {
        // postorder Traversal left -> right -> root;
        vector<int> v;
        
        if(root==NULL) return v; 
        // root is null then return the empty vector v
        
        stack<TreeNode*> s,s2; 
        // creat two stack in which we will store the node 
        s.push(root);           
        // intially we will push the root in the stack
        while(!s.empty())         
        // while loop will rum till it will become empty
        {
            root=s.top();  // in root we will assign top of the stack
            s.pop();       // delete the top  of stack s
            s2.push(root); // push the deleted value in stack s2
            
            if(root->left != NULL)    
            {   // check weather the left of the root is null or not 
               s.push(root->left);
               // if root left is not null then push the right in stack s
            }
            if(root->right != NULL)  
            {   // another case in which we will check the right of the root
                s.push(root->right);   
                // if yes then push the root left in the stack s
            }
        }
        // now will copy all the root->val in vector v
        while(!s2.empty()) 
        {
            v.push_back(s2.top()->val);   
            s2.pop();
        }
        return v;
    } */

/*
Recursive
class Solution {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)return v;
        
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        v.push_back(root->val);
        
        return v;
    }
}; */
