//
//  Error.h
//  后缀表达式
//
//  Created by Kyle.Yang on 14/12/2.
//  Copyright (c) 2014年 Kyle.Yang. All rights reserved.
//

#ifndef ______Error_h
#define ______Error_h

#include <iostream>
using namespace std;

class Error
{
protected:
    string name;
public:
    Error(string tempname="Default_Name")
    {
        this->name=tempname;
        cout<<"Error:"<<name<<endl;
    }
    
    virtual ~Error() {}
};

#endif
