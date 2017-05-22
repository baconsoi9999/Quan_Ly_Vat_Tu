#include <iostream>
#include <winbgim.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
template <typename T>
std::string genericToString(const T& t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}
//freopen("Vattu_Base.txt","r",stdin);
//freopen("Vattu_Base.txt","w",stdout);
struct Vattu{
	string MAVT;
	string TENVT;
	string DVT;
	int soluongton;				// dc them moi khi do la vat tu moi
};

struct DsVattu{
	int num;
	Vattu _vattu[100];
};
void Insert(DsVattu&,int,Vattu);
void FindandInsert(DsVattu&,Vattu);
bool Find(DsVattu&,string);
void addVattu(DsVattu&);
void deleteVattu(int,DsVattu&);
void printVattu(Vattu);
//void Hieuchinh();
// xu li nhap, xoa , hieu chinh vat tu
void Insert(DsVattu &ds,int pos,Vattu p ){
	for(int i = ds.num;i > pos; i--){
		ds._vattu[i] = ds._vattu[i-1];
	}
	ds._vattu[pos] = p;
	ds.num ++;
}
void FindandInsert(DsVattu &ds,Vattu p){
	for(int i = 0; i < ds.num; i++){
		if(ds._vattu[i].TENVT.compare(p.TENVT) ) {
			Insert(ds,i,p);
			return;
		}
	}
	Insert(ds,ds.num,p);
}
Vattu addVattu()
{
	Vattu Va;
	
	
	cout<<"Nhap ma vat tu";
	cin>>Va.MAVT;
	cout<<"Ten vat tu :";
	cin>>Va.TENVT;
	cout<<"Don vi tinh :";
	cin>>Va.DVT;
	cout<<"So luong ton :";
	cin>>Va.soluongton;
	return Va;
}
void deleteVattu(int n,DsVattu &ds){
	for(int i=n;i<ds.num-1;i++)
	{
		ds._vattu[i] = ds._vattu[i+1];
	}
	ds.num --;
}
void Hieuchinh(){
	
}
bool Find(DsVattu &ds, string p){
	for(int i = 0;i < ds.num; i++){
		if(ds._vattu[i].MAVT == p) return false;
	}
	return true;
} 
void printVattu(Vattu Va,int x,int y)
{
	int str_l=Va.MAVT.length();
	char* covert =new char[str+1];
	for(int i = 0; i <str_l;i++)
	covert[i]=Va.MAVT[i];
	covert[str_l]='\0';
	outtextxy(x+65,y,cover,covert);
	str_l=Va.TENVT.length();
	covert = new char[str_l+1];
	for(int i = 0; i <str_l;i++)
	covert[i]=Va.TENVT[i];
	covert[str_l]='\0';
	outtextxy(x+337,y,covert);
	str_l=Va.DVT.length();
	covert = new char[str_l+1];
	for(int i = 0; i <str_l;i++)
	covert[i]=Va.DVT[i];
	covert[str_l]='\0';
	outtextxy(x+721,y,covert);
	string x= genericToString(Va.soluongton);
	str_l=x.length();
	covert = new char[str_l+1];
	for(int i = 0; i <str_l;i++)
	covert[i]=x[i]
	covert[str_l]='\0';
	outtextxy(x+993,y,covert);
}
void lietkeVattu(DsVattu ds,int batdau, int ketthuc,int x,int y,int SPACE)
{
	//eror	sort(ds._vattu,ds._vattu + ds.num ); //compare missing
	for(int i = batdau ;i <= ketthuc ; i++)
	{
		Xuatvattu(ds._vattu[i],x,y+(i-batdau)*(SPACE+textheight("s")+1));	// liet ke theo trang 
	}
}
