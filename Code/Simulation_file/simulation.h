#pragma once

#ifndef SIMULATION
#define SIMULATION


#include <ostream>
#include <sstream>
#include <string>

#include <algorithm>
#include <cstdlib>						// aléatoire
#include <vector>

#include "Client.h"
#include "File.h"
#include "Machine.h"
#include "Entree.h"


const int libre = 0;
const int occupe = 1;
const int bloque = 2;
const int MACHINE1 = 0;
const int MACHINE2 = 1;
const int MACHINE3 = 2;
const int SORTIE = 3;

//==============================================

void afficherTextbox(std::string str, System::Windows::Forms::RichTextBox^  richTextBox1);
void gererEntrer(File & file_m1, Machine &serveur1, Entree & entree, int & date_courante, std::vector<Client> & sortie);
void gererMachine1(File & file_m1, File &file_m2, Machine &serveur1, Machine &serveur2, Entree & entree, int & date_courante);
void gererMachine2(File &file_m2, Machine &serveur1, Machine &serveur2, std::vector<Client> & sortie, int & date_courante);
void simuler(int duree_sim, int duree_entre_2_cl, int duree_traitement_cl_m1, int duree_traitement_cl_m2, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart);

int getProchainEven(const Machine serveur1, const Machine serveur2, const Entree entree);

bool sortByID(Client &lhs, Client &rhs);

int choix_Apres_MachA(int q);
int choix_Apres_MachB(int q);
int choix_Apres_MachC(int q);

#endif