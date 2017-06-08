	#include "Data/Vattu.h"
//	#include "Data/Nhanvien.h"
//	#include "Data/HOADON.h"
//	#include "Data/CT_HOADON.H"
	#include <E:\#PTIT CAU TRUC DU LIEU GIAI THUAT\de tai CTDLGT\Quan_Ly_Vat_Tu\conponentBGI.h>
	#include <iostream>
	#include <string>
	#include <sstream>

	
	using namespace std; // Just using for testing
int CURRENT_STRAGE;	
	
Frame m_f(APP_LEFT, APP_TOP, APP_RIGHT, APP_BOTTOM,COLOR(255,255,255));

Button Menu_Button(1,APP_LEFT, APP_TOP, APP_LEFT+ 399, APP_TOP+39, COLOR(0,0,255));

Button New_Button(0, Menu_Button.right+10, APP_TOP,Menu_Button.right+210, APP_TOP+39, COLOR(0,255,0));//change ID not 0

Tab_List Menu_Tab( Menu_Button.left, Menu_Button.bottom, Menu_Button.right,2, 15 , 4);	
/*
FONT SIZE: 2
LINE SPACE: 47
NUMBER OF LINES: 4
*****
*/
Tab_List VT_List(APP_LEFT+5, Menu_Button.bottom+39+5, APP_RIGHT-5 ,2 ,COLOR(254,244,205), 10);
/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
Tab_List NV_List(APP_LEFT+5, Menu_Button.bottom+39+5, APP_RIGHT-5 ,1 ,COLOR(254,244,205), 10);	
/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
Tab_List HD_List(APP_LEFT+5, Menu_Button.bottom+39+5, APP_RIGHT-5 ,1 ,COLOR(254,244,205), 10);
/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
Dialog Dic_Dialog(4100,APP_LEFT+5, Menu_Button.bottom+5, APP_RIGHT-5, APP_BOTTOM-135,15,"Bang tra cuu vat tu");

void main_frame()
{
	/* Draw app background*/
	m_f.Show();
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-130 , m_f.right, m_f.bottom);
	
	for(int i = 0; i<Menu_Tab.NUMBER_OF_LINE;i++)		  // Delete this line when release!!!
	cout<<"&*ct:::" <<Menu_Tab.List_content_ID[i] <<endl; // Delete this line when release!!!

	Menu_Button.show(false);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	setbkcolor(Menu_Button.color);
	setcolor(15);
	outtextxy(Menu_Button.left+20,(Menu_Button.bottom+Menu_Button.top - 24)/2,"MENU");

}

void Show_Menu_List()
{

	Menu_Tab.show();
	bool flag= true;
	while(flag)
	{
		int x=-1;
		int y=-1;
		getmouseclick(WM_LBUTTONDOWN,x,y);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(0);
		if ((x==-1)&&(y==-1)) continue;
		cout <<x <<" :: " <<y <<"--" <<R[y][x]<<endl;	// Delete this line when release!!!
		
		short int s_f=R[y][x];
		if(
		(s_f==Menu_Button.ID)
		||(s_f==Menu_Tab.List_content_ID[0])
		||(s_f==Menu_Tab.List_content_ID[1])
		||(s_f==Menu_Tab.List_content_ID[2])
		||(s_f==Menu_Tab.List_content_ID[3])
		)
		{
			Menu_Tab.cancel();
			if(s_f!=Menu_Button.ID) F_R[s_f]();
			flag= false;
		}	
		else
		{
			Menu_Tab.cancel();
			flag= false;
		}
	}	
}

void Show_VT()
{
	CURRENT_STRAGE = 1000;
	
	main_frame();
	setcolor(15);
	line(Menu_Button.left+136, Menu_Button.top,Menu_Button.left+136+20,Menu_Button.top+20);
	line( Menu_Button.left+136+20, Menu_Button.top+20,Menu_Button.left+137, Menu_Button.bottom);
	outtextxy(Menu_Button.left+176,(Menu_Button.bottom+Menu_Button.top - 24)/2,"Vat tu");
	
	cout <<"vat tu page open" <<endl; // Delete this line when release!!!
	New_Button.show(false);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setbkcolor(New_Button.color);
	setcolor(15);
	outtextxy((New_Button.left+New_Button.right - 3*16)/2, (New_Button.top+New_Button.bottom - 16)/2, "NEW");
	for(int i = 0; i<VT_List.NUMBER_OF_LINE;i++)
	VT_List.List_content_tile[i]= genericToString(i+1);
	for(int i = 0; i<VT_List.NUMBER_OF_LINE;i++)
	VT_List.List_content_ID[i]=0;
	VT_List.show();
	setfillstyle(1,COLOR(204,194,155));
	bar(VT_List.left,Menu_Button.bottom+5,VT_List.right,VT_List.top);
	setcolor(4);
	/* collum tile */
	setbkcolor(COLOR(204,194,155));
	settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
	outtextxy(VT_List.left+1,Menu_Button.bottom+15,"STT");
	outtextxy(VT_List.left+65,Menu_Button.bottom+15,"Ma Vat tu");
	outtextxy(VT_List.left+337,Menu_Button.bottom+15,"Ten Vat tu");
	outtextxy(VT_List.left+721,Menu_Button.bottom+15,"Don vi tinh");
	outtextxy(VT_List.left+993,Menu_Button.bottom+15,"SL ton");
	/* collum line */
	/*LINE 1*/ line(VT_List.left+57,Menu_Button.bottom+10,VT_List.left+57,VT_List.bottom-10);
	/*LINE 2*/ line(VT_List.left+329,Menu_Button.bottom+10,VT_List.left+329,VT_List.bottom-10);
	/*LINE 3*/ line(VT_List.left+713,Menu_Button.bottom+10,VT_List.left+713,VT_List.bottom-10);
	/*LINE 4*/ line(VT_List.left+985,Menu_Button.bottom+10,VT_List.left+985,VT_List.bottom-10);
	
	setcolor(0);
	setbkcolor(VT_List.color);
	lietkeVattu(DataVattu,0,2,VT_List.left+57,VT_List.top,10);
}


void Show_NV()
{
	CURRENT_STRAGE = 2000;
	main_frame();
	setcolor(15);
	line(Menu_Button.left+136, Menu_Button.top,Menu_Button.left+136+20,Menu_Button.top+20);
	line( Menu_Button.left+136+20, Menu_Button.top+20,Menu_Button.left+137, Menu_Button.bottom);
	outtextxy(Menu_Button.left+176,(Menu_Button.bottom+Menu_Button.top - 24)/2,"Nhan vien");
	cout <<"nhan vien page open" <<endl; // Delete this line when release!!!
}

void Show_HD ()
{
	CURRENT_STRAGE = 3000;
	main_frame();
	setcolor(15);
	line(Menu_Button.left+136, Menu_Button.top,Menu_Button.left+136+20,Menu_Button.top+20);
	line( Menu_Button.left+136+20, Menu_Button.top+20,Menu_Button.left+137, Menu_Button.bottom);
	outtextxy(Menu_Button.left+176,(Menu_Button.bottom+Menu_Button.top - 24)/2,"Hoa don");
	cout <<"hoa don page open" <<endl; // Delete this line when release!!!
}

void Show_Dic()
{
	cout <<"dictionary show" <<endl;
	Dic_Dialog.show();
}
void Cancel_Dic()
{
	cout <<"dictionary cancel" <<endl;
	Dic_Dialog.cancel();
}

void GUI_Init()
{
	F_R[0]= notthing;
//	F_R[2]= newconsole;
	/*Adding menu tab contents*/
	Menu_Tab.List_content_tile[0] = "Quan ly vat tu";
	Menu_Tab.List_content_ID[0] = 1000;
	F_R[1000]=Show_VT;
	Menu_Tab.List_content_tile[1] = "Quan ly nhan vien";
	Menu_Tab.List_content_ID[1] = 2000;
	F_R[2000]=Show_NV;
	Menu_Tab.List_content_tile[2] = "Quan ly hoa don";
	Menu_Tab.List_content_ID[2] = 3000;
	F_R[3000]=Show_HD;
	Menu_Tab.List_content_tile[3] = "Tra cuu ma vat tu";
	Menu_Tab.List_content_ID[3] = 4000;
	F_R[4000]=Show_Dic;
	/*Adding Menu Button ID*/
	F_R[Menu_Button.ID]=Show_Menu_List;
	/*main menu init*/
	Menu_Tab.line_color = COLOR(200,200,200);
	/*Vat Tu init*/
	VT_List.text_color = 4;
	VT_List.line_color = COLOR(128,128,128);
	/*Tra Cuu Vat Tu init*/
	F_R[Dic_Dialog.ID]=Cancel_Dic;

}		
