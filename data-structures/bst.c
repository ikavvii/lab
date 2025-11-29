#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        struct TreeNode *treeNode = malloc(sizeof(struct TreeNode));

        treeNode->val = val;
        treeNode->left = NULL;
        treeNode->right = NULL;
        return treeNode;
    }
    else if (val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (val < root->val)
    {
        return searchBST(root->left, val);
    }
    else if (val > root->val)
    {
        return searchBST(root->right, val);
    }

    return root;
}


struct TreeNode* findMax(struct TreeNode* root) {
    if (root == NULL)
        return NULL;
    else if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
}


struct TreeNode* findMin(struct TreeNode* root) {
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return NULL;
    else if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else {
            struct TreeNode* inorderSuccessor = findMin(root->right);
            root->val = inorderSuccessor->val;
            root->right = deleteNode(root->right, inorderSuccessor->val);

            // struct TreeNode* inorderPredecessor = findMax(root->left);
            // root->val = inorderPredecessor->val;
            // root->left = deleteNode(root->left, inorderPredecessor->val);
        }
    }
    return root;
}