// Simulation_file.cpp : fichier projet principal.

#include "form_main.h"

[System::STAThread]

int main(array<System::String ^> ^args){
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	Simulation_file::form_main form;
	System::Windows::Forms::Application::Run(%form);

	return 0;
}
