// danh sach hoa don (danh sach lien ket don)
#include "CT_HOADON.h"

struct NodeHD{
	char soHD[100];
	char day[2];
	char month[2];
	char year[4];
	char loai;
	CT_HOADON chitiet;
	NodeHD* _next;
};
struct DsHOADON{
	NodeHD* hdHead;
};
void init_hd(DsHOADON &hd){
	hd.hdHead = NULL;
}
NodeHD* GetNode_hd(char* sohd,char day[], char month[],char year[], char loai,CT_HOADON ct){
	NodeHD* p;
	strcpy(p->soHD , sohd);
	strcpy(p->day , day);
	strcpy(p->month , month);
	strcpy(p->year , year);
	loai = loai;
	p->chitiet = ct;
	p->_next = NULL;
}
void addTail_HD(DsHOADON &hd,NodeHD* p){
	if(hd.hdHead == NULL) hd.hdHead = p;
	else{
		NodeHD* q = hd.hdHead;
		while(q != NULL){
			if(q->_next == NULL){
				q->_next = p;
				break;
			}
			else q = q->_next;
		}
	}
}
#define CTHEAD hd.hdHead->chitiet.ctHead
void DeleteHD(DsHOADON &hd,char maVT[]){
	if(strcmp(CTHEAD -> MAVT , maVT)==0){
		CTHEAD = CTHEAD->_next;
	}
	else{
		for(NodeCT* p = CTHEAD ;p!=NULL ; p = p->_next){
			if(strcmp(p->_next->MAVT , maVT)==0){
				NodeCT* q = new NodeCT;
				q = p->_next;
				p->_next = q->_next;
				delete q;
				return;
			}
		}
	}
}

