#include <string.h>
#include <iostream>
#include <winbgim.h>
#include <fstream>
using namespace std;

/*file stream*/
ofstream f2;//write stream
// danh sach nhan vien ( binary serch tree)
struct Nhanvien{
	char MANV[100];
	char HO[100];
	char TEN[100];
	char PHAI[5];
//	DsHOADON nv_HOADON;			// tro den cac hoa don ma nhan vien do da lap
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
	Nhanvien k = p->nv;
	cout<<"k::::"<<k.MANV<<endl;
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
void XuatNhanvien(Nhanvien p,int x, int y,unsigned short int c_line[]){
	outtextxy(x+c_line[0],y,p.MANV);
//	cout<< p.MANV<<endl;
//	cout<< "Ho :";
//	cout<< p.HO<<endl;
	outtextxy(x+c_line[1],y,p.HO);
//	cout<< "Ten :";
//	cout<<  p.TEN<<endl;
	outtextxy(x+c_line[2],y,p.TEN);
//	cout<< "Gioi tinh :"; //su dung form list button voi 2 lua chon Nam/Nu 
//	cout<< p.PHAI<<endl;
	outtextxy(x+c_line[3],y,p.PHAI);
}
void init_nv(Tree &root){
	root = NULL;
	//root->left = root->right = NULL;
}


NodeNV* GetNode_NV(Nhanvien k){
	NodeNV* p = new NodeNV;
	p->nv  = k;
	p->left = p->right = NULL;
	return p;
}

void Insert_NV(NodeNV* p,Tree &root){
	//cout<<1;
	if( root == NULL ){
		root = p;
		//cout<<1;
		return;
	
	}
	
	if(strcmp(p->nv.MANV,root->nv.MANV)>0) Insert_NV(p,root->right);
	else Insert_NV(p,root->left);
}

// in ra man hinh day tang dan
void addNhanvien(Tree &root, Nhanvien nv){
	NodeNV * p = GetNode_NV(nv);
	Insert_NV(p,root);
	DataNhanvien.num++;
}
bool Find_NV(Tree root,char* MaNV){
	bool check = false;
	if(root == NULL ) return false;
	if(strcmp(MaNV , root->nv.MANV) == 0) return true;
	if(strcmp(MaNV , root->nv.MANV) > 0 ) return (check | Find_NV(root->right,MaNV)); 
	else return (check | Find_NV(root->left,MaNV));
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
void Nhapnhieunhanvien(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		Nhanvien k = NhapNhanvien();
		
		addNhanvien(DataNhanvien._nhanvien,k);
	}
}
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
void Find_pos_NV_process(Tree root,char* MaNV,int &pos){
	if(root == NULL) return;
	Find_pos_NV_process(root->left,MaNV,pos);
	if(strcmp(MaNV,root->nv.MANV)==0) pos = i;
	i++;
	Find_pos_NV_process(root->right,MaNV,pos);
}
int Find_pos_NV(Tree root , char* MaNV){
	 i = 1;
	 int x;
	 Find_pos_NV_process(root,MaNV,x);
	 return x;
}

Nhanvien searchTreebyNum(Tree root,int n){
		Nhanvien give;
		//cout<<"2????\n";
		 i = 1;
		Find_NV_Return(root,n,give);
	//	cout<<"2????\n"<<n<<endl;
		return give;
}
void delKey(Tree &t, char* MaNV)     // xoa nut co key x
{
    if (t==NULL) return ;
    else if (strcmp(MaNV,t->nv.MANV)>0) return delKey(t->right, MaNV);
    else if (strcmp(MaNV,t->nv.MANV)<0) return delKey(t->left, MaNV);
    else // T->key == x
    {
        NodeNV *p = t;
        if (t->left == NULL) t = t->right;    // Node chi co cay con phai
        else if (t->right == NULL) t = t->left;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
            NodeNV *s = t, *q = s->left;
            // S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
            while (q->right != NULL)
            {
                s = q;
                q = q->right;
            }
            p->nv = q->nv;
            s->right = q->left;
            delete q;
        }
    }
}
void Delete_NV(Tree &root,int n){
	 i = 1;
	Nhanvien p;
	Find_NV_Return(root,n,p);
	delKey(root,p.MANV);
	DataNhanvien.num--;
}
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
		s = p.MANV;
		addNhanvien(DataNhanvien._nhanvien,p);
	}
	else init_nv(DataNhanvien._nhanvien);
	delKey(DataNhanvien._nhanvien,s);

	f.close();
}
struct nhanvien_error{
	char* error_st[4];
	int error_color[4];
	bool check = true;
};
nhanvien_error Check_NV_new(Nhanvien &nv,char MaNV[], char Ho[], char Ten[], char Phai[])
{
		nhanvien_error p;
		
		
		// xu li ma vat tu
		if(Find_NV(DataNhanvien._nhanvien,MaNV)) {
			p.error_st[0] = "Da ton tai\0";
			p.check = false;
			p.error_color[0] = 4;
		}
		else if(strlen(MaNV)==0) {
			p.error_st[0] = "Khong duoc rong  \0";
			p.check = false;
			p.error_color[0] = 4;
		}
			else
			p.error_st[0] = "Co the su dung   \0",p.error_color[0] = COLOR(0,255,0);
		// xu li ten vat tu
		
			int len_Ho = strlen(Ho);
			if(len_Ho == 0) {
				p.error_st[1] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[1] = 4;
			}
			else p.error_st[1] = "Co the su dung \0",p.error_color[1] = COLOR(0,255,0);
			
		
		// xu li Don vi
		
			int len_ten = strlen(Ten);
			if(len_ten == 0){
				p.error_st[2] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[2] = 4;
			}
			else p.error_st[2] = "Co the su dung \0",p.error_color[2] = COLOR(0,255,0);
		
		//xu li so luong
		
			int len_phai = strlen(Phai);
			if(len_phai == 0){
				p.error_st[3] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[3] = 4;
			}
			else p.error_st[3] = "Co the su dung \0",p.error_color[3] = COLOR(0,255,0);
			if(p.check == true){
			strcpy(nv.MANV, MaNV);
			strcpy(nv.HO, Ho);
			strcpy(nv.TEN , Ten);
			strcpy(nv.PHAI,Phai);
			}
		return p;
}
nhanvien_error Check_NV_seclect(Nhanvien &nv,char MaNV[], char Ho[], char Ten[], char Phai[],int check_nv)
{
		nhanvien_error p;
		// xu li ma vat tu
		if(Find_NV(DataNhanvien._nhanvien,MaNV)==true && check_nv != Find_pos_NV(DataNhanvien._nhanvien,MaNV)) {
			p.error_st[0] = "Vat tu da ton tai\0";
			p.check = false;
			p.error_color[0] = 4;
		}
		else if(strlen(MaNV)==0) {
			p.error_st[0] = "Khong duoc rong  \0";
			p.check = false;
			p.error_color[0] = 4;
		}
			else
			p.error_st[0] = "Co the su dung   \0",p.error_color[0] = COLOR(0,255,0);
		// xu li ten vat tu
		
			int len_Ho = strlen(Ho);
			if(len_Ho == 0) {
				p.error_st[1] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[1] = 4;
			}
			else p.error_st[1] = "Co the su dung \0",p.error_color[1] = COLOR(0,255,0);
			
		
		// xu li Don vi
		
			int len_Ten = strlen(Ten);
			if(len_Ten == 0){
				p.error_st[2] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[2] = 4;
			}
			else p.error_st[2] = "Co the su dung \0",p.error_color[2] = COLOR(0,255,0);
		
		//xu li so luong
		
			int len_Phai = strlen(Phai);
			if(len_Phai == 0){
				p.error_st[3] = "Khong duoc rong\0";
				p.check = false;
				p.error_color[3] = 4;
			}
			else p.error_st[3] = "Co the su dung \0",p.error_color[3] = COLOR(0,255,0);
				if(p.check == true){
			strcpy(nv.MANV, MaNV);	
			strcpy(nv.HO, Ho);
			strcpy(nv.TEN, Ten);
			strcpy(nv.PHAI,Phai);
		}
		return p;
}

