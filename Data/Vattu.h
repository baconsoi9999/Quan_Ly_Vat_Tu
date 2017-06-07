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
fstream f1;

struct Vattu{
	string MAVT;
	string TENVT;
	string DVT;
	int soluongton;				// dc them moi khi do la vat tu moi
};

struct DsVattu{
	int num=0;
	Vattu _vattu[100];
} DataVattu;

void initdataVattu(){
	f1.open("DataVattu.txt",ios::in|ios::binary);
	f1.read((char*)&DataVattu,sizeof(DataVattu));
	f1.close();
}
void Insert(DsVattu &ds,int pos,Vattu vt ){
	for(int i = ds.num;i > pos; i--){
		ds._vattu[i] = ds._vattu[i-1];
	}
	ds._vattu[pos] = vt;
	ds.num ++;
}
bool Find(DsVattu &ds, string p){
	for(int i = 0;i < ds.num; i++){
		if(ds._vattu[i].MAVT == p) return true;
	}
	return false;
} 
bool FindandInsert(DsVattu &ds,Vattu vt){
	if(Find(ds ,vt.MAVT)) return false;
	for(int i = 0; i < ds.num; i++){
		if(ds._vattu[i].TENVT.compare(vt.TENVT)>0 ) {
			Insert(ds,i,vt);
			return true;
		}
	}
	cout<<"---ds.num---"<<ds.num<<endl;
	Insert(ds,ds.num,vt);
	return true;
}
Vattu addVattu()
{
	Vattu Va;
	cout<<"Nhap ma vat tu: ";
	fflush(stdin);
	getline(cin,Va.MAVT);
	cout<<"Ten vat tu: ";
	fflush(stdin);
	getline(cin,Va.TENVT);
	cout<<"Don vi tinh: ";
	fflush(stdin);
	getline(cin,Va.DVT);
	cout<<"So luong ton: ";
	cin>>Va.soluongton;
	return Va;
}
void nhapVattu()
{
	int n;
	cout <<"input n: ";
	cin >>n;
	DataVattu.num+=n;
	f1.open("DataVattu.txt",ios::app|ios::binary );

	for(int i =0 ;i<n;i++){
		Vattu vt = addVattu();
		// kiemtravt
		FindandInsert(DataVattu,vt);
	}
//	f1.write( (char*)&DataVattu, sizeof(DataVattu) );
//	f1.close();
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
void printVattu(Vattu Va,int x,int y)
{
	int str_l=Va.MAVT.length();
	char* covert =new char[str_l+1];
	for(int i = 0; i <str_l;i++)
	covert[i]=Va.MAVT[i];
	covert[str_l]='\0';
	outtextxy(x+65,y,covert);
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
	string num= genericToString(Va.soluongton);
	str_l=num.length();
	covert = new char[str_l+1];
	for(int i = 0; i <str_l;i++)
	covert[i]=num[i];
	covert[str_l]='\0';
	outtextxy(x+993,y,covert);
}
void inconsole(){
	for(int i = 0;i<DataVattu.num;i++){
		cout<<DataVattu._vattu[i].MAVT<<endl;
	}
}
void lietkeVattu(DsVattu ds,int batdau, int ketthuc,int x,int y,int SPACE)
{
	//eror	sort(ds._vattu,ds._vattu + ds.num ); //compare missing
	for(int i = batdau ;i <= ketthuc ; i++)
	{
		printVattu(ds._vattu[i],x,SPACE+y+(i-batdau)*(SPACE+textheight("s")+1));	// liet ke theo trang 
	}
}
