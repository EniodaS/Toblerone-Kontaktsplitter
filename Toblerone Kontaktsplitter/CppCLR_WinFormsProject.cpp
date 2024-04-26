#include "pch.h"




#include "Form1.h"

using namespace System;
using namespace System::Diagnostics; // nur für debug zwecke
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

[STAThread]
int main()
{


  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::Form1());

  return 0;
}