#include "simulation.h"


void simuler(int duree_sim, int duree_entre_2_cl, int duree_traitement_cl_m1, int duree_traitement_cl_m2, int duree_traitement_cl_m3, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart) {
	std::vector<Client> sortie;
	std::queue<Client> file_mA, file_mB, file_mC;
	Machine serveur_A(libre, infini, duree_traitement_cl_m1);
	Machine serveur_B(libre, infini, duree_traitement_cl_m2);
	Machine serveur_C(libre, infini, duree_traitement_cl_m3);
	Entree entree(libre, duree_entre_2_cl, 0);

	int date_courante = 0;
	srand(1);

	while (date_courante <= duree_sim) {
		/* Recherche DPE la plus petite */
		int machine_suivante = getProchainEven(serveur_A, serveur_B, serveur_C, entree);	

		switch (machine_suivante){
			case ENTREE: gererEntrer(file_mA, serveur_A, entree, date_courante, sortie);
				break;
			case MACHINE_A: gerer_Machine_A(file_mA, file_mB, file_mC, serveur_A, serveur_B, serveur_C, entree, date_courante);
				break;
			case MACHINE_B: gerer_Machine_B(file_mB, file_mA, serveur_A, serveur_B, sortie, date_courante);
				break;
			case MACHINE_C: gerer_Machine_C(file_mC, file_mA, serveur_A, serveur_C, sortie, date_courante);
				break;
			default: break;
		}
	}
	afficherResultat(serveur_A, serveur_B, serveur_C, sortie, file_mA, file_mB, file_mC, richTextBox1, chart);
}

void gerer_Machine_A(std::queue<Client> & file_mA, std::queue<Client> &file_mB, std::queue<Client> &file_mC, Machine &serveur_A, Machine &serveur_B, Machine & serveur_C, Entree & entree, int & date_courante) {
	date_courante = serveur_A.getDPE();
	int futur_machine = choix_Apres_MachA();
	if (MACHINE_B == futur_machine) {
		Client cl = serveur_A.getClient_present();						// La piece sort de la machine 1
		if (libre == serveur_B.getEtat()) {								// si m2 libre
			cl.setMachine(MACHINE_B);
			serveur_B.setClient_present(cl);							// Et rentre sur la machine 2
			serveur_B.setDPE(date_courante + serveur_B.getDuree_traitement());
			serveur_B.setEtat(occupe);
		}
		else {
			file_mB.push(cl);
		}
		if (0 != file_mA.size()) {
			Client piece_new = file_mA.front();											// Recupération piece file_mA
			file_mA.pop();
			piece_new.setMachine(MACHINE_A);
			serveur_A.setClient_present(piece_new);
			serveur_A.setDPE(date_courante + serveur_A.getDuree_traitement());
			serveur_A.setEtat(occupe);
		}
		else {
			serveur_A.setEtat(libre);
			serveur_A.setDPE(infini);
		}
	}
	else{
		Client piece = serveur_A.getClient_present();					// La piece sort de la machine 1
		if (libre == serveur_C.getEtat()) {								// si m2 libre
			piece.setMachine(MACHINE_B);
			serveur_C.setClient_present(piece);							// Et rentre sur la machine 2
			serveur_C.setDPE(date_courante + serveur_C.getDuree_traitement());
			serveur_C.setEtat(occupe);
		}
		else {
			file_mC.push(piece);
		}
		if (0 != file_mA.size()) {
			Client piece_new = file_mA.front();											// Recupération piece file_mA
			file_mA.pop();
			piece_new.setMachine(MACHINE_A);
			serveur_A.setClient_present(piece_new);
			serveur_A.setDPE(date_courante + serveur_A.getDuree_traitement());
			serveur_A.setEtat(occupe);
		}
		else {
			serveur_A.setEtat(libre);
			serveur_A.setDPE(infini);
		}
	}
}

void gerer_Machine_B(std::queue<Client> &file_mB, std::queue<Client> &file_mA, Machine &serveur_A, Machine &serveur_B, std::vector<Client> & sortie, int & date_courante) {
	date_courante = serveur_B.getDPE();
	Client cl = serveur_B.getClient_present();
	if (SORTIE == choix_Apres_MachB()) {				// La pièce sort
		cl.setDate_sortie_syst(date_courante);
		sortie.push_back(cl);
	}
	else {
		file_mA.push(cl);
	}
	if (0 != file_mB.size()) {
		Client cl = file_mB.front();
		file_mB.pop();
		cl.setMachine(MACHINE_B);
		serveur_B.setClient_present(cl);
		serveur_B.setDPE(date_courante + serveur_B.getDuree_traitement());
		if (bloque == serveur_A.getEtat()) {
			serveur_A.setEtat(occupe);
			serveur_A.setDPE(date_courante);
		}
	}
	else {
		serveur_B.setEtat(libre);
		serveur_B.setDPE(infini);
	}
}

void gerer_Machine_C(std::queue<Client> &file_mC, std::queue<Client> &file_mA, Machine &serveur_A, Machine &serveur_C, std::vector<Client> & sortie, int & date_courante) {
	date_courante = serveur_C.getDPE();
	Client cl = serveur_C.getClient_present();
	if (SORTIE == choix_Apres_MachB()) {				// La pièce sort
		cl.setDate_sortie_syst(date_courante);
		sortie.push_back(cl);
	}
	else {
		file_mA.push(cl);
	}
	if (0 != file_mC.size()) {
		Client cl = file_mC.front() ;
		file_mC.pop();
		cl.setMachine(MACHINE_B);
		serveur_C.setClient_present(cl);
		serveur_C.setDPE(date_courante + serveur_C.getDuree_traitement());
		if (bloque == serveur_A.getEtat()) {
			serveur_A.setEtat(occupe);
			serveur_A.setDPE(date_courante);
		}
	}
	else {
		serveur_C.setEtat(libre);
		serveur_C.setDPE(infini);
	}
}


void gererEntrer(std::queue<Client> & file_mA, Machine &serveur_A, Entree & entree, int & date_courante, std::vector<Client> & sortie) {
	date_courante = entree.getDPE();
	Client cl(entree.getDernier_numero(), date_courante);
	entree.setDernier_numero(entree.getDernier_numero()+1);
	entree.setDPE(date_courante + entree.getDuree_inter_arrivee());
	if (libre == serveur_A.getEtat()) {
		cl.setMachine(MACHINE_A);
		serveur_A.setEtat(occupe);
		serveur_A.setClient_present(cl);
		serveur_A.setDPE(date_courante + serveur_A.getDuree_traitement());
	}
	else {
		file_mA.push(cl);
	}
	entree.setDPE(date_courante + entree.getDuree_inter_arrivee());
}

int getProchainEven(Machine serveur_A, Machine serveur_B, Machine serveur_C, Entree entree) {
	int rep = ENTREE; //entree
	if ((serveur_B.getDPE() <= serveur_A.getDPE()) & (serveur_B.getDPE() <= entree.getDPE()) && serveur_B.getDPE() <= serveur_C.getDPE()){
		rep = MACHINE_B;
	}
	else {
		if ((serveur_C.getDPE() <= entree.getDPE()) && (serveur_C.getDPE() <= serveur_A.getDPE())) {
			rep = MACHINE_C;
		}
		else {
			if (serveur_A.getDPE() <= entree.getDPE()) {
				rep = MACHINE_A;
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
		rep = MACHINE_A;
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
		rep = MACHINE_A;
	}
	return rep;
}


bool sortByID(Client &lhs, Client &rhs) { return lhs.getId() < rhs.getId(); }
bool sortByDateEntree(Client &lhs, Client &rhs) { return lhs.getDate_entree_syst() < rhs.getDate_sortie_syst(); }

/*=======================================================*/
/*							AFFICHAGE   				 */		
/*=======================================================*/

void afficherResultat(Machine serveur_A, Machine serveur_B, Machine serveur_C, std::vector<Client> sortie, std::queue<Client> &file_mA, std::queue<Client> &file_mB, std::queue<Client> &file_mC, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart) {
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

	afficher_Contenu_machine(oss, serveur_A, file_mA, MACHINE_A);
	afficher_Contenu_machine(oss, serveur_B, file_mB, MACHINE_B);
	afficher_Contenu_machine(oss, serveur_C, file_mC, MACHINE_C);

	res = oss.str();
	afficherTextbox(res, richTextBox1);
}


void afficher_Contenu_machine(std::ostringstream &oss, Machine machine, std::queue<Client> file, int numero) {
	Client cl;
	oss << "\nListe des pièces dans la machine " << numero << ":\n";
	cl = machine.getClient_present();
	oss << "id : " << cl.getId() << "   || entree : " << cl.getDate_entree_syst() << "   || sortie : " << cl.getDate_sortie_syst() << "\n";

	while (!file.empty()) {
		cl = file.front();
		file.pop();
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
