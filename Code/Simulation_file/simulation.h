#pragma once

#include <ostream>
#include <sstream>
#include <string>

#include <vector>
#include <algorithm>
#include <cstdlib>						// aléatoire
#include <queue>

#include "Machine.h"
#include "Entree.h"


const int libre = 0;
const int occupe = 1;
const int bloque = 2;
const int ENTREE = 0;
const int MACHINE_A = 1;
const int MACHINE_B = 2;
const int MACHINE_C = 3;
const int SORTIE = 4;

//==============================================

void afficherTextbox(std::string str, System::Windows::Forms::RichTextBox^  richTextBox1);
void gererEntrer(std::queue<Client>& file_m1, Machine &serveur1, Entree & entree, int & date_courante, std::vector<Client> & sortie);
void gerer_Machine_A(std::queue<Client> &file_m1, std::queue<Client> &file_m2,std::queue<Client> &file_m3, Machine &serveur1, Machine &serveur2, Machine & serveur3, Entree & entree, int & date_courante);
void gerer_Machine_B(std::queue<Client>&file_m2, std::queue<Client>&file_mA, Machine &serveur1, Machine &serveur2, std::vector<Client> & sortie, int & date_courante);
void gerer_Machine_C(std::queue<Client>&file_m3, std::queue<Client>&file_mA, Machine &serveur1, Machine &serveur3, std::vector<Client> & sortie, int & date_courante);
void simuler(int duree_sim, int duree_entre_2_cl, int duree_traitement_cl_m1, int duree_traitement_cl_m2,int duree_traitement_cl_m3, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart);

int getProchainEven(const Machine serveur1, const Machine serveur2, const Machine serveur3, const Entree entree);

bool sortByID(Client &lhs, Client &rhs);

int choix_Apres_MachA();
int choix_Apres_MachB();
int choix_Apres_MachC();

void afficherResultat(Machine serveur1, Machine serveur2, Machine serveur3, std::vector<Client> sortie, std::queue<Client>&file_m1, std::queue<Client>&file_m2, std::queue<Client>&file_m3, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
void afficher_Contenu_machine(std::ostringstream &oss, Machine machine, std::queue<Client>file, int numero);
