#include "Affichage.h"


/*=======================================================*/
/*							AFFICHAGE   				 */
/*=======================================================*/

void afficherResultat(int duree_simulation, Machine_db serveur_A, Machine_db serveur_B, Machine_db serveur_C, std::vector<Client_db> sortie, std::queue<Client_db> &file_mA, std::queue<Client_db> &file_mB, std::queue<Client_db> &file_mC, System::Windows::Forms::RichTextBox^  richTextBox1, System::Windows::Forms::DataVisualization::Charting::Chart^ chart) {
	std::ostringstream oss;

	int nb_piece = 0;
	double temps_moyen = 0;

	for (Client_db cl : sortie) {
		nb_piece++;
		oss << "    id : " << cl.getId() << "   || entree : " << cl.getDate_entree_syst() << "   || sortie : " << cl.getDate_sortie_syst() << "   || Gamme : ";
		for (int i = 0; i < cl.getNb_machines_vues(); i++) {
			oss << cl.getMachine(i) << " ";
		}
		oss << "\n";
		temps_moyen += cl.getDate_sortie_syst() -cl.getDate_entree_syst();
		chart->Series[0]->Points->AddXY(nb_piece, temps_moyen / nb_piece);
	}

	afficher_Contenu_machine(oss, serveur_A, file_mA, MACHINE_A);
	afficher_Contenu_machine(oss, serveur_B, file_mB, MACHINE_B);
	afficher_Contenu_machine(oss, serveur_C, file_mC, MACHINE_C);

	
	oss << "\n\nNombre moyen client fileA : " << (float) serveur_A.getDuree_occupation() / duree_simulation;
	oss << "\nNombre moyen client fileB : " << (float) serveur_B.getDuree_occupation() / duree_simulation;
	oss << "\nNombre moyen client fileC : " << (float) serveur_C.getDuree_occupation() / duree_simulation;
	

	afficherTextbox(oss.str(), richTextBox1);
}

void afficher_Contenu_machine(std::ostringstream &oss, Machine_db machine, std::queue<Client_db> file, int numero) {
	Client_db cl;
	oss << "\nListe des pièces dans la machine " << numero << ": " << file.size() << "\n";
	cl = machine.getClient_present();
	oss << "    id : " << cl.getId() << "   || entree : " << cl.getDate_entree_syst() << "   || sortie : " << cl.getDate_sortie_syst() << "\n";

	while (!file.empty()) {
		cl = file.front();
		file.pop();
		oss << "    id : " << cl.getId() << "   || entree : " << cl.getDate_entree_syst() << "   || sortie : " << cl.getDate_sortie_syst() << "\n";
	}
}

void afficherTextbox(std::string str, System::Windows::Forms::RichTextBox^  richTextBox1) {
	std::ostringstream oss;
	oss << str;
	std::string ch = oss.str();
	System::String^ result = gcnew System::String(ch.c_str());
	richTextBox1->AppendText(result);
}