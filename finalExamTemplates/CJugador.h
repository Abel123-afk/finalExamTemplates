#pragma once
#include"CMovil.h"
class CJugador : public CMovil
{
private:
	int vidas;
	int auxX;
public:
	CJugador(Graphics^ g, int vidas) : CMovil()
	{
		this->vidas = vidas;
		x = rand() % ((int)g->VisibleClipBounds.Width - width);
		auxX = x;
		y = (int)g->VisibleClipBounds.Height - height;
		maxcol = 3;
		maxfil = 4;

	}
	~CJugador()
	{

	}
	void mover(Graphics^ g)
	{
		if (x + dx<0 || x + dx + width>g->VisibleClipBounds.Width ||
			y + dy<0 || y + dy + height>g->VisibleClipBounds.Height)
		{
			movinvalido(0);
		}
		else
		{
			x += dx;
			y += dy;
		}
	}
	void mostrar(Graphics^ g, Bitmap^ bmp)
	{
		if (dx > 0)
		{
			fil = 1;
		}
		else if (dx < 0)
		{
			fil = 3;
		}
		else if (dy > 0)
		{
			fil = 2;
		}
		else if (dy < 0)
		{
			fil = 0;
		}
		else
		{
			fil = fil;
			col = 1;
		}
		Rectangle sectionShow = Rectangle(col * bmp->Width / maxcol, fil * bmp->Height / maxfil, bmp->Width / maxcol, bmp->Height / maxfil);
		bmp->MakeTransparent(bmp->GetPixel(0, 0));
		g->DrawImage(bmp, this->getRec(), sectionShow, GraphicsUnit::Pixel);
		col++;
		if (col >= maxcol)
		{
			col = 0;
		}
	}
	void setXY(Graphics^ g)
	{
		x = auxX;
		y = (int)g->VisibleClipBounds.Height - height;
	}
	void decreaseVidas()
	{
		vidas--;
	}
	int getVidas()
	{
		return vidas;
	}

};
