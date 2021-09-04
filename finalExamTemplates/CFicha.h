#pragma once
#include"CMovil.h"
class CFicha : public CMovil
{
private:

public:
	CFicha(Graphics^ g) : CMovil()
	{
		x = rand() % ((int)g->VisibleClipBounds.Width - width);
		y = rand() % ((int)g->VisibleClipBounds.Height - height);
		width = 30;
		height = 30;
		tipo = rand() % 2 + 1;
		//tipo 1->Rectangulo
		//tipo 2->Circulo
	}
	~CFicha()
	{

	}
	void mostrar(Graphics^ g)
	{
		if (tipo == 1)
		{
			Rectangle rec = Rectangle(x, y, width, height);
			g->FillRectangle(Brushes::Red, rec);
		}
		else
		{
			Rectangle cir = Rectangle(x, y, width, height);
			g->FillEllipse(Brushes::Blue, cir);
		}
	}
};
