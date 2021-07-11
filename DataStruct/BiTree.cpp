#include "BiTree.h"

BiTNode* TreeMethod::InitTree()
{
	try
	{
		BiTree p = new BiTNode;
		return p;
	}
	catch (const std::exception& e)
	{
		cout << e.what();
		exit(-1);
	}
		
	
}

void TreeMethod::visit(BiTree T)
{
	cout << T->data << endl;

}

void TreeMethod::InOrderTraverseRecursive(BiTree T)
{
	if (T)
	{
		InOrderTraverseRecursive(T->lchild);
		visit(T);
		InOrderTraverseRecursive(T->rchild);
	}
	
}

void TreeMethod::PreOrderTraverseRecursive(BiTree T)
{
	if (T)
	{
		visit(T);
		PreOrderTraverseRecursive(T->lchild);
		PreOrderTraverseRecursive(T->rchild);
	}
}
void TreeMethod::PostTraverseRecursive(BiTree T)
{
	if (T)
	{
		
		PostTraverseRecursive(T->lchild);
		PostTraverseRecursive(T->rchild);
		visit(T);
	}
}

