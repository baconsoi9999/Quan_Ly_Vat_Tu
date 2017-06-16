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
/*file stream*/
ofstream f1;//write stream

/*MAIN STRUCT - begin*/
struct Vattu{
	char MAVT[100];
	char TENVT[100];
	char DVT[100];
	int soluongton;				// dc them moi khi do la vat tu moi
};
struct DsVattu{
	int num=0;
	Vattu _vattu[100];
} DataVattu;
/*MAIN STRUCT - end*/
/*METHOD*/
void save_Vattu()
{
	f1.open("Data/DataVattu.data",ios::binary );
	f1.write((char*)&DataVattu, sizeof(DataVattu));
	f1.close();
}
void initdataVattu(){
	ifstream f;
	f.open("Data/DataVattu.data",ios::binary);
	f.read((char*)&DataVattu,sizeof(DataVattu));
	f.close();
}
void Insert(DsVattu &ds,int pos,Vattu vt )
{
	for(int i = ds.num;i > pos; i--){
		ds._vattu[i] = ds._vattu[i-1];
	}
	ds._vattu[pos] = vt;
	ds.num ++;
}
bool Find(DsVattu &ds, char p[])
{
	for(int i = 0;i < ds.num; i++){
		if(strcmp(ds._vattu[i].MAVT , p)==0) return true;
	}
	return false;
} 
void FindandInsert(DsVattu &ds,Vattu vt)
{
	if(Find(ds ,vt.MAVT)) return;
//	for(int i = 0; i < ds.num; i++){
//		bool flag = true;
	//	for(int j=0; j<100||j!='\0';j++)
//		if(strcmp(vt.TENVT[j],ds._vattu[i].TENVT[j])!=0){flag=false;break;}
//		if(flag) {
			for(int i=0;i<ds.num;i++){
				if(strcmp(ds._vattu[i].MAVT , vt.MAVT)>0){
					Insert(ds,i,vt);
					return ;
				}
			}
			Insert(ds,ds.num,vt);
			return ;
		//}
	
	cout<<"---ds.num---"<<ds.num<<endl;
	Insert(ds,ds.num,vt);
	return ;
}
Vattu addVattu()
{
	Vattu Va;
	string buff;
	cout<<">>Ma vat tu: ";
	fflush(stdin);
	getline(cin,buff);
	strcpy(Va.MAVT, buff.c_str());
	cout<<">>Ten vat tu: ";
	fflush(stdin);
	getline(cin,buff);
	strcpy(Va.TENVT, buff.c_str());
	cout <<">>Don vi tinh: ";
	fflush(stdin);
	getline(cin,buff);
	strcpy(Va.DVT, buff.c_str());
	cout<<">>So luong ton: ";
	cin>>Va.soluongton;
	return Va;
}
void nhapVattu()
{
	int n;
	cout <<">>input n: ";
	cin >>n;
//	DataVattu.num+=n;

	for(int i =0 ;i<n;i++)
	{
		Vattu vt = addVattu();
		// kiemtravt
		FindandInsert(DataVattu,vt);
	}
	
}

void deleteVattu(int n,DsVattu &ds){
	for(int i=n;i<ds.num-1;i++)
	{
		ds._vattu[i] = ds._vattu[i+1];
	}
	ds.num --;
}

void printVattu(Vattu Va,int x,int y,unsigned short int c_line[])
{
		outtextxy(x+c_line[0]+10,y,Va.MAVT);
		outtextxy(x+c_line[1]+10,y,Va.TENVT);
		outtextxy(x+c_line[2]+10,y,Va.DVT);
	
		string num= genericToString(Va.soluongton);
		int str_l=num.length();
		auto covert = new char[str_l+1];
		for(int i = 0; i <str_l;i++)
		covert[i]=num[i];
		covert[str_l]='\0';
		outtextxy(x+c_line[3]+10,y,covert);
}
void inconsole(){
	for(int i = 0;i<DataVattu.num;i++){
		cout<<DataVattu._vattu[i].MAVT<<endl;
	}
}
void lietkeVattu(DsVattu ds,int batdau, int ketthuc,int x,int y,int SPACE,unsigned short int c_line[])
{
	setbkcolor(getpixel(x+1,y+1));
	setcolor(0);
	for(int i = batdau ;i <= ketthuc ; i++)
	{
		printVattu(ds._vattu[i],x,SPACE+y+(i-batdau)*(16+ SPACE*2 + 1),c_line);	// liet ke theo trang 
	}
}

struct vattu_error{
	char* error_st[4];
	int error_color[4];
	bool check = true;
};
vattu_error Check_VT(Vattu &vt,char MaVT[], char TVT[], char Donvi[], char sluong[])
{
		vattu_error p;
		// xu li ma vat tu
		if(Find(DataVattu,MaVT)) {
			p.error_st[0] = "Vat tu da ton tai\0";
			p.check = false;
			p.error_color[0] = 4;
		}
		else if(strlen(MaVT)==0) {
			p.error_st[0] = "Khong duoc rong  \0";
			p.check = false;
			p.error_color[0] = 4;
		}
			else
			p.error_st[0] = "Co the su dung   \0",p.error_color[0] = COLOR(0,255,0);
		// xu li ten vat tu
		
			int len_TVT = strlen(TVT);
			if(len_TVT == 0) {
				p.error_st[1] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[1] = 4;
			}
			else p.error_st[1] = "Co the su dung \0",p.error_color[1] = COLOR(0,255,0);
			
		
		// xu li Don vi
		
			int len_DV = strlen(Donvi);
			if(len_DV == 0){
				p.error_st[2] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[2] = 4;
			}
			else p.error_st[2] = "Co the su dung \0",p.error_color[2] = COLOR(0,255,0);
		
		//xu li so luong
		
			int len_slt = strlen(sluong);
			if(len_slt == 0){
				p.error_st[3] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[3] = 4;
			}
			else p.error_st[3] = "Co the su dung \0",p.error_color[3] = COLOR(0,255,0);
				if(p.check == true){
			strcpy(vt.MAVT, MaVT);
			if(TVT[len_TVT-1] == ' ') TVT[len_TVT-1] = NULL;
			strcpy(vt.TENVT, TVT);
			if(Donvi[len_DV-1] == ' ') Donvi[len_DV-1] = NULL;
			strcpy(vt.DVT , Donvi);
			int num = 0;
			for(int i=0;i<len_slt ;i++){
				num = num*10 + (sluong[i] - '0');
			}
			vt.soluongton = num; 
		}
		return p;
}
