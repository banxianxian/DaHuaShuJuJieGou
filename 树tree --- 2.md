# 树tree --- 2

#### 二叉树的遍历

前序，中序，后序遍历方式指的是 根节点的遍历位置

二叉树的节点设置

```c++
template<typename T>
struct Node {
    T data;
    Node* lChild;
    Node* rChild;
};
```



###### 1.前序遍历

**根节点 -->  左子树 --> 右子树**

实现代码（递归）

```c++
template<typename T>
void PreOrderTraverse(Node<T>* temp) {
    if (temp == nullptr) {
        return;
    }
    cout << setw(4) << temp->data;
    PreOrderTraverse(temp->lChild);
    PreOrderTraverse(temp->rChild);
}
```



###### 2.中序遍历

 **左子树 -->  根节点 --> 右子树**

实现代码（递归）

```c++
template<typename T>
void inOrderTraverse(Node<T>* temp) {
    if (temp == nullptr) {
        return;
    }
   
    inOrderTraverse(temp->lChild);
    cout << setw(4) << temp->data;
    inOrderTraverse(temp->rChild);
}
```



###### 3.后序遍历

 **左子树 --> 右子树 --> 根节点**

实现代码（递归）

```c++
template<typename T>
void PostOrderTraverse(Node<T>* temp) {
    if (temp == nullptr) {
        return;
    }
    PostOrderTraverse(temp->lChild);
    PostOrderTraverse(temp->rChild);
    cout << setw(4) << temp->data;
}
```

