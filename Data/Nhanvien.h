#include <string.h>
#include <iostream>
#include "Data\HOADON.h"
using namespace std;

// danh sach nhan vien ( binary serch tree)
struct Nhanvien{
	char MANV[100];
	char HO[100];
	char TEN[100];
	char PHAI[4];
	DsHOADON nv_HOADON;			// tro den cac hoa don ma nhan vien do da lap
};
struct NV_Node{
	Nhanvien nv;
	NV_Node* left;
	NV_Node* right; 
};

Nhanvien NhapNhanvien(){
	Nhanvien p;
	cout<<"Nhap Ma nhan vien :";
	cin>> p.MANV;
	cout<<"Nhap Ho :";
	cin>> p.HO;
	cout<<"Nhap Ten :";
	cin>> p.TEN;
	cout<<"Nhap gioi tinh :";
	cin>> p.PHAI;
	return p;
}
/*
using BGI 
*/
void XuatNhanvien(Nhanvien p){
	cout<< "Ma nhan vien :";
	cout<< p.MANV<<endl;
	cout<< "Ho :";
	cout<< p.HO<<endl;
	cout<< "Ten :";
	cout<<  p.TEN<<endl;
	cout<< "Gioi tinh :"; //su dung form list button voi 2 lua chon Nam/Nu 
	cout<< p.PHAI<<endl;
}
typedef struct NV_Node* Tree;
void init_nv(Tree &root){
	root = NULL;
	
	//root->left = root->right = NULL;
}
NV_Node* GetNode(Nhanvien k){
	NV_Node* p = new NV_Node;
	p->nv  = k;
	p->left = p->right = NULL;
	return p;
}

void Insert(NV_Node* p,Tree &root){
	//cout<<1;
	if( root == NULL ){
		root = p;
		//cout<<1;
		return;
	
	}
	
	if(strcmp(p->nv.MANV,root->nv.MANV)>0) Insert(p,root->right);
	else Insert(p,root->left);
}
// in ra man hinh day tang dan
void Output(Tree root){
	if(root ->left!=NULL) Output(root->left);
	//cout<<1;
	XuatNhanvien(root->nv);
	if(root->right!=NULL) Output(root->right); 
	//XuatNhanvien(root->nv);
}
