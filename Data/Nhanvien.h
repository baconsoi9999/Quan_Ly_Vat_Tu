#include<string>

using namespace std;

// danh sach nhan vien ( binary serch tree)
struct Nhanvien{
	string MANV;
	string HO;
	string TEN;
	string PHAI;
	//Node *Root;				// tro den cac hoa don ma nhan vien do da lap
};
struct NV_Node{
	Nhanvien nv;
	NV_Node* left;
	NV_Node* right; 
};

Nhanvien NhapNhanvien(){
	Nhanvien p;
//	cout<<"Nhap Ma nhan vien :";
//	cin>> p->MANV;
//	cout<<"Nhap Ho :";
//	cin>> p->HO;
//	cout<<"Nhap Ten :";
//	cin>> p->TEN;
//	cout<<"Nhap gioi tinh :";
//	cin>> p->PHAI;
	return p;
}
/*
using BGI 
*/
void XuatNhanvien(Nhanvien nv){
//	cout<< "Nhap Ma nhan vien :";
//	cout<< p->MANV<<endl;
//	cout<< "Nhap Ho :";
//	cout<< p->HO<<endl;
//	cout<< "Nhap Ten :";
//	cout<<  p->TEN<<endl;
//	cout<< "Nhap gioi tinh :"; //su dung form list button voi 2 lua chon Nam/Nu 
//	cout<< p->PHAI<<endl;
}

void Init(NV_Node* root){
	root = NULL;
}
NV_Node* GetNode(Nhanvien k){
	NV_Node* p = new NV_Node;
	p->nv  = k;
	p->left = p->right = NULL;
}

void Insert(NV_Node* p,NV_Node* root){
	if( root==NULL ){
		root = p;
		return;
	}
	if(p->nv.MANV.compare(root->nv.MANV)) Insert(p,root->right);
	else Insert(p,root->left);
}

void Output(NV_Node* root){
	if(root ->left!=NULL) Output(root->left);
	XuatNhanvien(root->nv);
	if(root->right!=NULL) Output(root->right); 
}
