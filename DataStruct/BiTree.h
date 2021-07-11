#pragma once
//��������ʽ����
#include "common.h"

typedef struct BiTNode
{
	ElemType data;
	BiTNode* rchild, * lchild;
}BiTNode,*BiTree;

class TreeMethod
{
public:
	//��ʼ��һ����
	BiTNode* InitTree();
	

	//���ʸýڵ�
	void visit(BiTree T);
	

	//�ݹ��������һ����
	void InOrderTraverseRecursive(BiTree T);
	
	//�ݹ�ǰ�����һ����
	void PreOrderTraverseRecursive(BiTree T);

	//�ݹ�������һ����
	void PostTraverseRecursive(BiTree T);
};

