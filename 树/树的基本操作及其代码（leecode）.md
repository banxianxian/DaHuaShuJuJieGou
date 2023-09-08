# 二叉树的基本操作及其代码（leecode）

#### 求（节点）最大深度（高度）

```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


```

#### 求（节点）最小深度（高度）

```c++
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
};
```

#### 遍历树

```c++
//前序遍历

void PreOrderTraverse(TreeNode* root) {
    if (temp == nullptr) {
        return;
    }
    /*
    遍历时需要进行的操作
    */
    PreOrderTraverse(temp->lChild);
    PreOrderTraverse(temp->rChild);
}

//中序遍历

void PreOrderTraverse(TreeNode* root) {
    if (temp == nullptr) {
        return;
    }
    PreOrderTraverse(temp->lChild);
    /*
    遍历时需要进行的操作
    */
    PreOrderTraverse(temp->rChild);
}


//后序遍历

void PreOrderTraverse(TreeNode* root) {
    if (temp == nullptr) {
        return;
    }
    PreOrderTraverse(temp->lChild);
    PreOrderTraverse(temp->rChild);
     /*
    遍历时需要进行的操作
    */
}
```

#### 检查树的对称

```c++
//root1 与 root2 在传参时均为 root

bool dfs(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) {
            return true;
        }

        if(root1 == nullptr || root2 == nullptr || root1 -> val != root2 ->val) {
            return false;
        }
    
       return  dfs(root1 -> left, root2 -> right)&&dfs(root1 -> right, root2 ->left);


    }
```

