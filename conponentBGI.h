#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <winbgim.h> 
#include <string>
using namespace std;
bool GUIkey = true;

const int SCREAN_H = 768;
const int SCREAN_W = 1366;

const int APP_LEFT = 30;
const int APP_TOP = 30;
const int APP_BOTTOM = SCREAN_H - 100;
const int APP_RIGHT = SCREAN_W - 30;

const int FUNCTION_NUMBER = 99999;
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
void Exit()
{
	GUIkey= false;
}
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
void clearStream()
{
	while(kbhit()){
		char c = getch();
	}
}
char* Int_to_Char (int x)
{
	char buffs[100];
	itoa(x,buffs,10);
	return buffs;
}
const int ENTER = 13;
const int BACKSPACE = 8;
void ScannerCode(char s[],int max, int px ,int py,int ID)
{
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(R[my][mx]== ID))) 
		break;
		
		if(kbhit())
		{
				
			char c = getch();
			
			if(l<max)
			{
				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
				}
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
				}
			}
			if(c == ENTER) break;
			if(c == BACKSPACE&&l>0){
				s[l-1] =' ';
				l--;
			}
//			cout <<s<<endl;
			printf("%s\n",s);
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]=NULL;
		}
	}
	cout<<"da ket thu\n";
	if((mx!=-1)&&(my!=-1)) F_R[R[my][mx]]();
}

struct Button
{
	short int ID;
	int left;
	int top;
	int right;
	int bottom;
	int color;
	char * tile;
	/*contructor*/
	Button(int bid, int l, int t, int r, int b, int c,char*b_t)
	{
		ID = bid;
		left = l;
		top = t;
		right = r;
		bottom = b;
		color = c;
		tile = b_t;
	};

	void show()
	{
		setfillstyle(1,color);
		bar(left, top, right, bottom);
		setbkcolor(color);
		outtextxy(left+5,(top+bottom- textheight("S"))/2,tile);	
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
	const short unsigned int CONTENT_SPACE = 10;
	
	/*set backup ID array*/
	int B_R[1000][1000];
	char **List_content_tile;
	short int *List_content_ID;
	/*Set backup layer*/
	void *bitmap; // get a ID memory pointer for layer. 

	Tab_List(int l, int t, int r, int f_s, int c, int n_o_l, char*c_tile[])
	{

		left = l;
		top = t;
		right = r;
		font_size= f_s;
		color = c;
		NUMBER_OF_LINE=n_o_l;
		bottom =  t +  n_o_l*(font_size*8 + CONTENT_SPACE*2+1);
		/*List content & ID contructor*/
		List_content_tile = c_tile;
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
			outtextxy(Tab_List::left+ 10 , top+ CONTENT_SPACE + i*(font_size*8+ CONTENT_SPACE*2+1), List_content_tile[i]);
			
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
	short int ID, cID;
	int left;
	int top;
	int right;
	int bottom;
	int color = COLOR(196,255,255);
	char *tile;
	/*cancel button*/
	int c_b_left;
	int c_b_right;
	int c_b_top;
	int c_b_bottom;

	/*set backup ID array*/
	int B_R[SCREAN_H][SCREAN_W];
	/*Set backup layer*/
	void *bitmap; // get a ID memory pointer for layer. 
	
	Dialog(int did, int dcid, int l, int t, int r, int b, int c, char tl[])
	{
		ID = did;
		cID = dcid;
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
				R[y][x]=cID;
			}
		};
	cout<< "Debug::Diaglog::set_active::4::ok" <<endl;
	};


	/*show to screan*/
	void show()
	{
		set_active();
			setfillstyle(1, color);
		/*frame*/
		bar(left, c_b_bottom, right, bottom);
			setcolor(COLOR(128,128,128));
		rectangle(left, top, right-1, bottom-1);
		/*head bar*/
			setfillstyle(1,COLOR(83,174,242));
		bar(left, top, c_b_left, c_b_bottom);
		setcolor(15);
		setbkcolor(COLOR(83,174,242));
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		outtextxy((left+c_b_left-strlen(tile))/2, (top+c_b_bottom-16)/2, tile);
		/*cancel button*/
			setfillstyle(1, 4);
		bar(c_b_left, c_b_top, c_b_right, c_b_bottom);
			
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
struct Book
{
	int left;
	int top,top_main;
	int right;
	int bottom;
	unsigned short int font_size;
	int color,t_color;
	int text_color = 0;
	int line_color = 0;
	unsigned short int NUMBER_OF_LINE;
	unsigned short int NUMBER_OF_COLUMN;
	const short unsigned int CONTENT_SPACE = 10;
	unsigned short int* column;
	/*Pages set*/
	unsigned short int CURENT_PAGE=1;
	unsigned short int TOTAL_PAGE;
	/*set backup ID array*/

	char** List_content_tile;
	char** Column_tile;
	unsigned short int *List_content_ID;
	/*Set backup layer*/


	Book(int l, int t, int r, int f_s, int c,int t_c, unsigned int n_o_l,unsigned int n_o_c,
	unsigned short int col[],char* c_tile[],char* l_tile[])
	{

		left = l;
		top = t;
		right = r;
		font_size= f_s;
		color = c;
		t_color = t_c;
		bottom =  t +  (n_o_l+2)*(font_size*8 + CONTENT_SPACE*2+1);
		NUMBER_OF_LINE=n_o_l;
		NUMBER_OF_COLUMN=n_o_c;
		column = col;
		/*Column tiles*/
		Column_tile = c_tile;
		/*List content & ID contructor*/
		List_content_tile = l_tile;
		List_content_ID = new unsigned short int[n_o_l];	
		top_main=t+(font_size*8 + CONTENT_SPACE*2+1);
		
	};
	void set_active()
	{		
		for(int n= 0; n<NUMBER_OF_LINE; n++)
			for(int i = top + (n+1)*(CONTENT_SPACE*2 + font_size*8+1); i< top + (n+2)*(CONTENT_SPACE*2 + font_size*8+1);i++)
				for(int j = left; j <= right ; j++)
					R[i][j]=List_content_ID[n];
					
	}
	void show()
	{
		
		set_active();
		
		
		setfillstyle(1, color );
		bar(left, top+font_size*8+CONTENT_SPACE*2+1, right, bottom);
		
		setcolor(line_color);//BLACK
		for(int i=1; i<=NUMBER_OF_LINE;i++)
		{
			line(left + 10, top + (i+1)*(CONTENT_SPACE*2 + font_size*8+1), right - 10, top + (i+1)*(CONTENT_SPACE*2 + font_size*8 +1));	
		}
		
		setbkcolor(color);
		setcolor(4);//RED
		settextstyle(DEFAULT_FONT, HORIZ_DIR,font_size);
		
		for(int i = 0; i<NUMBER_OF_LINE; i++)
		{
			outtextxy(left+ 10 , top+ CONTENT_SPACE + (i+1)*(font_size*8+ CONTENT_SPACE*2+1), List_content_tile[i]);
		}
		setfillstyle(1,t_color);
		/*tile bar*/
		bar(left,top,right,top+font_size*8+CONTENT_SPACE*2+1);
		setcolor(4);
		setbkcolor(t_color);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,font_size);
		outtextxy(left+10,top+CONTENT_SPACE,Column_tile[0]);
		for(int i=1;i<NUMBER_OF_COLUMN;i++)
		{
			outtextxy(left+column[i-1]+10,top+CONTENT_SPACE,Column_tile[i]);
			line(left+column[i-1],top+10,left+column[i-1],bottom-(CONTENT_SPACE*2 + font_size*8 +1) -10);
		}
		setcolor(line_color);//BLACK
		rectangle(left, top, right-1, bottom-1);
		cout <<"Book Open" <<endl <<"bottom: " << bottom <<endl; // Delete this line when release!!!	
	}
};
struct Array_Table
{
	int left;
	int top,top_main;
	int right;
	int bottom;
	unsigned short int font_size;
	int color, t_color;
	int text_color = 0;
	int line_color = 0;
	const short unsigned int CONTENT_SPACE = 10;
	unsigned short int* column;
	unsigned short int NUMBER_OF_COLUMN;
	char** Column_tile;
	unsigned short int *List_content_ID;
	char** List_content;
	int B_R[SCREAN_H][SCREAN_W];
	void *bitmap;
	Array_Table(int l, int t, int r,int b, int f_s, int c, int t_c, int n_o_c, unsigned short int col[], char* c_tile[])
	{
		left = l;
		top = t;
		top_main=t+(f_s*8 + CONTENT_SPACE*2+1);
		right = r;
		bottom = b;
		font_size= f_s;
		color = c;
		t_color = t_c;
		NUMBER_OF_COLUMN= n_o_c;
		column = col;
		Column_tile = c_tile; 
		List_content_ID= new unsigned short int[n_o_c];
		List_content = new char *[n_o_c];
		for(int i =  0; i<n_o_c;i++)
		List_content[i]= (char*) calloc(100,sizeof(char*));
		
		
	}
	free_Table()
	{
		for(int i = 0; i<NUMBER_OF_COLUMN; i++)	List_content[i]="";
		setfillstyle(1, color );
		bar(left+1, top_main+1, column[0]-1, bottom-1);
		for(int i = 1; i<NUMBER_OF_COLUMN-1; i++) bar(left+column[i]+1, top_main+1, column[i+1]-1, bottom-1);
		bar(column[NUMBER_OF_COLUMN-2]+1,top_main+1,left-1, bottom-1);	
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
			}
		}
		/*first column*/
		for(int i = top_main; i<bottom;i++)
			for(int j =left+1; j<left+column[0]-1;j++) 
			R[i][j]=List_content_ID[0];
			
		for(int n= 0; n<NUMBER_OF_COLUMN-1; n++)
			for(int i = top_main; i<bottom;i++)
			for(int j = left+column[n]+1; j<left+column[n+1]-1;j++) 
			R[i][j]=List_content_ID[n+1];
			
			
		for(int i = top_main; i<bottom;i++)
			for(int j =left+column[NUMBER_OF_COLUMN-2]+1; j<right-1;j++) 
			R[i][j]=List_content_ID[NUMBER_OF_COLUMN-1];			
	}
	void show()
	{
		
		set_active();
		for(int i = 0;i<NUMBER_OF_COLUMN;i++)
		cout<<"Array Table ID::"<<i <<"::::column::"<<column[i]<<endl;
		setfillstyle(1, color );
		bar(left, top_main, right, bottom);
		setfillstyle(1,t_color);
		bar(left,top,right,top_main);
		setcolor(4);
		setbkcolor(t_color);
		settextstyle(DEFAULT_FONT, HORIZ_DIR,font_size);
		outtextxy(left+10,top+CONTENT_SPACE,Column_tile[0]);
		for(int i=1;i<NUMBER_OF_COLUMN;i++)	
			outtextxy(left+column[i-1]+10,top+CONTENT_SPACE,Column_tile[i]);
		setcolor(COLOR(128,128,128));
		for(int i=1;i<NUMBER_OF_COLUMN;i++)
			line(left+column[i-1],top+1,left+column[i-1],bottom-1);
		rectangle(left, top, right-1, bottom-1);
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
		cout <<"Array_Table" <<endl; // Delete this line when release!!!
	};	
};
