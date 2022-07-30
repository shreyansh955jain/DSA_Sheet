************ imp
https://leetcode.com/problems/all-possible-full-binary-trees/

tutorials
https://leetcode.com/problems/all-possible-full-binary-trees/discuss/1316191/A-Good-C%2B%2B-Solution-(Recursion-with-Memorization-and-comments)

https://www.youtube.com/watch?v=VYczyMiMTqA




class Solution {
public:
    unordered_map<int,vector<TreeNode*>>memorization;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>ans;
        if(n<1 || n%2==0) return ans;
        if(memorization.find(n)!=memorization.end()){
            return memorization[n];
        }
        if(n==1){
            ans.push_back(new TreeNode(0));
            memorization[n]=ans;
            return ans;
        }
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>  left=allPossibleFBT(i);
            vector<TreeNode*>  right=allPossibleFBT(n-1-i);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                 TreeNode* root=new TreeNode(0);
                 root->left=left[j];
                 root->right=right[k];
                 ans.push_back(root);
                }
            }        
        }
        memorization[n]=ans;
        return ans;
    }
};