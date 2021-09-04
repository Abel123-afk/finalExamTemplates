#pragma once
#include<vector>
#include<ctime>
#include"CPlanta.h"
#include"CBloque.h"
#include"CJugador.h"
#include"CFicha.h"
#include"CVector.h"
using namespace std;
using namespace System;
class CControladora
{
private:
	CJugador* jug; //Zombie
	int cantPlantas;
	CVector<CPlanta*>vec;//Arreglo de plantas
	CVector<CBloque*>bloques;
	CVector<CFicha*>fichas;
	Rectangle meta;
	bool gano, perdio, inmunidad;
	int tiempo, tiempoInmunidad;
	time_t inicio, actual;
public:
	CControladora(Graphics^ g, int vidas, int cant)
	{
		jug = new CJugador(g, vidas);
		this->cantPlantas = cant;
		//Crear plantas
		for (int i = 0; i < cantPlantas; i++)
		{
			vec.push_back(new CPlanta(g));
		}
		//crear Bloques
		for (int i = 0; i < 10; i++)
		{
			bloques.push_back(new CBloque(g));
		}
		//Rectangulo meta
		meta = Rectangle(g->VisibleClipBounds.Width / 2 - 80, 0, 400, 60);
		gano = false;
		perdio = false;
		time(&inicio);
		tiempo = 0;
		//Crear Fichas
		for (int i = 0; i < 10; i++)
		{
			fichas.push_back(new CFicha(g));
		}
		inmunidad = false;
		tiempoInmunidad = 0;
		//Reposionar si un bloque aparece dentro del rectangulo meta
		for (int i = 0; i < bloques.size(); i++)
		{
			while (colision(bloques.at(i)->getRec(), meta))
			{
				bloques.at(i)->reposicionar(g);
			}
		}
		//Verificar que no se intersecta un bloque el zombie(jugador)
		for (int i = 0; i < bloques.size(); i++)
		{
			while (colision(bloques.at(i)->getRec(), jug->getRec()))
			{
				bloques.at(i)->reposicionar(g);
			}
		}
		//verificar que no choque un bloque con fichas
		for (int i = 0; i < fichas.size(); i++)
		{
			for (int j = 0; j < bloques.size(); j++)
			{
				if (colision(fichas.at(i)->getRec(), bloques.at(j)->getRec()))
				{
					j = 0;
					fichas.at(i)->reposicionar(g);
				}
			}
		}
	}
	~CControladora()
	{
		delete jug;
		while (vec.size())
		{
			vec.erase(0);
			delete vec.at(0);
		}
	}
	void mostrarTodos(Graphics^ g, Bitmap^ imgJugador, Bitmap^ imgPlantas, Bitmap^ imgBloque)
	{
		//g->FillRectangle(Brushes::Red, meta); //Para observar el rectangulo de la meta
		jug->mostrar(g, imgJugador);
		//mostrar plantas
		for (int i = 0; i < vec.size(); i++)
		{
			vec.at(i)->mostrar(g, imgPlantas);
		}
		//Mostrar Bloques
		for (int i = 0; i < bloques.size(); i++)
		{
			bloques.at(i)->mostrar(g,imgBloque);
		}
		//Mostrar Fichas
		for (int i = 0; i < fichas.size(); i++)
		{
			fichas.at(i)->mostrar(g);
		}
	}
	void moverTodos(Graphics^ g)
	{

		//Hacer que Jugador no pueda pasar por los bloques
		for (int i = 0; i < bloques.size(); i++)
		{
			if (colision(jug->getFutRec(), bloques.at(i)->getRec()))
			{
				jug->movinvalido(0);
			}
		}
		//mover al jugador
		jug->mover(g);
		//mover las plantas
		for (int i = 0; i < vec.size(); i++)
		{
			vec.at(i)->mover(g);
		}

	}
	void run(Graphics^ g, Bitmap^ imgJugador, Bitmap^ imgPlantas, Bitmap^ imgBloque)
	{
		time(&actual);
		moverTodos(g);
		mostrarTodos(g, imgJugador, imgPlantas, imgBloque);
		verificarColisiones(g);
		if (jug->getVidas() <= 0)
		{
			perdio = true;
		}
		if (colision(jug->getRec(), meta))
		{
			gano = true;
		}
		if (difftime(actual, inicio) >= 1)
		{
			tiempo++;
			if (inmunidad)
			{
				tiempoInmunidad--;
			}
			time(&inicio);
		}
		if (tiempoInmunidad <= 0)
		{
			inmunidad = false;
		}
	}
	void verificarColisiones(Graphics^ g)
	{
		//Verificar que el jugador colisiona con una Ficha y se vuelve inmune por T segundos
		for (int i = 0; i < fichas.size(); i++)
		{
			if (colision(jug->getRec(), fichas.at(i)->getRec()))
			{
				fichas.erase(i);
				tiempoInmunidad = rand() % 7 + 6; //6<=T<=12;
				inmunidad = true;
			}

		}
		if (!inmunidad)
		{
			for (int i = 0; i < vec.size(); i++)
			{
				if (jug->colision(vec.at(i)->getRec()))
				{
					jug->setXY(g);
					jug->decreaseVidas();
					vec.erase(0);
					break;
				}
			}
		}
	}
	void tecla(char t)
	{
		switch (t)
		{
		case 'A':
			jug->setDx(-15);
			jug->setDy(0);
			break;
		case 'D':
			jug->setDx(15);
			jug->setDy(0);
			break;
		case 'W':
			jug->setDx(0);
			jug->setDy(-15);
			break;
		case 'S':
			jug->setDx(0);
			jug->setDy(15);
			break;
		case 'N':
			jug->setDx(0);
			jug->setDy(0);
			break;
		}
	}
	bool colision(Rectangle r1, Rectangle r2)
	{
		return r1.IntersectsWith(r2);
	}
	int getVidas()
	{
		return jug->getVidas();
	}
	bool getGano()
	{
		return gano;
	}
	bool getPerdio()
	{
		return perdio;
	}
	int getTime()
	{
		return tiempo;
	}
	bool getInmunidad()
	{
		return inmunidad;
	}
	int getTimepoInmune()
	{
		return tiempoInmunidad;
	}
};
