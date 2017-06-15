#include <iostream>
using namespace std;
struct NodeCT{
	char MAVT[100];
	char soluong[100];
	char Dongia[100];
	char VAT[100];
	NodeCT* _next;
};
struct CT_HOADON{
	NodeCT* ctHead;
};

