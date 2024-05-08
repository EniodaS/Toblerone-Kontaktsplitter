#pragma once
#include "UiService.h"

// TODO: fix UI für Designer -.-" 
//		ich horst hab im DONOTCHANGE bereich sachen gechanged
//		letzter funktionierender stand war deiner: https://github.com/EniodaS/Toblerone-Kontaktsplitter/blob/4a97cc79feb44d943b29fd25403c1035a44f32d1/Toblerone%20Kontaktsplitter/Form1.h
// TODO: Deklarative Kommentare entfernen?
// TODO: Form1 deklariativer umbenennen?
namespace CppCLRWinFormsProject
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

	private:

		DataClass^ dataClass;
		UiService^ uiService;

	public:

		Form1(void)
		{
			InitializeComponent();
			dataClass = gcnew DataClass();
			uiService = gcnew UiService(dataClass);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ ScanButton;
	private: System::Windows::Forms::Button^ UpdateButton;
	private: System::Windows::Forms::Button^ SaveButton;
	private: System::Windows::Forms::TextBox^ EingabeFeld;
	private: System::Windows::Forms::TextBox^ AusgabeFeld;
	private: System::Windows::Forms::TextBox^ AnredeFeld;
	private: System::Windows::Forms::TextBox^ GeschlechtsFeld;
	private: System::Windows::Forms::TextBox^ TitelFeld1;
	private: System::Windows::Forms::TextBox^ TitelFeld2;
	private: System::Windows::Forms::TextBox^ VornameFeld1;
	private: System::Windows::Forms::TextBox^ NachnameFeld1;
	private: System::Windows::Forms::TextBox^ VornameFeld2;
	private: System::Windows::Forms::TextBox^ NachnameFeld2;
	private: System::Windows::Forms::Label^ VornameLabel2;
	private: System::Windows::Forms::Label^ NachnameLabel2;
	private: System::Windows::Forms::Label^ LabelNotice;
	private: System::Windows::Forms::Label^ LabelInvalid;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ EingabeLabel;
	private: System::Windows::Forms::Label^ AusgabeLabel;
	private: System::Windows::Forms::Label^ AnredeLabel;
	private: System::Windows::Forms::Label^ GeschlechtsLabel;
	private: System::Windows::Forms::Label^ TitelLabel1;
	private: System::Windows::Forms::Label^ TitelLabel2;
	private: System::Windows::Forms::Label^ VornameLabel1;
	private: System::Windows::Forms::Label^ NachnameLabel1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ScanButton = (gcnew System::Windows::Forms::Button());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->EingabeFeld = (gcnew System::Windows::Forms::TextBox());
			this->AusgabeFeld = (gcnew System::Windows::Forms::TextBox());
			this->AnredeFeld = (gcnew System::Windows::Forms::TextBox());
			this->GeschlechtsFeld = (gcnew System::Windows::Forms::TextBox());
			this->TitelFeld1 = (gcnew System::Windows::Forms::TextBox());
			this->TitelFeld2 = (gcnew System::Windows::Forms::TextBox());
			this->VornameFeld1 = (gcnew System::Windows::Forms::TextBox());
			this->NachnameFeld1 = (gcnew System::Windows::Forms::TextBox());
			this->EingabeLabel = (gcnew System::Windows::Forms::Label());
			this->AusgabeLabel = (gcnew System::Windows::Forms::Label());
			this->AnredeLabel = (gcnew System::Windows::Forms::Label());
			this->GeschlechtsLabel = (gcnew System::Windows::Forms::Label());
			this->TitelLabel1 = (gcnew System::Windows::Forms::Label());
			this->TitelLabel2 = (gcnew System::Windows::Forms::Label());
			this->VornameLabel1 = (gcnew System::Windows::Forms::Label());
			this->NachnameLabel1 = (gcnew System::Windows::Forms::Label());
			this->VornameFeld2 = (gcnew System::Windows::Forms::TextBox());
			this->NachnameFeld2 = (gcnew System::Windows::Forms::TextBox());
			this->VornameLabel2 = (gcnew System::Windows::Forms::Label());
			this->NachnameLabel2 = (gcnew System::Windows::Forms::Label());
			this->LabelNotice = (gcnew System::Windows::Forms::Label());
			this->LabelInvalid = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ScanButton
			// 
			this->ScanButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ScanButton->Location = System::Drawing::Point(271, 103);
			this->ScanButton->Margin = System::Windows::Forms::Padding(4);
			this->ScanButton->Name = L"ScanButton";
			this->ScanButton->Size = System::Drawing::Size(173, 34);
			this->ScanButton->TabIndex = 1;
			this->ScanButton->Text = L"Eingabe scannen";
			this->ScanButton->UseVisualStyleBackColor = true;
			this->ScanButton->Click += gcnew System::EventHandler(this, &Form1::ScanButton_Click);
			// 
			// UpdateButton
			// 
			this->UpdateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UpdateButton->Location = System::Drawing::Point(269, 437);
			this->UpdateButton->Margin = System::Windows::Forms::Padding(4);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(173, 34);
			this->UpdateButton->TabIndex = 16;
			this->UpdateButton->Text = L"Aktualisieren";
			this->UpdateButton->UseVisualStyleBackColor = true;
			this->UpdateButton->Click += gcnew System::EventHandler(this, &Form1::UpdateButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SaveButton->Location = System::Drawing::Point(270, 552);
			this->SaveButton->Margin = System::Windows::Forms::Padding(4);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(172, 34);
			this->SaveButton->TabIndex = 2;
			this->SaveButton->Text = L"Speichern";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &Form1::SaveButton_Click);
			// 
			// EingabeFeld
			// 
			this->EingabeFeld->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EingabeFeld->Location = System::Drawing::Point(49, 63);
			this->EingabeFeld->Margin = System::Windows::Forms::Padding(4);
			this->EingabeFeld->Name = L"EingabeFeld";
			this->EingabeFeld->Size = System::Drawing::Size(395, 24);
			this->EingabeFeld->TabIndex = 0;
			this->EingabeFeld->TextChanged += gcnew System::EventHandler(this, &Form1::EingabeFeld_TextChanged);
			// 
			// AusgabeFeld
			// 
			this->AusgabeFeld->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AusgabeFeld->Location = System::Drawing::Point(49, 510);
			this->AusgabeFeld->Margin = System::Windows::Forms::Padding(4);
			this->AusgabeFeld->Name = L"AusgabeFeld";
			this->AusgabeFeld->Size = System::Drawing::Size(394, 24);
			this->AusgabeFeld->TabIndex = 14;
			// 
			// AnredeFeld
			// 
			this->AnredeFeld->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AnredeFeld->Location = System::Drawing::Point(49, 190);
			this->AnredeFeld->Margin = System::Windows::Forms::Padding(4);
			this->AnredeFeld->Name = L"AnredeFeld";
			this->AnredeFeld->Size = System::Drawing::Size(172, 24);
			this->AnredeFeld->TabIndex = 4;
			// 
			// GeschlechtsFeld
			// 
			this->GeschlechtsFeld->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GeschlechtsFeld->Location = System::Drawing::Point(272, 191);
			this->GeschlechtsFeld->Margin = System::Windows::Forms::Padding(4);
			this->GeschlechtsFeld->Name = L"GeschlechtsFeld";
			this->GeschlechtsFeld->Size = System::Drawing::Size(171, 24);
			this->GeschlechtsFeld->TabIndex = 17;
			// 
			// TitelFeld1
			// 
			this->TitelFeld1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TitelFeld1->Location = System::Drawing::Point(49, 251);
			this->TitelFeld1->Margin = System::Windows::Forms::Padding(4);
			this->TitelFeld1->Name = L"TitelFeld1";
			this->TitelFeld1->Size = System::Drawing::Size(172, 24);
			this->TitelFeld1->TabIndex = 5;
			// 
			// TitelFeld2
			// 
			this->TitelFeld2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TitelFeld2->Location = System::Drawing::Point(272, 251);
			this->TitelFeld2->Margin = System::Windows::Forms::Padding(4);
			this->TitelFeld2->Name = L"TitelFeld2";
			this->TitelFeld2->Size = System::Drawing::Size(172, 24);
			this->TitelFeld2->TabIndex = 8;
			// 
			// VornameFeld1
			// 
			this->VornameFeld1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VornameFeld1->Location = System::Drawing::Point(49, 313);
			this->VornameFeld1->Margin = System::Windows::Forms::Padding(4);
			this->VornameFeld1->Name = L"VornameFeld1";
			this->VornameFeld1->Size = System::Drawing::Size(172, 24);
			this->VornameFeld1->TabIndex = 6;
			// 
			// NachnameFeld1
			// 
			this->NachnameFeld1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NachnameFeld1->Location = System::Drawing::Point(49, 374);
			this->NachnameFeld1->Margin = System::Windows::Forms::Padding(4);
			this->NachnameFeld1->Name = L"NachnameFeld1";
			this->NachnameFeld1->Size = System::Drawing::Size(172, 24);
			this->NachnameFeld1->TabIndex = 7;
			// 
			// EingabeLabel
			// 
			this->EingabeLabel->AutoSize = true;
			this->EingabeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EingabeLabel->Location = System::Drawing::Point(46, 89);
			this->EingabeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EingabeLabel->Name = L"EingabeLabel";
			this->EingabeLabel->Size = System::Drawing::Size(61, 18);
			this->EingabeLabel->TabIndex = 3;
			this->EingabeLabel->Text = L"Eingabe";
			// 
			// AusgabeLabel
			// 
			this->AusgabeLabel->AutoSize = true;
			this->AusgabeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AusgabeLabel->Location = System::Drawing::Point(46, 536);
			this->AusgabeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->AusgabeLabel->Name = L"AusgabeLabel";
			this->AusgabeLabel->Size = System::Drawing::Size(83, 18);
			this->AusgabeLabel->TabIndex = 15;
			this->AusgabeLabel->Text = L"Briefanrede";
			this->AusgabeLabel->Click += gcnew System::EventHandler(this, &Form1::AusgabeLabel_Click);
			// 
			// AnredeLabel
			// 
			this->AnredeLabel->AutoSize = true;
			this->AnredeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AnredeLabel->Location = System::Drawing::Point(46, 216);
			this->AnredeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->AnredeLabel->Name = L"AnredeLabel";
			this->AnredeLabel->Size = System::Drawing::Size(54, 18);
			this->AnredeLabel->TabIndex = 9;
			this->AnredeLabel->Text = L"Anrede";
			// 
			// GeschlechtsLabel
			// 
			this->GeschlechtsLabel->AutoSize = true;
			this->GeschlechtsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GeschlechtsLabel->Location = System::Drawing::Point(269, 217);
			this->GeschlechtsLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->GeschlechtsLabel->Name = L"GeschlechtsLabel";
			this->GeschlechtsLabel->Size = System::Drawing::Size(83, 18);
			this->GeschlechtsLabel->TabIndex = 18;
			this->GeschlechtsLabel->Text = L"Geschlecht";
			// 
			// TitelLabel1
			// 
			this->TitelLabel1->AutoSize = true;
			this->TitelLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TitelLabel1->Location = System::Drawing::Point(46, 277);
			this->TitelLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->TitelLabel1->Name = L"TitelLabel1";
			this->TitelLabel1->Size = System::Drawing::Size(79, 18);
			this->TitelLabel1->TabIndex = 10;
			this->TitelLabel1->Text = L"Erster Titel";
			// 
			// TitelLabel2
			// 
			this->TitelLabel2->AutoSize = true;
			this->TitelLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TitelLabel2->Location = System::Drawing::Point(269, 277);
			this->TitelLabel2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->TitelLabel2->Name = L"TitelLabel2";
			this->TitelLabel2->Size = System::Drawing::Size(87, 18);
			this->TitelLabel2->TabIndex = 13;
			this->TitelLabel2->Text = L"Zweiter Titel";
			// 
			// VornameLabel1
			// 
			this->VornameLabel1->AutoSize = true;
			this->VornameLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VornameLabel1->Location = System::Drawing::Point(46, 339);
			this->VornameLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->VornameLabel1->Name = L"VornameLabel1";
			this->VornameLabel1->Size = System::Drawing::Size(112, 18);
			this->VornameLabel1->TabIndex = 11;
			this->VornameLabel1->Text = L"Erster Vorname";
			this->VornameLabel1->Click += gcnew System::EventHandler(this, &Form1::VornameLabel_Click);
			// 
			// NachnameLabel1
			// 
			this->NachnameLabel1->AutoSize = true;
			this->NachnameLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NachnameLabel1->Location = System::Drawing::Point(46, 400);
			this->NachnameLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->NachnameLabel1->Name = L"NachnameLabel1";
			this->NachnameLabel1->Size = System::Drawing::Size(124, 18);
			this->NachnameLabel1->TabIndex = 12;
			this->NachnameLabel1->Text = L"Erster Nachname";
			// 
			// VornameFeld2
			// 
			this->VornameFeld2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VornameFeld2->Location = System::Drawing::Point(271, 314);
			this->VornameFeld2->Margin = System::Windows::Forms::Padding(4);
			this->VornameFeld2->Name = L"VornameFeld2";
			this->VornameFeld2->Size = System::Drawing::Size(172, 24);
			this->VornameFeld2->TabIndex = 19;
			// 
			// NachnameFeld2
			// 
			this->NachnameFeld2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NachnameFeld2->Location = System::Drawing::Point(271, 374);
			this->NachnameFeld2->Margin = System::Windows::Forms::Padding(4);
			this->NachnameFeld2->Name = L"NachnameFeld2";
			this->NachnameFeld2->Size = System::Drawing::Size(172, 24);
			this->NachnameFeld2->TabIndex = 20;
			// 
			// VornameLabel2
			// 
			this->VornameLabel2->AutoSize = true;
			this->VornameLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VornameLabel2->Location = System::Drawing::Point(269, 340);
			this->VornameLabel2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->VornameLabel2->Name = L"VornameLabel2";
			this->VornameLabel2->Size = System::Drawing::Size(120, 18);
			this->VornameLabel2->TabIndex = 30;
			this->VornameLabel2->Text = L"Zweiter Vorname";
			this->VornameLabel2->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// NachnameLabel2
			// 
			this->NachnameLabel2->AutoSize = true;
			this->NachnameLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NachnameLabel2->Location = System::Drawing::Point(269, 400);
			this->NachnameLabel2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->NachnameLabel2->Name = L"NachnameLabel2";
			this->NachnameLabel2->Size = System::Drawing::Size(132, 18);
			this->NachnameLabel2->TabIndex = 22;
			this->NachnameLabel2->Text = L"Zweiter Nachname";
			// 
			// LabelNotice
			// 
			this->LabelNotice->AutoSize = true;
			this->LabelNotice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LabelNotice->Location = System::Drawing::Point(46, 33);
			this->LabelNotice->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LabelNotice->Name = L"LabelNotice";
			this->LabelNotice->Size = System::Drawing::Size(311, 18);
			this->LabelNotice->TabIndex = 23;
			this->LabelNotice->Text = L"Bitte geben Sie Ihre vollständigen Angaben ein.";
			this->LabelNotice->Click += gcnew System::EventHandler(this, &Form1::label1_Click_1);
			// 
			// LabelInvalid
			// 
			this->LabelInvalid->AutoSize = true;
			this->LabelInvalid->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LabelInvalid->ForeColor = System::Drawing::Color::Red;
			this->LabelInvalid->Location = System::Drawing::Point(46, 151);
			this->LabelInvalid->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LabelInvalid->MaximumSize = System::Drawing::Size(385, 0);
			this->LabelInvalid->Name = L"LabelInvalid";
			this->LabelInvalid->Size = System::Drawing::Size(328, 18);
			this->LabelInvalid->TabIndex = 24;
			this->LabelInvalid->Text = L"Bitte prüfen Sie Ihre Angaben vor dem Speichern.";
			this->LabelInvalid->Visible = false;
			this->LabelInvalid->Click += gcnew System::EventHandler(this, &Form1::label1_Click_2);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->label1->Location = System::Drawing::Point(46, 482);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(240, 18);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Briefanrede erfolgreich gespeichert.";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click_3);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(501, 617);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LabelInvalid);
			this->Controls->Add(this->LabelNotice);
			this->Controls->Add(this->NachnameLabel2);
			this->Controls->Add(this->VornameLabel2);
			this->Controls->Add(this->NachnameFeld2);
			this->Controls->Add(this->VornameFeld2);
			this->Controls->Add(this->ScanButton);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->EingabeFeld);
			this->Controls->Add(this->AusgabeFeld);
			this->Controls->Add(this->AnredeFeld);
			this->Controls->Add(this->GeschlechtsFeld);
			this->Controls->Add(this->TitelFeld1);
			this->Controls->Add(this->TitelFeld2);
			this->Controls->Add(this->VornameFeld1);
			this->Controls->Add(this->NachnameFeld1);
			this->Controls->Add(this->EingabeLabel);
			this->Controls->Add(this->AusgabeLabel);
			this->Controls->Add(this->AnredeLabel);
			this->Controls->Add(this->GeschlechtsLabel);
			this->Controls->Add(this->TitelLabel1);
			this->Controls->Add(this->TitelLabel2);
			this->Controls->Add(this->VornameLabel1);
			this->Controls->Add(this->NachnameLabel1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Toblerone Kontaktsplitter";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void ScanButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Einlesen des Eingabestring und Weitergeben an UiService
		String^ eingabe = EingabeFeld->Text;
		uiService->scan(eingabe);

		// Setzen der Angabenfelder nach erstelltem Kontakt-Objekts des UiService
		AnredeFeld->Text = uiService->getAnrede();
		GeschlechtsFeld->Text = uiService->getGeschlecht();
		TitelFeld1->Text = uiService->getTitel1();
		TitelFeld2->Text = uiService->getTitel2();
		VornameFeld1->Text = uiService->getVorname1();
		VornameFeld2->Text = uiService->getVorname2();
		NachnameFeld1->Text = uiService->getNachname1();
		NachnameFeld2->Text = uiService->getNachname2();

		// Setze außerdem den Ausgabestring
		AusgabeFeld->Text = uiService->getAusgabe();
	}

	private: System::Void UpdateButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Schreibe die aktuellen Werte aller Eingabefelder in Kontakt-Objekt
		uiService->setAnrede(AnredeFeld->Text);
		uiService->setGeschlecht(GeschlechtsFeld->Text);
		uiService->setTitel1(TitelFeld1->Text);
		uiService->setTitel2(TitelFeld2->Text);
		uiService->setVorname1(VornameFeld1->Text);
		uiService->setVorname1(VornameFeld2->Text);
		uiService->setNachname1(NachnameFeld1->Text);
		uiService->setNachname1(NachnameFeld2->Text);

		// Aktualisiere Ausgabestring
		uiService->update();

		// Setze aktualisierten Ausgabestring in GUI
		AusgabeFeld->Text = uiService->getAusgabe();
	}

	private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// "Speichern" der Angaben
		// = Zurücksetzen des Kontakt-Objekts 
		uiService->save();

		// = Leeren der Felder
		EingabeFeld->Text = "";
		AusgabeFeld->Text = "";
		AnredeFeld->Text = "";
		GeschlechtsFeld->Text = "";
		TitelFeld1->Text = "";
		TitelFeld2->Text = "";
		VornameFeld1->Text = "";
		VornameFeld2->Text = "";
		NachnameFeld1->Text = "";
		NachnameFeld2->Text = "";
	}

	private: System::Void EingabeFeld_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void VornameLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void AusgabeLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_3(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
