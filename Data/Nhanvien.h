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
		Thongtin_NV p;
		check = true;
		f.read((char*)&p,sizeof(p));
		//cout<<"Nhanvien:::"<<p.MANV<<endl;
		s = p.MANV;
		Nhanvien q;
		q.thongtin = p;
		addNhanvien(DataNhanvien._nhanvien,q);
	}
	else init_nv(DataNhanvien._nhanvien);
	delKey(DataNhanvien._nhanvien,s);

	f.close();
}
bool Find_HD_byNum(Thongtin_HD &tt,CT_HOADON &ds,Tree t, char soHD[]){
	if(t == NULL ) return false;
	else{
		for(NodeHD* p = t->nv.nv_HOADON.hdHead ; p!=NULL; p = p->_next){
			if(strcmp(soHD,p->thongtin.soHD)==0) {
				tt = p->thongtin;
				ds = p->chitiet;
				return true;
			}
		}
		return (Find_HD_byNum (tt,ds,t->left,soHD)| Find_HD_byNum(tt,ds,t->right,soHD)); 
	}
}
void save_HD_to_NV(Tree &t, char MaNV[],NodeHD* p){
	if(t==NULL) return;
	if(strcmp(t->nv.thongtin.MANV,MaNV)==0){
		addTail_HD(t->nv.nv_HOADON,p);
	}
	if(strcmp(t->nv.thongtin.MANV,MaNV)>0) save_HD_to_NV(t->left,MaNV,p);
	if(strcmp(t->nv.thongtin.MANV,MaNV)<0) save_HD_to_NV(t->right,MaNV,p);
}
int Num_day(char ngay[], char thang[],char nam[]){
	int ans =0;
	if(strlen(ngay)==1) {
	ngay[1] = ngay[0];
	ngay[0] = '0';
	}
	if(strlen(thang)==1) {
	thang[1] = thang[0];
	thang[0] = '0';
	}
	int dis = 4-strlen(nam);
	for(int i=3;i>=dis;i--){
		nam [i] = nam [i-dis];
	}
	for(int i =0;i<dis;i++) nam[i] = '0';
	for(int i=0;i<strlen(nam);i++) ans= ans*10 + nam[i]; 
	for(int i=0;i<strlen(thang);i++) ans= ans*10 + thang[i]; 
	for(int i=0;i<strlen(ngay);i++) ans= ans*10 + ngay[i]; 
	return ans;
}
NodeNV* Find_HD_thongke (Tree t,int begin,int end){
	NodeNV* give = new NodeNV; 
	for(NodeHD* p = t->nv.nv_HOADON.hdHead;p!=NULL;p = p->_next){
		int num = Num_day(p->thongtin.day,p->thongtin.month,p->thongtin.year);
		if(num>=begin && num<=end){
			addTail_HD(give->nv.nv_HOADON,p);
		}
	}
	return give;
}
void Find_NV_thongke (Tree &ds,Tree t,int begin, int end){
	if(t == NULL ) return;
	NodeNV* p = new NodeNV;
	p = Find_HD_thongke(t,begin,end);
	if(p->nv.nv_HOADON.hdHead !=NULL) Insert_NV(p,ds);
	 Find_NV_thongke(ds,t->left,begin,end);
	 Find_NV_thongke(ds,t->right,begin,end);
}
DsNhanvien Thongke_HD(Tree t,int begin,int end){
	DsNhanvien ds_nv;
	init_nv(ds_nv._nhanvien);
	Find_NV_thongke(ds_nv._nhanvien,t,begin,end);
	return ds_nv;
}

