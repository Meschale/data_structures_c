// ch05_07.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
using namespace std;
class myclass {
private: int x;
public:
myclass (int n=20) {x=n;} //use default argument instead of overloading
int getx() {return x;}
};
int main()
{
myclass o1(10);// declare with initial value.
myclass o2;//declare without initializer.
cout<<"o1: "<<o1.getx()<<endl;
cout<<"o2: "<<o2.getx()<<endl;
}
