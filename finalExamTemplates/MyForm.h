#pragma once
#include"CControladora.h"
#include"CArchivoTexto.h"
#include<ctime>
namespace finalExamTemplates {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			g = this->CreateGraphics();
			miarchivo = new CArchivoTexto();
			//Lectura de datos.txt
			V = miarchivo->retornarNumero("datos.txt", 0);
			P = miarchivo->retornarNumero("datos.txt", 1);
			//obj controladora
			obj = new CControladora(g, V, P);
			//Bitmaps
			imgJugador = gcnew Bitmap("imagenes\\zombie.png");
			bmpFondo = gcnew Bitmap("imagenes\\fondo.png");
			imgPlantas = gcnew Bitmap("imagenes\\plantas.png");
			imgBloque = gcnew Bitmap("imagenes\\bloque.png");
		}
	private:
		CControladora* obj;
		int V; //Vidas
		int P;//Cantidad de plantas
		CArchivoTexto* miarchivo;
		Graphics^ g;
		Bitmap^ imgJugador;
		Bitmap^ bmpFondo;
		Bitmap^ imgPlantas;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblInmune;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ timeInmune;

		   Bitmap^ imgBloque;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblInmune = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->timeInmune = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vidas:";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(111, 13);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(16, 17);
			this->lblVidas->TabIndex = 1;
			this->lblVidas->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(243, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Tiempo:";
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(323, 12);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(16, 17);
			this->lblTime->TabIndex = 3;
			this->lblTime->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(405, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Inmunidad:";
			// 
			// lblInmune
			// 
			this->lblInmune->AutoSize = true;
			this->lblInmune->Location = System::Drawing::Point(517, 12);
			this->lblInmune->Name = L"lblInmune";
			this->lblInmune->Size = System::Drawing::Size(42, 17);
			this->lblInmune->TabIndex = 5;
			this->lblInmune->Text = L"False";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(629, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(128, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Tiempo Inmunidad:";
			// 
			// timeInmune
			// 
			this->timeInmune->AutoSize = true;
			this->timeInmune->Location = System::Drawing::Point(787, 12);
			this->timeInmune->Name = L"timeInmune";
			this->timeInmune->Size = System::Drawing::Size(16, 17);
			this->timeInmune->TabIndex = 7;
			this->timeInmune->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(881, 519);
			this->Controls->Add(this->timeInmune);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lblInmune);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblTime);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(BackColor);
		buffer->Graphics->DrawImage(bmpFondo, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);
		obj->run(buffer->Graphics, imgJugador, imgPlantas, imgBloque);
		lblTime->Text = "" + obj->getTime();
		lblVidas->Text = "" + obj->getVidas();
		timeInmune->Text = "" + obj->getTimepoInmune();
		if (obj->getInmunidad())
		{
			lblInmune->Text = "True";
		}
		else
		{
			lblInmune->Text = "False";
		}
		if (obj->getGano())
		{
			timer1->Enabled = false;
			MessageBox::Show("Ganaste");
			this->Close();
		}
		else if (obj->getPerdio())
		{
			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
			this->Close();
		}
		else
		{
			buffer->Render(g);
		}
		delete buffer;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyData)
		{
		case Keys::Left:
			obj->tecla('A');
			break;
		case Keys::Right:
			obj->tecla('D');
			break;
		case Keys::Up:
			obj->tecla('W');
			break;
		case Keys::Down:
			obj->tecla('S');
			break;
		}

	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		obj->tecla('N');
	}
	};
}
