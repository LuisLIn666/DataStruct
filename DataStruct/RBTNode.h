/*************************************************************************************
 *
 * 文 件 名:   RBTNode.h
 * 描    述: 红黑树
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/11/15 22:21
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
typedef enum {RED =0,BLACK=1};

template <class T>
class RBTNode {
public:
    RBTColor color;    // 颜色
    T key;            // 关键字(键值)
    RBTNode* left;    // 左孩子
    RBTNode* right;    // 右孩子
    RBTNode* parent; // 父结点

    RBTNode(T value, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
        key(value), color(c), parent(), left(l), right(r) {}
};

