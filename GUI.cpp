#include <E:\#PTIT CAU TRUC DU LIEU GIAI THUAT\de tai CTDLGT\Quan_Ly_Vat_Tu\conponentBGI.h>
void main_frame()
{

	Frame m_f;
	m_f.ID = 0;
	m_f.setFrame(30, 30, SCREAN_W - 30, SCREAN_H - 100, 15);
	m_f.Show();
	setcolor(8);
	setlinestyle(0, 0xFFFF, 3);
	line(m_f.left + 100, m_f.top, m_f.left + 100, m_f.bottom);


}
int main(int argc, char *argv[])
{
	setbkcolor(8);
	initwindow(SCREAN_W, SCREAN_H);
	setbkcolor(8);
	main_frame();
	while(!kbhit()) delay(1);
	return 0;
};
	
