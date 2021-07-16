/*************************************************************************************
 *
 * 文 件 名:   BiTree.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/11 17:07
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "BiTree.h"
#include "BitNode.h"
#include <deque>
#include <stack>

BiTree::BiTree()
{
	root = nullptr;
	high = 0;
}

void BiTree::visit(BitNode* T)
{
	cout << " " << T->data << " ";
}


void BiTree::inOrder(BitNode* T)
{
	if (T)
	{
		inOrder(T->lchild);
		BiTree::visit(T);
		
		inOrder(T->rchild);
	}
}

void BiTree::preOrder(BitNode*T)
{
	if (T)
	{
		BiTree::visit(T);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void BiTree::postOrder(BitNode* T)
{

	if (T)
	{
		postOrder(T->lchild);
		postOrder(T->rchild);
		BiTree::visit(T);
		
	}
}



BitNode* BiTree::setRoot(ElemType e)
{
	if (!root)
	{
		root = new BitNode(e);
		root->data = e;
		return root;

	}
	else
	{
		throw
			"根已经存在";
	}
}



BitNode* BiTree::getRoot()
{
	// TODO: 在此处插入 return 语句
	if (root)
	{
		return this->root;
	}
	else
	{
		throw "root is null";
	}
	
}

BiTree& BiTree::getTree()
{
	return *this;
}

void BiTree::insertNewNode(ElemType e)
{
	if (!root)
	{
		throw "error";
	}
	deque<BitNode*> deq;
	auto p = root;

	deq.push_back(p);
	while (deq.empty())
	{
		auto q = deq.front();
		if (!q->lchild)
		{
			q->lchild = new BitNode(e);
			break;
		}

		if (q->lchild)
		{
			deq.push_back(q->lchild);
			if (!q->rchild)
			{
				q->rchild = new BitNode(e);
				break;
			}

		}
		else if(q->rchild)
		{
			deq.push_back(q->rchild);
		}
		
		deq.pop_front();
	}

}

int BiTree::getHigh(BitNode* T)
{
	if (!T)
	{
		return 0;
	}
	auto m = getHigh(T->lchild);
	auto n= getHigh(T->rchild);
	return m > n ? m + 1 : n + 1;
}

void BiTree::preOrdernorecursion(BitNode* T)
{
	if (!T)
	{
		throw "Error";
	}

	stack<BitNode*> STACK;
	auto q = T;
	STACK.push(q);
	while (!STACK.empty()||q)
	{
		
		while (q)
		{
			visit(q);
			STACK.push(q);
			q=q->lchild;
		}
		if (!STACK.empty())
		{
			auto p = STACK.top();
			q = p->rchild;
			STACK.pop();
		}
	}
	
}

void BiTree::inOrdernorecursion(BitNode* T)
{
	if (!T)
	{
		throw "Error";
	}

	stack<BitNode*> STACK;
	auto p = T;
	
	while (!STACK.empty() || p)
	{
		if (p)
		{
			STACK.push(p);
			p = p->lchild;
		}
		else
		{
			auto p = STACK.top();
			visit(p);
			STACK.pop();
			p = p->rchild;

		}
	}
}

void BiTree::postOrdernorecursion(BitNode* T)
{
	if (!T)
	{
		throw "Error";
	}

	stack<BitNode*> STACK;
	auto p = T;

	while (!STACK.empty() || p)
	{
		if (p)
		{
			STACK.push(p);
			p = p->lchild;

		}
		else 
		{
			p = STACK.top();
			if (!p->rchild)
			{
				visit(p);
				STACK.pop();
			}
			else
			{
				p = p->rchild;
			}
			
			
		}
	}
}
