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

typedef Machine<double> Machine_db;
typedef Entree<double> Entree_db;
typedef Client<double> Client_db;

//==============================================

void afficherTextbox(std::string str, System::Windows::Forms::RichTextBox^  richTextBox1);
void gererEntrer(std::queue<Client_db>& file_m1, Machine_db &serveur1, Entree_db & entree, double & date_courante, std::vector<Client_db> & sortie);
void gerer_Machine_A(std::queue<Client_db> &file_m1, std::queue<Client_db> &file_m2,std::queue<Client_db> &file_m3, Machine_db &serveur1, Machine_db &serveur2, Machine_db & serveur3, Entree_db & entree, double & date_courante);
void gerer_Machine_B(std::queue<Client_db>&file_m2, std::queue<Client_db>&file_mA, Machine_db &serveur1, Machine_db &serveur2, std::vector<Client_db> & sortie, double & date_courante);
void gerer_Machine_C(std::queue<Client_db>&file_m3, std::queue<Client_db>&file_mA, Machine_db &serveur1, Machine_db &serveur3, std::vector<Client_db> & sortie, double & date_courante);
void simuler(int duree_sim, double duree_entre_2_cl, double duree_traitement_cl_m1, double duree_traitement_cl_m2,double duree_traitement_cl_m3, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart);

int getProchainEven(const Machine_db serveur1, const Machine_db serveur2, const Machine_db serveur3, const Entree_db entree);

bool sortByID(Client_db &lhs, Client_db &rhs);

int choix_Apres_MachA();
int choix_Apres_MachB();
int choix_Apres_MachC();

void afficherResultat(Machine_db serveur1, Machine_db serveur2, Machine_db serveur3, std::vector<Client_db> sortie, std::queue<Client_db>&file_m1, std::queue<Client_db>&file_m2, std::queue<Client_db>&file_m3, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
void afficher_Contenu_machine(std::ostringstream &oss, Machine_db machine, std::queue<Client_db>file, int numero);
