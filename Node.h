//
//  Node.h
//  后缀表达式
//
//  Created by Kyle.Yang on 14/12/2.
//  Copyright (c) 2014年 Kyle.Yang. All rights reserved.
//

#ifndef ______Node_h
#define ______Node_h

#include <stdio.h>
#include <iostream>
using namespace std;

template <class ElemType>
struct Node
{
    //数据成员
    ElemType data;
    Node<ElemType> *next;
    
    //构造函数
    Node()
    {
        next=NULL;
    }
    
    Node(ElemType e,Node<ElemType> *link=NULL)
    {
        data=e;
        next=link;
    }
    
};

#endif
