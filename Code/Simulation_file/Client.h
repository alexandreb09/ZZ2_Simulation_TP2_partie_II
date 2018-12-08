#pragma once


const int taille_max_gamme = 20;

class Client {
	int id;
	int date_entree_syst;
	int date_sortie_syst;
	int gamme[taille_max_gamme];
	int nb_machines_vues;

	public:
		Client();
		Client(int id, int des);
		Client(int id, int des, int dss);

		int getId();
		void setId(int n_id);

		int getDate_entree_syst();
		void setDate_entree_syst(int new_des);

		int getDate_sortie_syst();
		void setDate_sortie_syst(int n_dss);

		int getNb_machines_vues();
		void setNb_machines_vues(int nbmv);

		int getMachine(int indice);
		void setMachine(int machine);

		friend bool operator==(const Client & cl1, const Client & cl2);
};

bool operator==(const Client & cl1, const Client & cl2);