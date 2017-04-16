#include <string>
#include <iostream>
#include <algorithm> // for testing
using namespace std;
const int _MAX  = 100; 

struct Vattu{
	string MAVT;
	string TENVT;
	string DVT;
	int soluongton;				// dc them moi khi do la vat tu moi
};

struct DsVattu{
	int num;
	Vattu _vattu[_MAX];
};

// xu li nhap, xoa , hieu chinh vat tu
Vattu Nhapvattu()
{
	Vattu Va;
	cout<<"Ma vat tu :";
	cin>>Va.MAVT;
	cout<<"Ten vat tu :";
	cin>>Va.TENVT;
	cout<<"Don vi tinh :";
	cin>>Va.DVT;
	cout<<"So luong ton :";
	cin>>Va.soluongton;
	return Va;
}
void Themvattu(DsVattu &ds)
{
	ds._vattu[ds.num] = Nhapvattu();
	ds.num++;
}
void Xoavattu(int n,DsVattu &ds)
{
	for(int i=n;i<ds.num-1;i++)
	{
		ds._vattu[i] = ds._vattu[i+1];
	}
	ds.num --;
}
void Hieuchinh(){
	
} 
void Xuatvattu(Vattu Va)
{
	cout<<"Ma vat tu :";
	cout<<Va.MAVT<<endl;
	cout<<"Ten vat tu :";
	cout<<Va.TENVT<<endl;
	cout<<"Don vi tinh :";
	cout<<Va.DVT<<endl;
	cout<<"So luong ton :";
	cout<<Va.soluongton<<endl;
}
void Lietkevattu(DsVattu ds)
{
	//eror	sort(ds._vattu,ds._vattu + ds.num ); //compare missing
	for(int i = 0 ;i < ds.num ; i++)
	{
		Xuatvattu(ds._vattu[i]);
	}
}
