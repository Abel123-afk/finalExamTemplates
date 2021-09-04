#pragma once
#include"CMovil.h"
class CPlanta : public CMovil
{
private:
	int paciencia;
public:
	CPlanta(Graphics^ g) : CMovil()
	{
		x = rand() % ((int)g->VisibleClipBounds.Width - width);
		y = rand() % ((int)g->VisibleClipBounds.Height - height);
		maxcol = 8;
		maxfil = 1;
		paciencia = 96;
		col = rand() % 8;
		dx = ((rand() % 2) * 10 - 5) * 4;
		dy = ((rand() % 2) * 10 - 5) * 2;
	}
	~CPlanta()
	{

	}
	void mover(Graphics^ g)
	{
		if (x + dx<0 || x + dx + width>g->VisibleClipBounds.Width ||
			y + dy<0 || y + dy + height>g->VisibleClipBounds.Height || rand() % 100 >= paciencia)
		{
			movinvalido(1);
		}
		else
		{
			x += dx;
			y += dy;
		}
	}
	void mostrar(Graphics^ g, Bitmap^ bmp)
	{
		Rectangle sectionShow = Rectangle(col * bmp->Width / maxcol, fil * bmp->Height / maxfil, bmp->Width / maxcol, bmp->Height / maxfil);
		bmp->MakeTransparent(bmp->GetPixel(0, 0));
		g->DrawImage(bmp, this->getRec(), sectionShow, GraphicsUnit::Pixel);
	}
	void movinvalido(int n)
	{
		dx = ((rand() % 2) * 10 - 5) * 4;
		dy = ((rand() % 2) * 10 - 5) * 2;
	}


};
