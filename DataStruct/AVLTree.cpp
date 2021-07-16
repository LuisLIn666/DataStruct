/*************************************************************************************
 *
 * �� �� ��:   AVLTree.cpp
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/16 10:27
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
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
//������С��ƽ���������ڵ�
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
		// ����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
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
    // ��Ϊ�� ���� û��Ҫɾ���Ľڵ㣬ֱ�ӷ���NULL��
    if (tree == nullptr || z == nullptr)
        return nullptr;

    if (z->key < tree->key)        // ��ɾ���Ľڵ���"tree��������"��
    {
        tree->lchild = remove(tree->lchild, z);
        // ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
        if (height(tree->rchild) - height(tree->lchild) == 2)
        {
            AVLTreeNode<T>* r = tree->rchild;
            if (height(r->lchild) > height(r->rchild))
                tree = rightLeftRotation(tree);
            else
                tree = rightRightRotation(tree);
        }
    }
    else if (z->key > tree->key)// ��ɾ���Ľڵ���"tree��������"��
    {
        tree->rchild = remove(tree->rchild, z);
        // ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
        if (height(tree->lchild) - height(tree->rchild) == 2)
        {
            AVLTreeNode<T>* l = tree->lchild;
            if (height(l->rchild) > height(l->lchild))
                tree = leftRightRotation(tree);
            else
                tree = leftLeftRotation(tree);
        }
    }
    else    // tree�Ƕ�ӦҪɾ���Ľڵ㡣
    {
        // tree�����Һ��Ӷ��ǿ�
        if ((tree->left != nullptr) && (tree->right != nullptr))
        {
            if (height(tree->lchild) > height(tree->rchild))
            {
                // ���tree�����������������ߣ�
                // ��(01)�ҳ�tree���������е����ڵ�
                //   (02)�������ڵ��ֵ��ֵ��tree��
                //   (03)ɾ�������ڵ㡣
                // ����������"tree�������������ڵ�"��"tree"������
                // �������ַ�ʽ�ĺô��ǣ�ɾ��"tree�������������ڵ�"֮��AVL����Ȼ��ƽ��ġ�
                AVLTreeNode<T>* max = maximum(tree->lchild);
                tree->key = max->key;
                tree->lchild = remove(tree->lchild, max);
            }
            else
            {
                // ���tree��������������������(��������ȣ�������������������1)
                // ��(01)�ҳ�tree���������е���С�ڵ�
                //   (02)������С�ڵ��ֵ��ֵ��tree��
                //   (03)ɾ������С�ڵ㡣
                // ����������"tree������������С�ڵ�"��"tree"������
                // �������ַ�ʽ�ĺô��ǣ�ɾ��"tree������������С�ڵ�"֮��AVL����Ȼ��ƽ��ġ�
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
