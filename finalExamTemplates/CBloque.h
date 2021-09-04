#pragma once
#include"CMovil.h"
class CBloque : public CMovil
{
private:

public:
	CBloque(Graphics^ g) : CMovil()
	{
		x = rand() % ((int)g->VisibleClipBounds.Width - width);
		y = rand() % ((int)g->VisibleClipBounds.Height - height);
		maxcol = 1;
		maxfil = 1;
	}
	~CBloque()
	{

	}
	void mostrar(Graphics^ g, Bitmap^ bmp)
	{
		Rectangle sectionShow = Rectangle(col * bmp->Width / maxcol, fil * bmp->Height / maxfil, bmp->Width / maxcol, bmp->Height / maxfil);
		bmp->MakeTransparent(bmp->GetPixel(0, 0));
		g->DrawImage(bmp, this->getRec(), sectionShow, GraphicsUnit::Pixel);
	}
};
