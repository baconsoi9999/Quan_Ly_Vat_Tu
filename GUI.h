//	#include "Data/Vattu.h"
//	#include "Data/Nhanvien.h"
//	#include "Data/HOADON.h"
//	#include "Data/CT_HOADON.H"
	#include <E:\#PTIT CAU TRUC DU LIEU GIAI THUAT\de tai CTDLGT\Quan_Ly_Vat_Tu\conponentBGI.h>
	#include <iostream>
	
	using namespace std; // Just using for testing
	
	void lalaland()
	{
		cout <<"FUCK LALALAND" <<endl;
	}
	
void main_frame()
{
	/* Draw app background*/
	Frame m_f(APP_LEFT, APP_TOP, APP_W, APP_H,WHITE);
	m_f.Show();
	setcolor(8);
	setlinestyle(0, 0xFFFF, 3);
	line(m_f.left + 100, m_f.top, m_f.left + 100, m_f.bottom);
	
	Button b_vt(1,APP_LEFT+5,APP_TOP+5,APP_LEFT+95,APP_TOP+95,LIGHTGRAY);
	/* Adding function ID*/
	F_R[1]=lalaland;
	/*Show off*/
	b_vt.show();
	/* Tile of button b*/
		int tile_length=3;
		setcolor(1);
		setbkcolor(b_vt.color);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		outtextxy((b_vt.right+b_vt.left-tile_length*16)/2,(b_vt.bottom+b_vt.top)/2-16,"Vat"); // 16 (pixel) is hight (& width) text. 8 half of hight
		tile_length=2;
		outtextxy((b_vt.right+b_vt.left-tile_length*16)/2,(b_vt.bottom+b_vt.top)/2,"Tu");
	
}

	
