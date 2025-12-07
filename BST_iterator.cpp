/*  ////QUESTION////
Implement the BSTIterator class that represents an iterator over the in-order traversal
 of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class.
The root of the BST is given as part of the constructor. The pointer should be
initialized to a non-existent number smaller than any element in the BST.


boolean hasNext() Returns true if there exists a number in the traversal to the
right of the pointer, otherwise returns false.

int next() Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number,
the first call to the next() will return the smallest element in the BST.

Assume that the next() calls will always be valid. That is, there will be at least
 a next number in the in-order traversal when the next() is called.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIterator
{
private:
  stack<TreeNode *> myStack;

public:
  BSTIterator(TreeNode *root)
  {
    pushAll(root);
  }

  // Returns whether our tree has next element or not
  bool hasNext()
  {
    return !myStack.empty();
  }

  int next()
  {
    TreeNode *temp = myStack.top();
    myStack.pop();
    pushAll(temp->right);
    return temp->data;
  }

private:
  void pushAll(TreeNode *node)
  {
    for (; node != NULL; myStack.push(node), node = node->left)
      ;
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */