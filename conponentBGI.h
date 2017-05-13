#include <iostream>
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

const int FUNCTION_NUMBER = 20;
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
};

struct Button
{
	int ID;
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
		
		setcolor( COLOR(128,128,128));//BLACK
		rectangle(left, top, right-1, bottom-1);
		for(int i=1; i<NUMBER_OF_LINE;i++)
		{
			line(left + 10, top + i*(CONTENT_SPACE*2 + font_size*8+1), right - 10, top + i*(CONTENT_SPACE*2 + font_size*8 +1));	
		}
		
		setbkcolor(color);
		setcolor( 0 ); //BLACK
		settextstyle(DEFAULT_FONT, HORIZ_DIR,font_size);
		
		for(int i = 0; i<NUMBER_OF_LINE; i++)
		{
			char *covert = new char [List_content_tile[i].length()];
			for(int j=0;j<List_content_tile[i].length();j++) covert[j] =List_content_tile[i][j]; 
			outtextxy(Tab_List::left+ 5 , top+ CONTENT_SPACE + i*(font_size*8+ CONTENT_SPACE*2+1), covert);
			
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
	int ID;
	const int left = SCREAN_W / 2 - 200;
	const int top = SCREAN_H / 2 - 100;
	const int right = SCREAN_W / 2 + 200;
	const int bottom = SCREAN_H / 2 + 100;
	int color = 9;

	/*cancel button*/
	int c_b_left = right - 50;
	int c_b_right = right;
	int c_b_top = top;
	int c_b_bottom = top + 25;

	/*set backup ID array*/
	short int B_R[201][401];

	/*Set backup layer*/
	void *bitmap; // get a ID memory pointer for layer. 

	void set_active()
	{

		int y;
		int x;
		int y2;
		int x2;
		
		/*set backup ID */
		bitmap = malloc(imagesize(left, top, right, bottom)); // set memory for image 
		getimage(left, top, right, bottom, bitmap); //save area scream.
	
		
		/*save pixels ID*/
		for (y = top, y2 = 0; y <= bottom; y++, y2++)
		{
			for (x = left, x2 = 0; x <= right; x++, x2++)
			{
				B_R[y2][x2] = R[y][x];
				R[y][x] = ID;
			}
		};

		/*set cancel ID*/
		for (y = c_b_top, y2 = 0; y <= c_b_bottom; y++, y2++)
		{
			for (x = c_b_left, x2 = 0; x <= c_b_right; x++, x2++)
			{
				R[y][x]=-ID;
			}
		};

	};


	/*show to screan*/
	void show()
	{
		set_active();
		setfillstyle(1, color);
		bar(left, top, right, bottom);

		/*cancel button*/
		setfillstyle(1, 4);
		bar(c_b_left, c_b_top, c_b_right, c_b_bottom);
		setcolor(15);
		setbkcolor(4);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(c_b_left + 22, top + 8, "X");
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

