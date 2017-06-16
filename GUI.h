	#include "Data/Vattu.h"
//	#include "Data/Nhanvien.h"
//	#include "Data/HOADON.h"
//	#include "Data/CT_HOADON.H"
	#include <E:\#PTIT CAU TRUC DU LIEU GIAI THUAT\de tai CTDLGT\Quan_Ly_Vat_Tu\conponentBGI.h>
	#include <iostream>
	#include <string.h>
	
	
	using namespace std;
	 // Just using for testing

int CURRENT_STRAGE;	
unsigned int VT_ID=100,NV_ID=200,HD_ID=300;
Frame m_f(APP_LEFT, APP_TOP, APP_RIGHT, APP_BOTTOM,COLOR(255,255,255));

Panel active_bar(APP_LEFT,APP_BOTTOM-130,APP_RIGHT,APP_BOTTOM);

Button Exit_App(1,APP_RIGHT-58,APP_TOP,APP_RIGHT,APP_TOP+29,4,2," X ");

Button Menu_Button(2,APP_LEFT, APP_TOP, APP_LEFT+ 399, APP_TOP+39, COLOR(0,0,255),3,"MENU");

Button New_Button(0, Menu_Button.right+10, APP_TOP,Menu_Button.right+160, APP_TOP+39, COLOR(0,255,0),3," NEW\0");//change ID not 0

Button Save_Button(0,New_Button.right +5, APP_TOP, New_Button.right +165, APP_TOP+39, COLOR(0,0,220),3," SAVE\0");

char*Menu_Content_Tile[5]={"Trang chu\0","Quan ly vat tu\0","Quan ly nhan vien\0","Quan ly hoa don\0","Tra cuu ma"};
Tab_List Menu_Tab( Menu_Button.left, Menu_Button.bottom, Menu_Button.right,2, 15 , 5, Menu_Content_Tile);	
/*
FONT SIZE: 2
LINE SPACE: 47
NUMBER OF LINES: 4
*****
*/
unsigned short int VT_Book_c_line[4]={71,349,713,985};
char* VT_Book_c_tile[5]={"STT\0","Ma Vat tu\0","Ten Vat tu\0", "don vi tinh\0", "SL ton\0"};
char* VT_Book_l_tile[10]={"1\0","2\0","3\0","4\0","5\0","6\0","7\0","8\0","9\0","10\0"};
//Tab_List VT_List(APP_LEFT+5, Menu_Button.bottom+39+5, APP_RIGHT-5 ,2 ,COLOR(254,244,205), 10,l_tile);
Book VT_Book(APP_LEFT+5, Menu_Button.bottom+5, APP_RIGHT-5 ,2 ,COLOR(234,244,253),COLOR(83,174,242), 10,5,VT_Book_c_line,VT_Book_c_tile,VT_Book_l_tile);
//new VAT TU function
unsigned short int VT_new_c_line[3]={278,642,914};
char* VT_new_c_tile[4]={"Ma Vat tu\0","Ten Vat tu\0", "don vi tinh\0", "SL ton\0"};
Array_Table VT_new(APP_LEFT+5, APP_BOTTOM-120, APP_RIGHT-100, APP_BOTTOM-40, 2,COLOR(234,244,253),COLOR(0,255,0), 4, VT_new_c_line, VT_new_c_tile);
Button VT_new_save(125,APP_RIGHT-95, APP_BOTTOM-120,APP_RIGHT-5,APP_BOTTOM-82,COLOR(0,0,220),2," OK\0");
Button VT_new_cancel(126,APP_RIGHT-95,APP_BOTTOM-78,APP_RIGHT-5,APP_BOTTOM-40,COLOR(0,0,220),2," HUY\0");
/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
//Tab_List NV_List(APP_LEFT+5, Menu_Button.bottom+39+5, APP_RIGHT-5 ,1 ,COLOR(254,244,205), 10,l_tile);	
/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
//Tab_List HD_List(APP_LEFT+5, Menu_Button.bottom+39+5, APP_RIGHT-5 ,1 ,COLOR(254,244,205), 10,l_tile);
/*
FONT SIZE: 1
LINE SPACE: 39
NUMBER OF LINES: 10
*****
*/
Dialog Dic_Dialog(401,402,APP_LEFT+5, Menu_Button.bottom+5, APP_RIGHT-5, APP_BOTTOM-135,COLOR(255,255,255),"Bang tra cuu vat tu\0");

void menu_slash(char* menu_content_tile)
{
	setcolor(15);
	line(Menu_Button.left+136, Menu_Button.top,Menu_Button.left+136+20,Menu_Button.top+20);
	line( Menu_Button.left+136+20, Menu_Button.top+20,Menu_Button.left+137, Menu_Button.bottom);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	setbkcolor(Menu_Button.color);
	setcolor(15);
	outtextxy(Menu_Button.left+160,(Menu_Button.bottom+Menu_Button.top - 24)/2, menu_content_tile);
}
void main_frame()
{
	/* Draw app background*/
	m_f.Show();
	setfillstyle(1,COLOR(128,128,255));
	bar(m_f.left,m_f.bottom-130 , m_f.right, m_f.bottom);
	
	for(int i = 0; i<Menu_Tab.NUMBER_OF_LINE;i++)		  // Delete this line when release!!!
	cout<<"&*ct:::" <<Menu_Tab.List_content_ID[i] <<endl; // Delete this line when release!!!	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	setbkcolor(Menu_Button.color);
	setcolor(15);
	Menu_Button.show();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	Exit_App.show();
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
		||(s_f==Menu_Tab.List_content_ID[4])
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
/*home*/
void Home()
{
	main_frame();
}
/*VAT TU  fuction*/
void new_MVT()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerCode(VT_new.List_content[0],16,VT_new.left+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[0]);
}
void new_TVT()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerString(VT_new.List_content[1],21,VT_new.left+VT_new.column[0]+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[1]);
}
void new_DVTVT()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerString(VT_new.List_content[2],16,VT_new.left+VT_new.column[1]+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[2]);
}
void new_SLTVT()
{
	setbkcolor(VT_new.color);
	setcolor(0);//BLACK
	settextstyle(DEFAULT_FONT, HORIZ_DIR,VT_new.font_size);
	clearStream();
	ScannerNum(VT_new.List_content[3],9,VT_new.left+VT_new.column[2]+5,(VT_new.top_main+VT_new.bottom-textheight("S"))/2,VT_new.List_content_ID[3]);
}
void cancel_VT_new()
{
	VT_new.free_Table();
	VT_new.cancel();
	active_bar.cancel();
	
}
void save_VT_new()
{
	vattu_error error;
	Vattu pre_add;
	error = Check_VT(pre_add,VT_new.List_content[0],VT_new.List_content[1],VT_new.List_content[2],VT_new.List_content[3]);
	if(error.check)
	{
	FindandInsert(DataVattu,pre_add);
	cancel_VT_new();
	} 
	else 
	{
		setbkcolor(getpixel(VT_new.left,VT_new.bottom+5));
		setcolor(4);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
		setcolor(error.error_color[0]);
		outtextxy(VT_new.left,VT_new.bottom+5,error.error_st[0]);
		for(int i = 1; i<4;i++)
		{
			setcolor(error.error_color[i]);
			outtextxy(VT_new.left+VT_new_c_line[i-1],VT_new.bottom+5,error.error_st[i]);
		}
	}
	
	
}

void Show_VT_new()
{
	if(active_bar.is_active) active_bar.cancel();
	if(VT_new.is_active) VT_new.cancel();
	active_bar.Show();
	VT_new.free_Table();
	VT_new_save.show();//button
	VT_new_cancel.show();//button
	VT_new.show();
}
void next_VT_Book()
{
	VT_Book.next_PAGE();
	lietkeVattu(DataVattu,
	    (VT_Book.CURENT_PAGE-1)*10,min((VT_Book.CURENT_PAGE*10-1),(DataVattu.num-1)),
    	VT_Book.left,VT_Book.top_main,10,VT_Book_c_line);
}
void prev_VT_Book()
{
	VT_Book.prev_PAGE();
	lietkeVattu(DataVattu,
	    (VT_Book.CURENT_PAGE-1)*10,min((VT_Book.CURENT_PAGE*10-1),(DataVattu.num-1)),
    	VT_Book.left,VT_Book.top_main,10,VT_Book_c_line);
}
void Show_VT()
{
	cout <<"vat tu page open" <<endl; // Delete this line when release!!!
	CURRENT_STRAGE = 100;
	
	main_frame();
	menu_slash("vat tu");
	
	cout <<"vat tu page open" <<endl; // Delete this line when release!!!
	New_Button.ID=CURRENT_STRAGE+20;
	New_Button.show();
	Save_Button.ID=CURRENT_STRAGE+99;
	Save_Button.show();
	VT_Book.show();
	setcolor(0);
	setbkcolor(VT_Book.color);
	lietkeVattu(DataVattu,
	    (VT_Book.CURENT_PAGE-1)*10,min((VT_Book.CURENT_PAGE*10-1),(DataVattu.num-1)),
    	VT_Book.left,VT_Book.top_main,10,VT_Book_c_line);
}


void Show_NV()
{
	CURRENT_STRAGE = 200;
	main_frame();
	menu_slash("Nhan vien");
	cout <<"nhan vien page open" <<endl; // Delete this line when release!!!
}

void Show_HD ()
{
	CURRENT_STRAGE = 300;
	main_frame();
	menu_slash("Hoa don");
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
	/*Adding Exit button ID*/
	F_R[Exit_App.ID]=Exit;
	/*Adding Menu Button ID*/
	F_R[Menu_Button.ID]=Show_Menu_List;
	/*Adding menu tab contents*/
	/*Vattu ID*/
	Menu_Tab.List_content_ID[0]= 3;
	F_R[3]=Home;
	Menu_Tab.List_content_ID[1] = VT_ID;
	F_R[VT_ID]=Show_VT;
	for(int i = 0; i<VT_Book.NUMBER_OF_LINE;i++)
	{
		VT_Book.List_content_ID[i]=VT_ID+i+1;
		F_R[VT_Book.List_content_ID[i]] = notthing;
	}
	F_R[VT_ID+20]=Show_VT_new;
	VT_new.List_content_ID[0]=VT_ID+21;
	F_R[VT_new.List_content_ID[0]]=new_MVT;
	VT_new.List_content_ID[1]=VT_ID+22;
	F_R[VT_new.List_content_ID[1]]=new_TVT;
	VT_new.List_content_ID[2]=VT_ID+23;
	F_R[VT_new.List_content_ID[2]]=new_DVTVT;
	VT_new.List_content_ID[3]=VT_ID+24;
	F_R[VT_new.List_content_ID[3]]=new_SLTVT;
	F_R[VT_new_save.ID]=save_VT_new;
	F_R[VT_new_cancel.ID]=cancel_VT_new;
	/*Nhan vien ID*/
	Menu_Tab.List_content_ID[2] = NV_ID;
	F_R[NV_ID]=Show_NV;
	/*Hoa don ID*/
	Menu_Tab.List_content_ID[3] = HD_ID;
	F_R[HD_ID]=Show_HD;
	/*Dic ID*/
	Menu_Tab.List_content_ID[4] = Dic_Dialog.ID;
	F_R[Dic_Dialog.ID]=Show_Dic;
	F_R[Dic_Dialog.cID]=Cancel_Dic;
	/*main menu init*/
	Menu_Tab.line_color = COLOR(200,200,200);
	/*Vat Tu init*/
	F_R[VT_ID+99] = save_Vattu;
	VT_Book.prev_ID=111;
	F_R[VT_Book.prev_ID] = prev_VT_Book;
	VT_Book.next_ID=112;
	F_R[VT_Book.next_ID] = next_VT_Book;
	VT_Book.TOTAL_PAGE= DataVattu.num/10+(DataVattu.num%10!=0);
	VT_Book.text_color = 0;
	VT_Book.line_color = COLOR(128,128,128);
	/*Tra Cuu Vat Tu init*/
	cout <<"GUI init complete!\n";
}		
