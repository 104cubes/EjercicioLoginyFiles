#pragma once
#include "MyForm1.h"
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
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Bienvemida;
	private: System::Windows::Forms::Label^ eNombre;
	private: System::Windows::Forms::Label^ eContrasena;


	private: System::Windows::Forms::TextBox^ Nombre;
	private: System::Windows::Forms::TextBox^ Contrasena;
	private: System::Windows::Forms::Button^ Entrar;


	protected:


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
			this->Bienvemida = (gcnew System::Windows::Forms::Label());
			this->eNombre = (gcnew System::Windows::Forms::Label());
			this->eContrasena = (gcnew System::Windows::Forms::Label());
			this->Nombre = (gcnew System::Windows::Forms::TextBox());
			this->Contrasena = (gcnew System::Windows::Forms::TextBox());
			this->Entrar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Bienvemida
			// 
			this->Bienvemida->AutoSize = true;
			this->Bienvemida->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Bienvemida->Location = System::Drawing::Point(277, 65);
			this->Bienvemida->Name = L"Bienvemida";
			this->Bienvemida->Size = System::Drawing::Size(441, 61);
			this->Bienvemida->TabIndex = 0;
			this->Bienvemida->Text = L"Introduce tus datos";
			this->Bienvemida->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// eNombre
			// 
			this->eNombre->AutoSize = true;
			this->eNombre->Location = System::Drawing::Point(132, 210);
			this->eNombre->Name = L"eNombre";
			this->eNombre->Size = System::Drawing::Size(118, 25);
			this->eNombre->TabIndex = 1;
			this->eNombre->Text = L"Tu Nombre";
			// 
			// eContrasena
			// 
			this->eContrasena->AutoSize = true;
			this->eContrasena->Location = System::Drawing::Point(553, 210);
			this->eContrasena->Name = L"eContrasena";
			this->eContrasena->Size = System::Drawing::Size(123, 25);
			this->eContrasena->TabIndex = 2;
			this->eContrasena->Text = L"Contrasena";
			// 
			// Nombre
			// 
			this->Nombre->Location = System::Drawing::Point(137, 271);
			this->Nombre->Name = L"Nombre";
			this->Nombre->Size = System::Drawing::Size(229, 31);
			this->Nombre->TabIndex = 3;
			// 
			// Contrasena
			// 
			this->Contrasena->Location = System::Drawing::Point(558, 271);
			this->Contrasena->Name = L"Contrasena";
			this->Contrasena->Size = System::Drawing::Size(229, 31);
			this->Contrasena->TabIndex = 4;
			// 
			// Entrar
			// 
			this->Entrar->Location = System::Drawing::Point(325, 372);
			this->Entrar->Name = L"Entrar";
			this->Entrar->Size = System::Drawing::Size(286, 95);
			this->Entrar->TabIndex = 5;
			this->Entrar->Text = L"Entrar";
			this->Entrar->UseVisualStyleBackColor = true;
			this->Entrar->Click += gcnew System::EventHandler(this, &MyForm::Entrar_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1032, 599);
			this->Controls->Add(this->Entrar);
			this->Controls->Add(this->Contrasena);
			this->Controls->Add(this->Nombre);
			this->Controls->Add(this->eContrasena);
			this->Controls->Add(this->eNombre);
			this->Controls->Add(this->Bienvemida);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void Entrar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ DatosParaEnviar =
			"Bienvenido: "
			+ Nombre->Text
			+ "\n"
			+ "Tu Password es" + Contrasena->Text;

		//Convertimos de String^ a std::string
		std::string paraEnviarStr = msclr::interop::marshal_as<std::string>(DatosParaEnviar);
		std::string NombreStr = msclr::interop::marshal_as<std::string>(Nombre->Text);
		
		
		std::ofstream file(NombreStr + ".txt");//Creamos el archivo
		if (file.is_open()) {//Comprobamos si se abrió
			file << paraEnviarStr; //Escribimos en el archivo
			file.close();//Cerramos el archivo
		}

		MyForm1^ Receptor = gcnew MyForm1(Nombre->Text);
		Nombre->Text = "";
		Contrasena->Text = "";
		this->Hide();
		Receptor->ShowDialog();
		this->Show();
		
	}
};
}
