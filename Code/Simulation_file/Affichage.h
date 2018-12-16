#pragma once


#include <sstream>
#include <string>
#include <queue>

#include "Machine.h"
#include "Entree.h"
#include "Constante.h"


void afficherResultat(int duree_simulation,Machine_db serveur1, Machine_db serveur2, Machine_db serveur3, std::vector<Client_db> sortie, std::queue<Client_db>&file_m1, std::queue<Client_db>&file_m2, std::queue<Client_db>&file_m3, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
void afficher_Contenu_machine(std::ostringstream &oss, Machine_db machine, std::queue<Client_db>file, int numero);

void afficherTextbox(std::string str, System::Windows::Forms::RichTextBox^  richTextBox1);