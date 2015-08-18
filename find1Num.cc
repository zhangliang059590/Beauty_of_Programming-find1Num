/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file find1Num.cc
 * @author cscc(cscc@baidu.com)
 * @date 2015/08/18 01:42:29
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

int count1_methord1(unsigned int number){
    cout<<"methord1:"<<endl;
    unsigned int tmp;
    unsigned int count = 0;
    while(number>0){
        tmp = number%2;
        if(tmp==1){
            ++count;
        }
        number = number/2;
    }
    return count;
}


int count1_methord2(unsigned int number){
    cout<<"methord2:"<<endl;
    unsigned int count = 0;
    while(number>0){
        if(number & 1){
            count += 1;
        }
        number >>= 1;
    }
    return count;
}

int count1_methord3(unsigned int number){
    cout<<"methord3:"<<endl;
    unsigned int count = 0;
    while(number){
        count += 1;
        number &= number-1;
    }
    return count;
}

int main(){
    unsigned int input;
    cin>>input;
    clock_t start, end;
    int count; 
    start = clock();
    count = count1_methord1(input);
    end = clock();
    cout<<"number of 1 in binary:"<<count<<endl;
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<"sec"<<endl;

    start = clock();
    count = count1_methord2(input);
    end = clock();
    cout<<"number of 1 in binary:"<<count<<endl;
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<"sec"<<endl;

    start = clock();
    count = count1_methord2(input);
    end = clock();
    cout<<"number of 1 in binary:"<<count<<endl;
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<"sec"<<endl;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
