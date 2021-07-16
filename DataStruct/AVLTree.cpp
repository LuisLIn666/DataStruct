/*************************************************************************************
 *
 * 文 件 名:   AVLTree.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/16 10:27
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "AVLTree.h"
#include "AVLTreeNode.h"
template<class T>
void AVLTree<T>::remove(T key)
{
	AVLTreeNode<T>* z;

	if ((z = search(root, key)) != nullptr)
		root= remove(root, z);
}
template<class T>
inline int AVLTree<T>::height(AVLTreeNode<T>* tree)
{
	if (tree)
		return tree->height;
	return 0;
}

template<class T>
int  AVLTree<T>::height()
{
	return height(root);
}

template<class T>
int AVLTree<T>::max(int a, int b)
{
	return a>b?a:b;
}
//传入最小不平衡子树根节点
template<class T>
inline AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
	
	AVLTreeNode<T>* k1;

	k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;

	k2->height = max(height(k2->lchild), height(k2->rchild)) + 1;
	k1->height = max(height(k1->lchild), k2->height) + 1;

	return k2;
}

template<class T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>* k1)
{
	AVLTreeNode<T> k2 = k1->rchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;
	k2->height = max(height(k2->lchild), height(k2->rchild)) + 1;
	k1->height = max(height(k1->lchild), k2->height) + 1;
	return k1;
}

template<class T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* k3)
{
	k3->lchild = rightRightRotation(k3->rchild);

	return leftLeftRotation(k3);
}

template<class T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k1)
{
	k1->rchild = leftLeftRotation(k1->rchild);

	return rightRightRotation(k1);
}

template<class T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &tree, T key)
{
	if (!tree)
	{
		tree = new AVLTreeNode<T>(key, nullptr, nullptr);
		if (!tree)
		{
			throw "ERROR: create avltree node failed!";
		}
	}
	else if (key < tree->key)
	{
		tree->lchild = insert(tree->lchild, key);
		if (height(tree->lchild) - height(tree->rchild) == 2)
		{
			if (key < tree->left->key)
				tree = leftLeftRotation(tree);
			else
				tree = leftRightRotation(tree);
		}
	}
	else if (key > tree->key)
	{
		tree->rchild = insert(tree->rchild, key);
		// 插入节点后，若AVL树失去平衡，则进行相应的调节。
		if (height(tree->rchild) - height(tree->lchild) == 2)
		{
			if (key > tree->rchild->key)
				tree = rightRightRotation(tree);
			else
				tree = rightLeftRotation(tree);
		}
	}
	else
	{
		throw "cannot inser the same node";
	}
	tree->height = max(height(tree->lchild), height(tree->rchild)) + 1;
	return tree;
}

template<class T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>*& tree, AVLTreeNode<T>* z)
{
    // 根为空 或者 没有要删除的节点，直接返回NULL。
    if (tree == nullptr || z == nullptr)
        return nullptr;

    if (z->key < tree->key)        // 待删除的节点在"tree的左子树"中
    {
        tree->lchild = remove(tree->lchild, z);
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if (height(tree->rchild) - height(tree->lchild) == 2)
        {
            AVLTreeNode<T>* r = tree->rchild;
            if (height(r->lchild) > height(r->rchild))
                tree = rightLeftRotation(tree);
            else
                tree = rightRightRotation(tree);
        }
    }
    else if (z->key > tree->key)// 待删除的节点在"tree的右子树"中
    {
        tree->rchild = remove(tree->rchild, z);
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if (height(tree->lchild) - height(tree->rchild) == 2)
        {
            AVLTreeNode<T>* l = tree->lchild;
            if (height(l->rchild) > height(l->lchild))
                tree = leftRightRotation(tree);
            else
                tree = leftLeftRotation(tree);
        }
    }
    else    // tree是对应要删除的节点。
    {
        // tree的左右孩子都非空
        if ((tree->left != nullptr) && (tree->right != nullptr))
        {
            if (height(tree->lchild) > height(tree->rchild))
            {
                // 如果tree的左子树比右子树高；
                // 则(01)找出tree的左子树中的最大节点
                //   (02)将该最大节点的值赋值给tree。
                //   (03)删除该最大节点。
                // 这类似于用"tree的左子树中最大节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
                AVLTreeNode<T>* max = maximum(tree->lchild);
                tree->key = max->key;
                tree->lchild = remove(tree->lchild, max);
            }
            else
            {
                // 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
                // 则(01)找出tree的右子树中的最小节点
                //   (02)将该最小节点的值赋值给tree。
                //   (03)删除该最小节点。
                // 这类似于用"tree的右子树中最小节点"做"tree"的替身；
                // 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
                AVLTreeNode<T>* min = maximum(tree->rchild);
                tree->key = min->key;
                tree->rchild = remove(tree->rchild, min);
            }
        }
        else
        {
            AVLTreeNode<T>* tmp = tree;
            tree = (tree->lchild != nullptr) ? tree->lchild : tree->rchild;
            delete tmp;
        }
    }

    return tree;
}
