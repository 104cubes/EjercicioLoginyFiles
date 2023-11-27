#pragma once
#include <fstream>
#include "msclr/marshal_cppstd.h"
namespace MiFormEjercicioLogin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(String^ datos)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Oculto->Text = datos;
			Oculto->Visible = false;
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Oculto;
	private: System::Windows::Forms::Label^ Mostrar;
	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Oculto = (gcnew System::Windows::Forms::Label());
			this->Mostrar = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Oculto
			// 
			this->Oculto->AutoSize = true;
			this->Oculto->Location = System::Drawing::Point(114, 91);
			this->Oculto->Name = L"Oculto";
			this->Oculto->Size = System::Drawing::Size(74, 25);
			this->Oculto->TabIndex = 0;
			this->Oculto->Text = L"Oculto";
			// 
			// Mostrar
			// 
			this->Mostrar->AutoSize = true;
			this->Mostrar->Location = System::Drawing::Point(258, 91);
			this->Mostrar->Name = L"Mostrar";
			this->Mostrar->Size = System::Drawing::Size(85, 25);
			this->Mostrar->TabIndex = 1;
			this->Mostrar->Text = L"Mostrar";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1042, 450);
			this->Controls->Add(this->Mostrar);
			this->Controls->Add(this->Oculto);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		
		std::string NombreStr = msclr::interop::marshal_as<std::string>(Oculto->Text);

		std::ifstream file(NombreStr + ".txt");
		if (file.is_open()) {
			std::string contenidoArchivo((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
			file.close();
			String^ contenidoArchivoNet = msclr::interop::marshal_as<System::String^>(contenidoArchivo);
			Mostrar->Text = "Del Archivo: \n" + contenidoArchivoNet;
		}
	}
	};
}
