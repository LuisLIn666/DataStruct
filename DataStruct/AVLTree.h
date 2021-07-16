/*************************************************************************************
 *
 * �� �� ��:   AVLTree.h
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
#pragma once
#include "AVLTreeNode.h"
template<class T>
class AVLTree
{
private:
	AVLTreeNode<T>* root;    // �����

public:
    AVLTree();
    ~AVLTree();

 
    // ��ȡ���ĸ߶�
     int height();
     //�Ƚϴ�С
     int max(int a, int b);
    // ǰ�����"AVL��"
    void preOrder();
    // �������"AVL��"
    void inOrder();
    // �������"AVL��"
    void postOrder();

    // (�ݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
    AVLTreeNode<T>* search(T key);
    // (�ǵݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
    AVLTreeNode<T>* iterativeSearch(T key);

    // ������С��㣺������С���ļ�ֵ��
    T minimum();
    // ��������㣺���������ļ�ֵ��
    T maximum();

    // �����(keyΪ�ڵ��ֵ)���뵽AVL����
    void insert(T key);

    // ɾ�����(keyΪ�ڵ��ֵ)
    void remove(T key);

    // ����AVL��
    void destroy();

    // ��ӡAVL��
    void print();
private:
    // ��ȡ���ĸ߶�
    int height(AVLTreeNode<T>* tree);

    // ǰ�����"AVL��"
    void preOrder(AVLTreeNode<T>* tree) const;
    // �������"AVL��"
    void inOrder(AVLTreeNode<T>* tree) const;
    // �������"AVL��"
    void postOrder(AVLTreeNode<T>* tree) const;

    // (�ݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
    AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key) const;
    // (�ǵݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
    AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* x, T key) const;

    // ������С��㣺����treeΪ������AVL������С��㡣
    AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);
    // ��������㣺����treeΪ������AVL��������㡣
    AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

    // LL�������Ӧ�����(����ת)��
    AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);

    // RR�����Ҷ�Ӧ�����(�ҵ���ת)��
    AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);

    // LR�����Ҷ�Ӧ�����(��˫��ת)��
    AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);

    // RL�������Ӧ�����(��˫��ת)��
    AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);

    // �����(z)���뵽AVL��(tree)��
    AVLTreeNode<T>* insert(AVLTreeNode<T>*& tree, T key);

    // ɾ��AVL��(tree)�еĽ��(z)�������ر�ɾ���Ľ��
    AVLTreeNode<T>* remove(AVLTreeNode<T>*& tree, AVLTreeNode<T>* z);

    // ����AVL��
    void destroy(AVLTreeNode<T>*& tree);

    // ��ӡAVL��
    void print(AVLTreeNode<T>* tree, T key, int direction);
};


