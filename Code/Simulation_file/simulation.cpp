#include "simulation.h"


void simuler(int duree_sim, int duree_entre_2_cl, int duree_traitement_cl_m1, int duree_traitement_cl_m2, int duree_traitement_cl_m3, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart) {
	File file_m1;
	File file_m2;
	File file_m3;
	std::vector<Client> sortie;
	Machine serveur1(libre, infini, duree_traitement_cl_m1);
	Machine serveur2(libre, infini, duree_traitement_cl_m2);
	Machine serveur3(libre, infini, duree_traitement_cl_m3);
	Entree entree(libre, duree_entre_2_cl, 0);

	int date_courante = 0;
	srand(1);

	while (date_courante <= duree_sim) {
		/* Recherche DPE la plus petite */
		int P = getProchainEven(serveur1, serveur2, serveur3, entree);					// Si PDE entree plus petite	

		switch (P){
			case ENTREE: gererEntrer(file_m1, serveur1, entree, date_courante, sortie);
				break;
			case MACHINE1: gererMachine1(file_m1, file_m2, file_m3, serveur1, serveur2, serveur3, entree, date_courante);
				break;
			case MACHINE2: gererMachine2(file_m2, serveur1, serveur2, sortie, date_courante);
				break;
			case MACHINE3: gererMachine3(file_m3, serveur1, serveur3, sortie, date_courante);
				break;
			default: break;
		}
	}
	afficherResultat(serveur1, serveur2, serveur3, sortie, file_m1, file_m2, file_m3, richTextBox1, chart);

}

void gererMachine1(File & file_m1, File &file_m2, File &file_m3, Machine &serveur1, Machine &serveur2, Machine & serveur3, Entree & entree, int & date_courante) {
	date_courante = serveur1.getDPE();
	int futur_machine = choix_Apres_MachA();
	if (MACHINE2 == futur_machine) {
		if (file_m2.test_File_pleine()) {									// Si file m2 pleine
			serveur1.setEtat(bloque);
			serveur1.setDPE(infini);
		}
		else {
			Client piece = serveur1.getClient_present();					// La piece sort de la machine 1
			if (serveur2.getEtat() == libre) {								// si m2 libre
				piece.setMachine(MACHINE2);
				serveur2.setClient_present(piece);							// Et rentre sur la machine 2
				serveur2.setDPE(date_courante + serveur2.getDuree_traitement());
				serveur2.setEtat(occupe);
			}
			else {
				file_m2.ajout_file(piece);
			}
			if (!file_m1.test_File_Vide()) {
				Client piece_new;											// Recupération piece file_m1
				file_m1.suppression_file(piece_new);
				piece_new.setMachine(MACHINE1);
				serveur1.setClient_present(piece_new);
				serveur1.setDPE(date_courante + serveur1.getDuree_traitement());
				serveur1.setEtat(occupe);
			}
			else {
				serveur1.setEtat(libre);
				serveur1.setDPE(infini);
			}
		}
	}
	else{
		if (file_m3.test_File_pleine()) {									// Si file m2 pleine
			serveur1.setEtat(bloque);
			serveur1.setDPE(infini);
		}
		else {
			Client piece = serveur1.getClient_present();					// La piece sort de la machine 1
			if (serveur3.getEtat() == libre) {								// si m2 libre
				piece.setMachine(MACHINE2);
				serveur3.setClient_present(piece);							// Et rentre sur la machine 2
				serveur3.setDPE(date_courante + serveur3.getDuree_traitement());
				serveur3.setEtat(occupe);
			}
			else {
				file_m3.ajout_file(piece);
			}
			if (!file_m1.test_File_Vide()) {
				Client piece_new;											// Recupération piece file_m1
				file_m1.suppression_file(piece_new);
				piece_new.setMachine(MACHINE1);
				serveur1.setClient_present(piece_new);
				serveur1.setDPE(date_courante + serveur1.getDuree_traitement());
				serveur1.setEtat(occupe);
			}
			else {
				serveur1.setEtat(libre);
				serveur1.setDPE(infini);
			}
		}
	}
}

void gererMachine2(File &file_m2, Machine &serveur1, Machine &serveur2, std::vector<Client> & sortie, int & date_courante) {
	date_courante = serveur2.getDPE();
	Client cl = serveur2.getClient_present();
	if (SORTIE == choix_Apres_MachB()) {				// La pièce sort
		cl.setDate_sortie_syst(date_courante);
		sortie.push_back(cl);
	}
	else {
		/* TODO : renvoyer pièce sur l'entrée */
	}
	if (!file_m2.test_File_Vide()) {
		Client cl;
		file_m2.suppression_file(cl);
		cl.setMachine(MACHINE2);
		serveur2.setClient_present(cl);
		serveur2.setDPE(date_courante + serveur2.getDuree_traitement());
		if (serveur1.getEtat() == bloque) {
			serveur1.setEtat(occupe);
			serveur1.setDPE(date_courante);
		}
	}
	else {
		serveur2.setEtat(libre);
		serveur2.setDPE(infini);
	}
}

void gererMachine3(File &file_m3, Machine &serveur1, Machine &serveur3, std::vector<Client> & sortie, int & date_courante) {
	date_courante = serveur3.getDPE();
	Client cl = serveur3.getClient_present();
	if (SORTIE == choix_Apres_MachB()) {				// La pièce sort
		cl.setDate_sortie_syst(date_courante);
		sortie.push_back(cl);
	}
	else {
		/* TODO : renvoyer pièce sur l'entrée */
	}
	if (!file_m3.test_File_Vide()) {
		Client cl;
		file_m3.suppression_file(cl);
		cl.setMachine(MACHINE2);
		serveur3.setClient_present(cl);
		serveur3.setDPE(date_courante + serveur3.getDuree_traitement());
		if (serveur1.getEtat() == bloque) {
			serveur1.setEtat(occupe);
			serveur1.setDPE(date_courante);
		}
	}
	else {
		serveur3.setEtat(libre);
		serveur3.setDPE(infini);
	}
}


void gererEntrer(File & file_m1, Machine &serveur1, Entree & entree, int & date_courante, std::vector<Client> & sortie) {
	date_courante = entree.getDPE();
	Client cl(entree.getDernier_numero(), date_courante);
	entree.setDernier_numero(entree.getDernier_numero()+1);
	entree.setDPE(date_courante + entree.getDuree_inter_arrivee());
	if (file_m1.test_File_pleine()) {
		cl.setDate_sortie_syst(date_courante);
		sortie.push_back(cl);
	}
	else {
		if (libre == serveur1.getEtat()) {
			cl.setMachine(MACHINE1);
			serveur1.setEtat(occupe);
			serveur1.setClient_present(cl);
			serveur1.setDPE(date_courante + serveur1.getDuree_traitement());
		}
		else {
			file_m1.ajout_file(cl);
		}
	}
	entree.setDPE(date_courante + entree.getDuree_inter_arrivee());
}

int getProchainEven(Machine serveur1, Machine serveur2, Machine serveur3, Entree entree) {
	int rep = ENTREE; //entree
	if ((serveur2.getDPE() <= serveur1.getDPE()) & (serveur2.getDPE() <= entree.getDPE()) && serveur2.getDPE() <= serveur3.getDPE()){
		rep = MACHINE2;
	}
	else {
		if ((serveur3.getDPE() <= entree.getDPE()) && (serveur3.getDPE() <= serveur1.getDPE())) {
			rep = MACHINE3;
		}
		else {
			if (serveur1.getDPE() <= entree.getDPE()) {
				rep = MACHINE1;
			}
		}
	}
	return rep;
}


/* Retourne 1 = machine B ou 2 machine C*/
int choix_Apres_MachA() {
	double q = 0.4;
	double borne = RAND_MAX;
	double proba = rand() / borne;
	int rep = 1;
	if (proba > q) {
		rep = 2;
	}
	return rep;
}

int choix_Apres_MachB() {
	double p = 0.6;
	double borne = RAND_MAX;
	double proba = rand() / borne;
	int rep = SORTIE;
	if (proba > p) {
		rep = MACHINE1;
	}
	return rep;
}

/* Ici identique choix_Apres_MachC */
int choix_Apres_MachC() {
	double p = 0.6;
	double borne = RAND_MAX;
	double proba = rand() / borne;
	int rep = SORTIE;
	if (proba > p) { 
		rep = MACHINE1;
	}
	return rep;
}


bool sortByID(Client &lhs, Client &rhs) { return lhs.getId() < rhs.getId(); }

/*=======================================================*/
/*							AFFICHAGE   				 */		
/*=======================================================*/

void afficherResultat(Machine serveur1, Machine serveur2, Machine serveur3, std::vector<Client> sortie, File &file_m1, File &file_m2, File &file_m3, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart) {
	std::ostringstream oss;
	std::ostringstream oss_tmp;
	std::string res;

	Client cl;
	int nb_piece = 0, temps_moyen = 0;

	std::sort(sortie.begin(), sortie.end(), sortByID);

	for (Client cl : sortie) {
		nb_piece++;
		oss << "id : " << cl.getId() << "   || entree : " << cl.getDate_entree_syst() << "   || sortie : " << cl.getDate_sortie_syst() << "   || Gamme : ";
		for (int i = 0; i < cl.getNb_machines_vues(); i++) {
			oss << cl.getMachine(i) << " ";
		}
		oss << "\n";
		temps_moyen += cl.getDate_sortie_syst(); // -cl.getDate_entree_syst();
		chart->Series[0]->Points->AddXY(nb_piece, temps_moyen / nb_piece);
	}

	afficher_Contenu_machine(oss, serveur1, file_m1, MACHINE1);
	afficher_Contenu_machine(oss, serveur2, file_m2, MACHINE2);
	afficher_Contenu_machine(oss, serveur3, file_m3, MACHINE3);

	res = oss.str();
	afficherTextbox(res, richTextBox1);
}


void afficher_Contenu_machine(std::ostringstream &oss, Machine machine, File file, int numero) {
	Client cl;
	oss << "\nListe des pièces dans la machine " << numero << ":\n";
	cl = machine.getClient_present();
	oss << "id : " << cl.getId() << "   || entree : " << cl.getDate_entree_syst() << "   || sortie : " << cl.getDate_sortie_syst() << "\n";
	while (file.test_File_Vide()) {
		file.ajout_file(cl);
		oss << "id : " << cl.getId() << "   || entree : " << cl.getDate_entree_syst() << "   || sortie : " << cl.getDate_sortie_syst() << "\n";
	}
}

void afficherTextbox(std::string str, System::Windows::Forms::RichTextBox^  richTextBox1) {
	std::ostringstream oss;
	oss << str;
	std::string ch = oss.str();
	System::String^ result = gcnew System::String(ch.c_str());
	richTextBox1->AppendText(result);
}
