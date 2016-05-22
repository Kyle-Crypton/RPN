//
//  LinkStack.h
//  后缀表达式
//
//  Created by Kyle.Yang on 14/12/2.
//  Copyright (c) 2014年 Kyle.Yang. All rights reserved.
//

#ifndef ______LinkStack_h
#define ______LinkStack_h

#include "Node.h"
#include <stdio.h>
#include <iostream>
using namespace std;

template <class ElemType>
class LinkStack
{
protected:
    Node<ElemType> *top;
    
public:
    LinkStack()
    {
        top=NULL;
    }
    
    virtual ~LinkStack()
    {
        Clear();
    }
    
    void Clear()
    {
        Node<ElemType> *p;
        while(top!=NULL)
        {
            p=top;
            top=top->next;
            delete p;
        }
    }
    
    bool IsEmpty() const
    {
        if(top==NULL)
            return true;
        else
            return false;
    }
    
    void Push(const ElemType e)
    {
        Node<ElemType> *p=new Node<ElemType>(e,top);
        if(p==NULL)
            cout<<"OVER_FLAW";
        else
        {
            top=p;
            //cout<<"Success";
        }
    }
    
    void Top(ElemType &e) const
    {
        if(IsEmpty())
            cout<<"UNDER_FLAW";
        else
        {
            e=top->data;
            //cout<<"Success";
        }
    }
    
    void Pop(ElemType &e)
    {
        if(IsEmpty())
            cout<<"OVER_FLAW";
        else
        {
            Node<ElemType> *p=top;
            e=top->data;
            top=top->next;
            delete p;
            //cout<<"Success";
        }
    }
    
};

#endif
