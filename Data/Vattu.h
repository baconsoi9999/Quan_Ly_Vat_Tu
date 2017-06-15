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
void initdataVattu(){
	ifstream f;
	f.open("Data/DataVattu.data",ios::binary);
	f.read((char*)&DataVattu,sizeof(DataVattu));
	f.close();
}

void Insert(DsVattu &ds,int pos,Vattu vt ){
	for(int i = ds.num;i > pos; i--){
		ds._vattu[i] = ds._vattu[i-1];
	}
	ds._vattu[pos] = vt;
	ds.num ++;
}
bool Find(DsVattu &ds, char p[100]){
	for(int i = 0;i < ds.num; i++){
		if(strcmp(ds._vattu[i].MAVT , p)==0) return true;
	}
	return false;
} 
bool FindandInsert(DsVattu &ds,Vattu vt){
	if(Find(ds ,vt.MAVT)) return false;
//	for(int i = 0; i < ds.num; i++){
//		bool flag = true;
	//	for(int j=0; j<100||j!='\0';j++)
//		if(strcmp(vt.TENVT[j],ds._vattu[i].TENVT[j])!=0){flag=false;break;}
//		if(flag) {
			for(int i=0;i<ds.num;i++){
				if(strcmp(ds._vattu[i].MAVT , vt.MAVT)>0){
					Insert(ds,i,vt);
					return true;
				}
			}
			Insert(ds,ds.num,vt);
			return true;
		//}
	
	cout<<"---ds.num---"<<ds.num<<endl;
	Insert(ds,ds.num,vt);
	return true;
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
//	int str_l=Va.MAVT.length();
//	char* covert =new char[str_l+1];
//	for(int i = 0; i <str_l;i++)
//	covert[i]=Va.MAVT[i];
//	covert[str_l]='\0';
//	outtextxy(x+65,y,covert);
//	str_l=Va.TENVT.length();
//	covert = new char[str_l+1];
//	for(int i = 0; i <str_l;i++)
//	covert[i]=Va.TENVT[i];
//	covert[str_l]='\0';
//	outtextxy(x+337,y,covert);
//	str_l=Va.DVT.length();
//	covert = new char[str_l+1];
//	for(int i = 0; i <str_l;i++)
//	covert[i]=Va.DVT[i];
//	covert[str_l]='\0';
//	outtextxy(x+721,y,covert);
//	string num= genericToString(Va.soluongton);
//	str_l=num.length();
//	covert = new char[str_l+1];
//	for(int i = 0; i <str_l;i++)
//	covert[i]=num[i];
//	covert[str_l]='\0';
//	outtextxy(x+993,y,covert);
	
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
	//eror	sort(ds._vattu,ds._vattu + ds.num ); //compare missing
	for(int i = batdau ;i <= ketthuc ; i++)
	{
		printVattu(ds._vattu[i],x,SPACE+y+(i-batdau)*(16+ SPACE*2 + 1),c_line);	// liet ke theo trang 
	}
}
void xoa1vt()
{
	int n;
	cout <<"nhap STT vat tu: ";
	deleteVattu(n,DataVattu);
}
