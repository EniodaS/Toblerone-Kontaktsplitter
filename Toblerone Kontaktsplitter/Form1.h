#pragma once
#include "UiService.h"

namespace CppCLRWinFormsProject
{
	// TODO: Code aufräumen, strukturieren, beschreiben, generierte Kommentare entfernen
	// TODO: Form1 deklariativer umbenennen?
	// TODO: DataClass entfernen

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

	// Button Deklaration
	private: System::Windows::Forms::Button^ ScanButton;
	private: System::Windows::Forms::Button^ UpdateButton;
	private: System::Windows::Forms::Button^ SaveButton;
	// Feld Deklaration
	private: System::Windows::Forms::TextBox^ EingabeFeld;
	private: System::Windows::Forms::TextBox^ AusgabeFeld;
	private: System::Windows::Forms::TextBox^ AnredeFeld;
	private: System::Windows::Forms::TextBox^ GeschlechtsFeld;
	private: System::Windows::Forms::TextBox^ TitelFeld1;
	private: System::Windows::Forms::TextBox^ TitelFeld2;
	private: System::Windows::Forms::TextBox^ VornameFeld;
	private: System::Windows::Forms::TextBox^ NachnameFeld;
	// Label Deklaration
	private: System::Windows::Forms::Label^ EingabeLabel;
	private: System::Windows::Forms::Label^ AusgabeLabel;
	private: System::Windows::Forms::Label^ AnredeLabel;
	private: System::Windows::Forms::Label^ GeschlechtsLabel;
	private: System::Windows::Forms::Label^ TitelLabel1;
	private: System::Windows::Forms::Label^ TitelLabel2;
	private: System::Windows::Forms::Label^ VornameLabel;
	private: System::Windows::Forms::Label^ NachnameLabel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// .............. oooooops ._.
		/// </summary>
		void InitializeComponent(void)
		{
			// Button Initialisierung
			this->ScanButton = (gcnew System::Windows::Forms::Button());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			// Feld Initialisierung
			this->EingabeFeld = (gcnew System::Windows::Forms::TextBox());
			this->AusgabeFeld = (gcnew System::Windows::Forms::TextBox());
			this->AnredeFeld = (gcnew System::Windows::Forms::TextBox());
			this->GeschlechtsFeld = (gcnew System::Windows::Forms::TextBox());
			this->TitelFeld1 = (gcnew System::Windows::Forms::TextBox());
			this->TitelFeld2 = (gcnew System::Windows::Forms::TextBox());
			this->VornameFeld = (gcnew System::Windows::Forms::TextBox());
			this->NachnameFeld = (gcnew System::Windows::Forms::TextBox());
			// Label Initialisierung
			this->EingabeLabel = (gcnew System::Windows::Forms::Label());
			this->AusgabeLabel = (gcnew System::Windows::Forms::Label());
			this->AnredeLabel = (gcnew System::Windows::Forms::Label());
			this->GeschlechtsLabel = (gcnew System::Windows::Forms::Label());
			this->TitelLabel1 = (gcnew System::Windows::Forms::Label());
			this->TitelLabel2 = (gcnew System::Windows::Forms::Label());
			this->VornameLabel = (gcnew System::Windows::Forms::Label());
			this->NachnameLabel = (gcnew System::Windows::Forms::Label());

			this->SuspendLayout();

			// Button Definition
			// ScanButton
			this->ScanButton->Location = System::Drawing::Point(279, 68);
			this->ScanButton->Name = L"ScanButton";
			this->ScanButton->Size = System::Drawing::Size(144, 23);
			this->ScanButton->TabIndex = 1;
			this->ScanButton->Text = L"Eingabe scannen";
			this->ScanButton->UseVisualStyleBackColor = true;
			this->ScanButton->Click += gcnew System::EventHandler(this, &Form1::ScanButton_Click);
			// UpdateButton
			this->UpdateButton->Location = System::Drawing::Point(279, 320);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(144, 29);
			this->UpdateButton->TabIndex = 16;
			this->UpdateButton->Text = L"Aktualisieren";
			this->UpdateButton->UseVisualStyleBackColor = true;
			this->UpdateButton->Click += gcnew System::EventHandler(this, &Form1::UpdateButton_Click);
			// SaveButton
			this->SaveButton->Location = System::Drawing::Point(382, 461);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(80, 27);
			this->SaveButton->TabIndex = 2;
			this->SaveButton->Text = L"Speichern";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &Form1::SaveButton_Click);

			// Feld Definition
			// EingabeFeld
			this->EingabeFeld->Location = System::Drawing::Point(12, 27);
			this->EingabeFeld->Name = L"EingabeFeld";
			this->EingabeFeld->Size = System::Drawing::Size(342, 20);
			this->EingabeFeld->TabIndex = 0;
			// AusgabeFeld
			// TODO manuelle bearbeitung/änderung disablen?
			this->AusgabeFeld->Location = System::Drawing::Point(16, 400);
			this->AusgabeFeld->Name = L"AusgabeFeld";
			this->AusgabeFeld->Size = System::Drawing::Size(341, 20);
			this->AusgabeFeld->TabIndex = 14;
			// AnredeFeld
			this->AnredeFeld->Location = System::Drawing::Point(16, 120);
			this->AnredeFeld->Name = L"AnredeFeld";
			this->AnredeFeld->Size = System::Drawing::Size(130, 20);
			this->AnredeFeld->TabIndex = 4;
			// GeschlechtsFeld
			// TODO hier multibox vllcht sinnvoll in kombination mit nicht bearbeitbarer Anrede?
			this->GeschlechtsFeld->Location = System::Drawing::Point(183, 121);
			this->GeschlechtsFeld->Name = L"GeschlechtsFeld";
			this->GeschlechtsFeld->Size = System::Drawing::Size(129, 20);
			this->GeschlechtsFeld->TabIndex = 17;
			// TitelFeld1
			this->TitelFeld1->Location = System::Drawing::Point(16, 170);
			this->TitelFeld1->Name = L"TitelFeld1";
			this->TitelFeld1->Size = System::Drawing::Size(130, 20);
			this->TitelFeld1->TabIndex = 5;
			// TitelFeld2
			this->TitelFeld2->Location = System::Drawing::Point(183, 170);
			this->TitelFeld2->Name = L"TitelFeld2";
			this->TitelFeld2->Size = System::Drawing::Size(130, 20);
			this->TitelFeld2->TabIndex = 8;
			// VornameFeld
			this->VornameFeld->Location = System::Drawing::Point(16, 220);
			this->VornameFeld->Name = L"VornameFeld";
			this->VornameFeld->Size = System::Drawing::Size(130, 20);
			this->VornameFeld->TabIndex = 6;
			// NachnameFeld
			this->NachnameFeld->Location = System::Drawing::Point(16, 270);
			this->NachnameFeld->Name = L"NachnameFeld";
			this->NachnameFeld->Size = System::Drawing::Size(130, 20);
			this->NachnameFeld->TabIndex = 7;

			// Label Definition
			// EingabeLabel
			this->EingabeLabel->AutoSize = true;
			this->EingabeLabel->Location = System::Drawing::Point(12, 50);
			this->EingabeLabel->Name = L"EingabeLabel";
			this->EingabeLabel->Size = System::Drawing::Size(46, 13);
			this->EingabeLabel->TabIndex = 3;
			this->EingabeLabel->Text = L"Eingabe";
			// AusgabeLabel
			this->AusgabeLabel->AutoSize = true;
			this->AusgabeLabel->Location = System::Drawing::Point(13, 434);
			this->AusgabeLabel->Name = L"AusgabeLabel";
			this->AusgabeLabel->Size = System::Drawing::Size(61, 13);
			this->AusgabeLabel->TabIndex = 15;
			this->AusgabeLabel->Text = L"Briefanrede";
			// AnredeLabel
			this->AnredeLabel->AutoSize = true;
			this->AnredeLabel->Location = System::Drawing::Point(13, 143);
			this->AnredeLabel->Name = L"AnredeLabel";
			this->AnredeLabel->Size = System::Drawing::Size(41, 13);
			this->AnredeLabel->TabIndex = 9;
			this->AnredeLabel->Text = L"Anrede";
			// GeschlechtsLabel
			this->GeschlechtsLabel->AutoSize = true;
			this->GeschlechtsLabel->Location = System::Drawing::Point(181, 144);
			this->GeschlechtsLabel->Name = L"GeschlechtsLabel";
			this->GeschlechtsLabel->Size = System::Drawing::Size(61, 13);
			this->GeschlechtsLabel->TabIndex = 18;
			this->GeschlechtsLabel->Text = L"Geschlecht";
			// TitelLabel1
			this->TitelLabel1->AutoSize = true;
			this->TitelLabel1->Location = System::Drawing::Point(13, 193);
			this->TitelLabel1->Name = L"TitelLabel1";
			this->TitelLabel1->Size = System::Drawing::Size(36, 13);
			this->TitelLabel1->TabIndex = 10;
			this->TitelLabel1->Text = L"Titel 1";
			// TitelLabel2
			this->TitelLabel2->AutoSize = true;
			this->TitelLabel2->Location = System::Drawing::Point(180, 193);
			this->TitelLabel2->Name = L"TitelLabel2";
			this->TitelLabel2->Size = System::Drawing::Size(36, 13);
			this->TitelLabel2->TabIndex = 13;
			this->TitelLabel2->Text = L"Titel 2";
			// VornameLabel
			this->VornameLabel->AutoSize = true;
			this->VornameLabel->Location = System::Drawing::Point(13, 243);
			this->VornameLabel->Name = L"VornameLabel";
			this->VornameLabel->Size = System::Drawing::Size(49, 13);
			this->VornameLabel->TabIndex = 11;
			this->VornameLabel->Text = L"Vorname";
			// NachnameLabel
			this->NachnameLabel->AutoSize = true;
			this->NachnameLabel->Location = System::Drawing::Point(13, 293);
			this->NachnameLabel->Name = L"NachnameLabel";
			this->NachnameLabel->Size = System::Drawing::Size(59, 13);
			this->NachnameLabel->TabIndex = 12;
			this->NachnameLabel->Text = L"Nachname";

			// Form Definition
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(501, 516);
			this->Controls->Add(this->ScanButton);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->EingabeFeld);
			this->Controls->Add(this->AusgabeFeld);
			this->Controls->Add(this->AnredeFeld);
			this->Controls->Add(this->GeschlechtsFeld);
			this->Controls->Add(this->TitelFeld1);
			this->Controls->Add(this->TitelFeld2);
			this->Controls->Add(this->VornameFeld);
			this->Controls->Add(this->NachnameFeld);
			this->Controls->Add(this->EingabeLabel);
			this->Controls->Add(this->AusgabeLabel);
			this->Controls->Add(this->AnredeLabel);
			this->Controls->Add(this->GeschlechtsLabel);
			this->Controls->Add(this->TitelLabel1);
			this->Controls->Add(this->TitelLabel2);
			this->Controls->Add(this->VornameLabel);
			this->Controls->Add(this->NachnameLabel);
			this->Name = L"Form1";
			this->Text = L"Toblerone Kontaktsplitter";
			this->ResumeLayout(false);
			this->PerformLayout();
		}

// TODO was ist das?
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
		VornameFeld->Text = uiService->getVorname1();
		NachnameFeld->Text = uiService->getNachname1();
		// TODO: add felder für vorname2, nachname2

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
		uiService->setVorname1(VornameFeld->Text);
		uiService->setNachname1(NachnameFeld->Text);

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
		VornameFeld->Text = "";
		NachnameFeld->Text = "";
	}

	};
}
