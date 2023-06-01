/*
Binary Search Tree Iterator

We could have easily done this question by using inorder traversal and storing it in a vector after that iterating every index of vector for next() value and if the index is equal to vector size then hasnext() becomes false else it would be true.

But in question, it is given that we have to do it in 0(h) memory, where h is the height of the tree. So now we will make use of the stack and instead of inorder traversal, we would use partial inorder traversal so that at any instant of time the stack contains elements equal to the height of the tree.

Step 1: We will push the left part of the tree into a stack which is 7 and then 3 is inserted. Now is next() is called 3 is stored as the top and then poped now we will push the right of 3 but it does not contain any so we just return the top->val i.e. 3.

Step 2: We will now pop() 7 from the stack and see if it has the right children yes it has so we push 15 and then 9 into the stack. Observe here you'll see at a time stack contains elements equal to the height of the tree.

Step 3: Now 9 is poped and 9 does contain any right child so we move on 15. If hasnext() is called it would return true as traversal is still left and the stack is also not empty.

Step 4: Now 15 is poped and checked if it has the right child yes it has i.e. 20 so 20 is pushed inside the stack.

Step 5: Lastly 20 is poped and returned and after that is hasnext() is called it will return false as there are no more elements or children inside the stack.


*/

class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    void helper(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
    int next() {
        TreeNode* top = st.top();
        st.pop();
        helper(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

______
  
  
O(N) memory

class BSTIterator {
public:
    vector<int> inorder;
    int idx=0;
    BSTIterator(TreeNode* root) {
       helper(root);
    }
    
    void helper(TreeNode* root)
    {
         if(root)
        {
        helper(root->left);
        inorder.push_back(root->val);
        helper(root->right);
        }
    }
    int next() {
        if(idx<inorder.size())
        return inorder[idx++];
        
        return -1;
    }
    
    bool hasNext() {
      if(idx<inorder.size())
      {
          return true;
      }
        return false;
    }
};
