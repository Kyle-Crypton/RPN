//
//  function.cpp
//  后缀表达式
//
//  Created by Kyle.Yang on 14/12/2.
//  Copyright (c) 2014年 Kyle.Yang. All rights reserved.
//


#include "LinkStack.h"
#include "Error.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

bool IsOperator(char ch)
{
    if(ch=='#' || ch=='(' || ch=='^' || ch=='*' || ch=='/' || ch=='+' || ch=='-' || ch==')')
        return true;
    else
        return false;
}

int OperPrior(char op1,char op2)
{
    int prior=0;
    switch (op1) {
        case '+':
        case '-':
            if(op2=='+' || op2=='-' || op2==')' || op2=='#')
                prior=2;
            else
                prior=1;
            break;
        case '*':
        case '/':
        case '^':
            if(op2=='^' || op2=='(')
                prior=1;
            else
                prior=2;
            break;
        case '(':
            if(op2==')')
                prior=0;
            else if(op2=='#')
                prior=-1;
            else
                prior=1;
            break;
        case ')':
            if(op2=='(')
                prior=-1;
            else
                prior=2;
            break;
        case '#':
            if(op2==')')
                prior=-1;
            else if(op2=='#')
                prior=3;
            else
                prior=1;
            break;
    }
    
    return prior;
}

double Operate(double first,char ch,double second)
{
    switch(ch){
        case '+':
            return first+second;
            break;
        case '-':
            return first-second;
            break;
        case '*':
            return first*second;
            break;
        case '/':
            return first/second;
            break;
        case '^':
            return pow(first,second);
            break;
    }
    return 0;
}

void InfixInToPostfix()
{
    LinkStack<char> optr;
    char ch;
    char priorChar;
    char op='#';
    double operand;
    int operandCount=0;
    
    optr.Push('#');
    priorChar='#';
    
    getchar();
    cout<<"Enter the Infix, end with '#': ";
    ch=getchar();
    while(op!='#' || ch!='#')
    {
        if(isdigit(ch) || ch=='.')
        {
            if(priorChar=='0' || priorChar==')')
                throw Error("Missing operator!");
            cin.putback(ch);
            cin>>operand;
            cout<<operand<<" ";
            operandCount++;
            priorChar='0';
            ch=getchar();
        }
        else if(!IsOperator(ch))
        {
            throw Error("Illegal symbols in the expression!");
        }
        else
        {
            if(ch=='(' && (priorChar=='0' || priorChar == ')'))
                throw Error("Missing operator before '('!");
            while(OperPrior(op,ch)==2)
            {
                if(operandCount<2)
                    throw Error("Missing operand!");
                operandCount--;
                optr.Pop(op);
                cout<<op<<" ";
                if(optr.IsEmpty())
                    throw Error("Missing operator!");
                optr.Top(op);
            }
            switch (OperPrior(op,ch)) {
                case -1:
                    throw Error("Mismatched braces!");
                    break;
                case 0:
                    optr.Pop(op);
                    if(optr.IsEmpty())
                        throw Error("Missing operator!");
                    priorChar=ch;
                    ch=getchar();
                    break;
                case 1:
                    optr.Push(ch);
                    op=ch;
                    priorChar=ch;
                    ch=getchar();
                    break;
            }
        }
    }
    if(operandCount!=1)
        throw Error("Missing operand!");
    cout<<endl;
};

void PostfixExpressionCalculation()
{
    LinkStack<double> opnd;
    char ch;
    double operand,first,second;
    getchar();
    cout<<"Enter the RPN, end with '#': ";
    ch=getchar();
    while(ch!='#')
    {
        if(isdigit(ch) || ch=='.')
        {
            cin.putback(ch);
            cin>>operand;
            opnd.Push(operand);
        }
        else if((!IsOperator(ch) || ch=='(' || ch==')') && (ch!=' '))
        {
            throw Error("Illegal symbols in the expression!");
        }
        else if(ch!=' ')
        {
            if(opnd.IsEmpty())
                throw Error("Missing operand!");
            opnd.Pop(second);
            if(opnd.IsEmpty())
                throw Error("Missing operand!");
            opnd.Pop(first);
            opnd.Push(Operate(first,ch,second));
        }
        ch=getchar();
    }
    if(opnd.IsEmpty())
        throw Error("Missing operand!");
    opnd.Pop(operand);
    if(!opnd.IsEmpty())
        throw Error("Missing operator!");
    cout<<"The result is:"<<operand<<endl;
};

void system()
{
    int choice;
    
    cout<<"RPN beta V1.0"<<endl;
    cout<<"1.Calculate RPN 2.Infix to RPN 0:Exit System"<<endl;
    cout<<"Copyright by Kyle_Crypton"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    while(choice!=0)
    {
        if(choice==1)
            PostfixExpressionCalculation();
        else if(choice==2)
            InfixInToPostfix();
        else
            cout<<"Wrong input!"<<endl;
        
        cout<<"Enter your choice:";
        cin>>choice;
    }
};
