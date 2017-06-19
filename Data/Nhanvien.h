#include <string.h>
#include <iostream>
#include <winbgim.h>
#include <fstream>
#include "HOADON.h"
using namespace std;

/*file stream*/
ofstream f2;//write stream
// danh sach nhan vien ( binary serch tree)
struct Thongtin_NV{
	char MANV[100];
	char HO[100];
	char TEN[100];
	char PHAI[5];
};
struct Nhanvien{
	Thongtin_NV thongtin;
	DsHOADON nv_HOADON;			// tro den cac hoa don ma nhan vien do da lap
};
struct NodeNV{
	Nhanvien nv;
	NodeNV* left;
	NodeNV* right; 
};
typedef struct NodeNV* Tree;
int i =1;
struct DsNhanvien{
	Tree _nhanvien;
	int num = 0;
}DataNhanvien;
void save_node(NodeNV* p){
	if(p == NULL) return;
	Thongtin_NV k = p->nv.thongtin;
	//cout<<"k::::"<<k.MANV<<endl;
	f2.write((char*) &k,sizeof(k));
	save_node(p->left);
	save_node(p->right);
}
void save_Nhanvien()
{
	
	f2.open("Data/DataNhanvien.data",ios::binary |ios :: out);
	save_node(DataNhanvien._nhanvien);
	f2.close();
}

//Nhanvien NhapNhanvien(){
//	Nhanvien p;
//	cout<<"Nhap Ma nhan vien :";
//	cin>> p.MANV;
//	cout<<"Nhap Ho :";
//	cin>> p.HO;
//	cout<<"Nhap Ten :";
//	cin>> p.TEN;
//	cout<<"Nhap gioi tinh :";
//	cin>> p.PHAI;
//	return p;
//}
/*
using BGI 
*/
void XuatNhanvien(Nhanvien p,int x, int y,unsigned short int c_line[]){
	outtextxy(x+c_line[0],y,p.thongtin.MANV);
//	cout<< p.thongtin.MANV<<endl;
//	cout<< "Ho :";
//	cout<< p.HO<<endl;
	outtextxy(x+c_line[1],y,p.thongtin.HO);
//	cout<< "Ten :";
//	cout<<  p.TEN<<endl;
	outtextxy(x+c_line[2],y,p.thongtin.TEN);
//	cout<< "Gioi tinh :"; //su dung form list button voi 2 lua chon Nam/Nu 
//	cout<< p.PHAI<<endl;
	outtextxy(x+c_line[3],y,p.thongtin.PHAI);
}
void init_nv(Tree &root){
	root = NULL;
	//root->left = root->right = NULL;
}


NodeNV* GetNode_NV(Nhanvien k){
	NodeNV* p = new NodeNV;
	p->nv  = k;
	p->left = p->right = NULL;
	init_hd( p->nv.nv_HOADON);
	return p;
}

void Insert_NV(NodeNV* p,Tree &root){
	//cout<<1;
	if( root == NULL ){
		root = p;
		//cout<<1;
		return;
	
	}
	
	if(strcmp(p->nv.thongtin.MANV,root->nv.thongtin.MANV)>0) Insert_NV(p,root->right);
	else Insert_NV(p,root->left);
}

// in ra man hinh day tang dan
void addNhanvien(Tree &root, Nhanvien nv){
	NodeNV * p = GetNode_NV(nv);

	Insert_NV(p,root);
	DataNhanvien.num++;
	cout<<"Data add::"<<DataNhanvien.num<<endl;
}
bool Find_NV(Tree root,char* MaNV){
	cout<<"????"<<endl;
	if(root == NULL ) return false;
	if(strcmp(MaNV , root->nv.thongtin.MANV) == 0) return true;
	 else return  (Find_NV(root->right,MaNV) | Find_NV(root->left,MaNV));
	 
}


void Output(Tree root, int page,int x,int y,unsigned short int c_line[]){
	if(root == NULL ) return ;
	if(root ->left != NULL)  Output(root->left,page,x,y,c_line);
	//cout<<1;
	
	if(i>(page-1)*10 && i<=page*10 ) {
	if(i%10!=0)XuatNhanvien(root->nv,x,y+(i%10-1)*37,c_line);
	else XuatNhanvien(root->nv,x,y+9*37,c_line);
//	cout <<"vi tri y:: " <<y+(i-1)*37 <<":::" <<i<<endl;
	}
	i++;
	if(root->right != NULL) Output(root->right,page,x,y,c_line); 
	//XuatNhanvien(root->nv);
}
void PrintNhanvien(Tree root, int page,int x,int y,unsigned short int c_line[]){
	i = 1;
	Output(root, page,x,y,c_line);
}
//void Nhapnhieunhanvien(){
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++){
//		Nhanvien k = NhapNhanvien();
//		
//		addNhanvien(DataNhanvien._nhanvien,k);
//	}
//}
void Find_NV_Return(Tree root, int k,Nhanvien &get){
	if(root == NULL) return;
	Find_NV_Return(root->left,k,get);
	//cout<<":::"<<i<<"\n";
	if(i == k) {
		get = root->nv;
		//cout<<"get::"<<get.MANV<<endl;
	}
	i++;
	Find_NV_Return(root->right,k,get);
}

Nhanvien searchTreebyNum(Tree root,int n){
		Nhanvien give;
		//cout<<"2????\n";
		 i = 1;
		Find_NV_Return(root,n,give);
	//	cout<<"2????\n"<<n<<endl;
		return give;
}
void delKey(Tree &t, char MaNV[])     // xoa nut co key x
{	
//cout<<"cmp::"<<strcmp(MaNV,t->nv.MANV)<<endl;
    if (t==NULL) return ;
    else if (strcmp(MaNV,t->nv.thongtin.MANV)>0)  delKey(t->right, MaNV);
    else if (strcmp(MaNV,t->nv.thongtin.MANV)<0)  delKey(t->left, MaNV);
    else // T->key == x
    {
    	cout<<"vao\n";
        NodeNV *p = t;
       // cout<<"node bi xoa ||::"<<t->nv.MANV<<endl;
        if (t->left == NULL) t = t->right;    // Node chi co cay con phai
        	else if (t->right == NULL) t = t->left;   // Node chi co cay con trai
        		else // Node co ca 2 con
			    {
			    //	bool flag = false;
			       NodeNV *s = t, *q = t->left;
			       // S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
			       while (q->right != NULL)
			        {
			           s = q;
			           q = q->right;
			    	}
			    	
			        t->nv = q->nv;
			        if(q->left == NULL) t->left =NULL;
			        else s->right = q->left;
			        delete q;
			    }
   // cout<<"node thay the ||::"<<t->nv.MANV<<endl;
	}
   
}
//void Delete_NV(Tree &root,int n){
//	 i = 1;
//	Nhanvien p;
//	Find_NV_Return(root,n,p);
//	delKey(root,p.MANV);
//	DataNhanvien.num--;
//}
void initdataNhanvien(){
	ifstream f;
	char* s ;
	f.open("Data/DataNhanvien.data",ios::binary);
	bool check = false;
	if(f)
	while(!f.eof()){
		Nhanvien p;
		check = true;
		f.read((char*)&p,sizeof(p));
		//cout<<"Nhanvien:::"<<p.MANV<<endl;
		s = p.thongtin.MANV;
		addNhanvien(DataNhanvien._nhanvien,p);
	}
	else init_nv(DataNhanvien._nhanvien);
	delKey(DataNhanvien._nhanvien,s);

	f.close();
}

