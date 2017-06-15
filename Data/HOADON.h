// danh sach hoa don (danh sach lien ket don)
#include <F:\Quan_Ly_Vat_Tu\Data\CT_HOADON.h>
#include <F:\Quan_Ly_Vat_Tu\Data\Vattu.h>
#include <iostream>
struct NodeHD{
	char soHD[100];
	char ngayLap[100];
	char loai[100];
	CT_HOADON chitiet;
	NodeHD* _next = NULL;
};
struct HOADON{
	NodeHD* hdHead;
};
void Init(HOADON &hd){
	hd.hdHead = NULL;
}
void addTail(HOADON &hd,NodeHD* p){
	p->_next = NULL;
	if(hd.hdHead == NULL) hd.hdHead = p;
	else{
		NodeHD* q = hd.hdHead;
		while(q != NULL){
			if(q->_next == NULL){
				q->_next = p;
			}
			else q = q->_next;
		}
	}
}
#define CTHEAD hd.hdHead->chitiet.ctHead
void DeleteHD(HOADON &hd,char maVT[]){
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


