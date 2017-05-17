#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <winbgim.h> 
#include <string>
using namespace std;

const int SCREAN_H = 768;
const int SCREAN_W = 1366;

const int APP_LEFT = 30;
const int APP_TOP = 30;
const int APP_BOTTOM = SCREAN_H - 100;
const int APP_RIGHT = SCREAN_W - 30;

const int FUNCTION_NUMBER = 10000;
void (*F_R[FUNCTION_NUMBER])();
/*
function's menber decrptions:

*/
/**********************************************/
/*
ID via screan
ID must be a number under FUNCTION_NUMBER
*/
short int R[SCREAN_H+1][SCREAN_W+1];
void init_R()
{
	for(unsigned int i=0; i<=SCREAN_H;i++)
	for(unsigned int j=0; j<=SCREAN_W;j++)
	R[i][j]=0;
}
void  notthing()
{
	cout << "Do not thing" <<endl;
}
//void newconsole()
//{
//CConsoleLogger another_console;
//another_console.Create("This is the first console");
//another_console.printf("WOW !!! COOLL !!! another console ???");
//}
struct Button
{
	short int ID;
	int left;
	int top;
	int right;
	int bottom;
	int color;
	
	/*contructor*/
	Button(int bid, int l, int t, int r, int b, int c)
	{
		ID = bid;
		left = l;
		top = t;
		right = r;
		bottom = b;
		color = c;
	};

	void show(bool click)
	{
		setfillstyle(1,color);
		bar(left, top, right, bottom);	
		for (int y = top; y <= bottom; y++)
		for (int x = left; x <= right; x++)
			R[y][x] = ID;	
	}
	// useless method
//10:26-12/5/2017 Delete is_button_clicked() method
};



struct Frame
{
	int left;
	int top;
	int right;
	int bottom;
	int color;
	/*contructor*/
	Frame(int l, int t, int r, int b, int c)
	{
		left = l;
		top = t;
		right = r;
		bottom = b;
		color = c;
	};
	void Show()
	{
		setfillstyle(1, color);
		bar(left, top, right, bottom);
	};
};

struct Tab_List
{
	int left;
	int top;
	int right;
	int bottom;
	unsigned short int font_size;
	int color;
	int text_color = 0;
	int line_color = 0;
	unsigned short int NUMBER_OF_LINE;
	const short unsigned int CONTENT_SPACE = 15;
	
	/*set backup ID array*/
	int B_R[1000][1000];
	string *List_content_tile;
	short int *List_content_ID;
	/*Set backup layer*/
	void *bitmap; // get a ID memory pointer for layer. 

	Tab_List(int l, int t, int r, int f_s, int c, int n_o_l)
	{

		left = l;
		top = t;
		right = r;
		font_size= f_s;
		color = c;
		NUMBER_OF_LINE=n_o_l;
		bottom =  t +  n_o_l*(font_size*8 + CONTENT_SPACE*2+1);
		/*List content & ID contructor*/
		List_content_tile = new string[n_o_l];
		List_content_ID = new short int[n_o_l];

		
	};
	
	void set_active()
	{

		/*set backup ID */
		bitmap = malloc(imagesize(left, top, right,bottom)); // set memory for image 
		getimage(left, top, right, bottom, bitmap); //save area scream.
		/*save pixels ID*/
		int y;
		int x;
		int y2;
		int x2;
		for (y = top, y2 = 0; y <= bottom; y++, y2++)
		{
			for (x = left, x2 = 0; x <= right; x++, x2++)
			{
				B_R[y2][x2]=R[y][x];
			}
		}
		
		for(int n= 0; n<NUMBER_OF_LINE; n++)
			for(int i = top + n*(CONTENT_SPACE*2 + font_size*8+1); i< top + (n+1)*(CONTENT_SPACE*2 + font_size*8+1);i++)
				for(int j = Tab_List::left; j <= Tab_List::right ; j++)
					R[i][j]=Tab_List::List_content_ID[n];
			
				
	}
	void show()
	{
		
		Tab_List::set_active();
		
		setfillstyle(1, color );
		bar(left, top, right, bottom);
		
		setcolor(line_color);//BLACK
		rectangle(left, top, right-1, bottom-1);
		for(int i=1; i<NUMBER_OF_LINE;i++)
		{
			line(left + 10, top + i*(CONTENT_SPACE*2 + font_size*8+1), right - 10, top + i*(CONTENT_SPACE*2 + font_size*8 +1));	
		}
		
		setbkcolor(color);
		setcolor( text_color ); //BLACK
		settextstyle(DEFAULT_FONT, HORIZ_DIR,font_size);
		
		for(int i = 0; i<NUMBER_OF_LINE; i++)
		{
			char *covert = new char [List_content_tile[i].length()];
			for(int j=0;j<List_content_tile[i].length();j++) covert[j] =List_content_tile[i][j]; 
			covert[List_content_tile[i].length()]='\0';
			outtextxy(Tab_List::left+ 10 , top+ CONTENT_SPACE + i*(font_size*8+ CONTENT_SPACE*2+1), covert);
			
		}
		cout <<"Tap_List Open" <<endl <<"bottom: " << bottom <<endl; // Delete this line when release!!!
		
	}
	
	
	void cancel()
	{
		
		/*set Image back */
		putimage(left, top, bitmap, 0);
		free(bitmap);
		/*set backup ID back */
	
		int y2=0;
		int x2=0;
		for (int y = top; y <= bottom; y++)
		{
			for (int x = left; x <= right; x++)
			{
				R[y][x] = B_R[y2][x2];
				x2++;
			}
			y2++;
		}
		cout <<"Tap_List Cancel" <<endl; // Delete this line when release!!!
	};
//10:26-12/5/2017 Delete is_content_click() method	

	
};
struct Dialog
{
	short int ID;
	int left;
	int top;
	int right;
	int bottom;
	int color = 15;
	string tile;
	/*cancel button*/
	int c_b_left;
	int c_b_right;
	int c_b_top;
	int c_b_bottom;

	/*set backup ID array*/
	short int B_R[1000][2000];

	/*Set backup layer*/
	void *bitmap; // get a ID memory pointer for layer. 
	
	Dialog(int did, int l, int t, int r, int b, int c, string tl)
	{
		ID = did;
		left = l;
		top = t;
		right = r;
		bottom = b;
		color = c;
		tile = tl;
		c_b_left = r - 50;
		c_b_right = r;
		c_b_top = t;
		c_b_bottom = t + 25;
	}
	void set_active()
	{		
		/*set backup ID */
		bitmap = malloc(imagesize(left, top, right,bottom)); // set memory for image 
		getimage(left, top, right, bottom, bitmap); //save area scream.
		/*save pixels ID*/
		int y;
		int x;
		int y2;
		int x2;
		for (y = top, y2 = 0; y <= bottom; y++, y2++)
		{
			for (x = left, x2 = 0; x <= right; x++, x2++)
			{
				B_R[y2][x2]=R[y][x];
				R[y][x]=0;
			}
		}
	cout<< "Debug::Diaglog::set_active::3::ok" <<endl;
		/*set cancel ID*/
		for (y = c_b_top, y2 = 0; y <= c_b_bottom; y++, y2++)
		{
			for (x = c_b_left, x2 = 0; x <= c_b_right; x++, x2++)
			{
				R[y][x]=ID;
			}
		};
	cout<< "Debug::Diaglog::set_active::4::ok" <<endl;
	};


	/*show to screan*/
	void show()
	{
		set_active();
			setfillstyle(1, color);
		bar(left, top, right, bottom);
			setcolor(COLOR(128,128,128));
		rectangle(left, top, right-1, bottom-1);
			setfillstyle(1, COLOR(128,128,255));
		bar(left, top, c_b_left, c_b_bottom);

		/*cancel button*/
			setfillstyle(1, 4);
		bar(c_b_left, c_b_top, c_b_right, c_b_bottom);
			setcolor(15);
			setbkcolor(COLOR(128,128,255));
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		char *covert = new char [tile.length()+1];
			for(int j=0;j<tile.length();j++) covert[j] =tile[j]; 
			covert[tile.length()]='\0';
		outtextxy((left+c_b_left-tile.length()*16)/2, (top+c_b_bottom-16)/2, covert);
			setbkcolor(4);
		outtextxy(c_b_left + 17, c_b_top+4, "X");
	};
	/*cancel Dialog*/
	void cancel()
	{
		int y;
		int x;
		int y2;
		int x2;
		/*set backup ID */
		putimage(left, top, bitmap, 0);
		free(bitmap);
		for (y = top, y2 = 0; y <= bottom; y++, y2++)
		{
			for (x = left, x2 = 0; x <= right; x++, x2++)
			{
				R[y][x] = B_R[y2][x2];
			}
		};

	};
	
//10:26-12/5/2017 Delete is_cancel_click() method
};
