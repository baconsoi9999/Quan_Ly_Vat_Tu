
using namespace std;
struct Thongtin_CT{
	char MAVT[100];
	char soluong[100];
	char Dongia[100];
	char VAT[100];
};
struct NodeCT{
	Thongtin_CT thongtin;
	NodeCT* _next;
};
struct CT_HOADON{
	NodeCT* ctHead;
};
int j = 1;
void init_ct(CT_HOADON ct){
	ct.ctHead = NULL;
}
void addTail_CT(CT_HOADON ct,NodeCT* nodect){
	if(ct.ctHead = NULL) ct.ctHead = nodect;
	else{
		NodeCT* p = ct.ctHead;
		while(p != NULL){
			if(p->_next == NULL){
				p->_next = nodect;
				break; 
			}
			else p = p->_next;
		}
	}
}
int parseInt(char num[]){
	int k = strlen(num);
	int ans =0;
	for(int i=0;i<k;i++) ans = ans*10+(num[i]-'0');
	return ans;
}
void Xuat_CT_HD(NodeCT* ct,int x, int y , int page, char c_line[]){
	
	outtextxy(x,y,ct->thongtin.MAVT);
	cout<<"ma vt:::"<<ct->thongtin.MAVT<<endl;
	outtextxy(x,y,ct->thongtin.soluong);
	cout<<"so luong:::"<<ct->thongtin.soluong<<endl;
	outtext(x,y,ct->thongtin.Dongia);
	cout<<"don gia::::"<<ct->thongtin.Dongia<<endl;
	outtextxy(x,y,ct->thongtin.VAT);
	cout<<"%VAT:::::"<<ct->thongtin.VAT<<endl;
}
void Print_CT_HD(CT_HOADON ct,int x, int y , int page, char c_line[]){
	j = 1;
	for(NodeCT* p = ct.ctHead;p!=NULL;p = p->_next){
		if(j>page*10) return;
		if(j>(page-1)*10 && j<=(page)*10) Xuat_CT_HD(p,x,y,page,c_line);
		j++;
	}
}
