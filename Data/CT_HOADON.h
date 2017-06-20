
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
	int num = 0;
	NodeCT* ctHead;
};
int j = 1;
void init_ct(CT_HOADON &ct){
	ct.num = 0;
	cout<<"\nda init\n";
	ct.ctHead = NULL;
}
NodeCT* GetNode_CT(Thongtin_CT ct){
	NodeCT* p = new NodeCT;
	p->thongtin = ct;
	p->_next = NULL;
		return p;
}
void addTail_CT(CT_HOADON &ct,NodeCT* nodect){
	if(ct.ctHead == NULL) ct.ctHead = nodect;
	else{
		NodeCT* p = new NodeCT;
		p =	ct.ctHead;
		
		while(p->_next != NULL){
			p = p->_next;
		}
		cout<<"ppp"<<p->thongtin.MAVT<<endl;
		p->_next = nodect;
		
	}
	ct.num++;
}
int parseInt(char num[]){
	int k = strlen(num);
	int ans =0;
	for(int i=0;i<k;i++) ans = ans*10+(num[i]-'0');
	return ans;
}
void Xuat_CT_HD(NodeCT* ct,int x, int y , int page,unsigned short int c_line[]){
	
	outtextxy(x+c_line[0],y,ct->thongtin.MAVT);
	cout<<"ma vt:::"<<ct->thongtin.MAVT<<endl;
	outtextxy(x+c_line[1],y,ct->thongtin.soluong);
	cout<<"so luong:::"<<ct->thongtin.soluong<<endl;
	outtextxy(x+c_line[2],y,ct->thongtin.Dongia);
	cout<<"don gia::::"<<ct->thongtin.Dongia<<endl;
	outtextxy(x+c_line[3],y,ct->thongtin.VAT);
	cout<<"%VAT:::::"<<ct->thongtin.VAT<<endl;
}

void Print_CT_HD(CT_HOADON ct,int x, int y , int page,unsigned short int c_line[]){
	j = 1;
	for(NodeCT* p = ct.ctHead;p!=NULL;p = p->_next){
		if(j>page*5) return;
		cout<<"j:::"<<j<<endl;
		if(j>(page-1)*5 && j<=(page)*5) {
		if(j%5!=0)	Xuat_CT_HD(p,x,y+(j%5-1)*(20+textheight("S")+1),page,c_line);
		else Xuat_CT_HD(p,x,y+4*(20+textheight("S")+1),page,c_line);
		}
		
		j++;
	}
}
void Delete_CT_HD(CT_HOADON &ct,int n){
	 j = 1;
	if(ct.ctHead == NULL) return;
	if(n==1 ) {
		NodeCT* p = ct.ctHead;
		ct.ctHead = p->_next;
		delete p; 
	}
	else {
		for(NodeCT* p = ct.ctHead; p!=NULL;p = p->_next){
			if(j+1==n){
				NodeCT* s = p->_next;
				p->_next = s->_next;
				delete s;
			}
		}
	}
}
void Free_CT(CT_HOADON &ct){
	while(ct.ctHead!=NULL){
		Delete_CT_HD(ct,1);
	}
}
