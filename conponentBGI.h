#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <graphics.h> 
#include <string>
using namespace std;

const int SCREAN_H = 768;
const int SCREAN_W = 1366;

const int APP_LEFT = 30;
const int APP_TOP = 30;
const int APP_H = SCREAN_H - 100;
const int APP_W = SCREAN_W - 30;

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
	for(unsigned int j=0;j<=SCREAN_W;j++)
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

	void show()
	{
		setfillstyle(1, this->color);
		bar(left, top, right, bottom);	
		for (int y = top; y <= bottom; y++)
		for (int x = left; x <= right; x++)
			R[y][x] = ID;
			
		
	}
	bool is_button_clicked()
	{
		int x, y;
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if (R[y][x] == Button::ID) return true; else return false;
	}
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


struct Dialog
{
	public:
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
		//outtextxy(c_b_left + 22, top + 8, "X");
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
	
	bool is_cancel_click()
	{
		int x, y;
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if (R[y][x] == -ID) return true; else return false; // 14/4/2017: ver 2.0.0.0
	}
};

