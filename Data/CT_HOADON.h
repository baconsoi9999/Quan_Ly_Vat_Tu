
using namespace std;
struct NodeCT{
	char MAVT[100];
	char soluong[100];
	char Dongia[100];
	char VAT[100];
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
	cout<<"ma vt:::"<<ct->MAVT<<endl;
	cout<<"so luong:::"<<ct->soluong<<endl;
	cout<<"don gia::::"<<ct->Dongia<<endl;
	cout<<"%VAT:::::"<<ct->VAT<<endl;
}
void Print_CT_HD(CT_HOADON ct,int x, int y , int page, char c_line[]){
	for(NodeCT* p = ct.ctHead;p!=NULL;p = p->_next){
		Xuat_CT_HD(p,x,y,page,c_line);
	}
}
