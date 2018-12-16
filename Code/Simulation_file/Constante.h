#pragma once

/* PARAMETRES */


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