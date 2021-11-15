/*************************************************************************************
 *
 * �� �� ��:   RBTNode.h
 * ��    ��: �����
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/11/15 22:21
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
typedef enum {RED =0,BLACK=1};

template <class T>
class RBTNode {
public:
    RBTColor color;    // ��ɫ
    T key;            // �ؼ���(��ֵ)
    RBTNode* left;    // ����
    RBTNode* right;    // �Һ���
    RBTNode* parent; // �����

    RBTNode(T value, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
        key(value), color(c), parent(), left(l), right(r) {}
};

