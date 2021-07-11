#pragma once
//二叉树链式定义
#include "common.h"

typedef struct BiTNode
{
	ElemType data;
	BiTNode* rchild, * lchild;
}BiTNode,*BiTree;

class TreeMethod
{
public:
	//初始化一棵树
	BiTNode* InitTree();
	

	//访问该节点
	void visit(BiTree T);
	

	//递归中序遍历一棵树
	void InOrderTraverseRecursive(BiTree T);
	
	//递归前序遍历一棵树
	void PreOrderTraverseRecursive(BiTree T);

	//递归后序遍历一棵树
	void PostTraverseRecursive(BiTree T);
};

