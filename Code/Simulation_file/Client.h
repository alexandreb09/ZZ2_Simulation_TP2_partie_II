#pragma once


const int taille_max_gamme = 20;

template <typename T>
class Client {
	int id;
	T date_entree_syst;
	T date_sortie_syst;
	int gamme[taille_max_gamme];
	int nb_machines_vues;

	public:
		Client();
		Client(int id, T des);
		Client(int id, T des, T dss);

		int getId();
		void setId(int n_id);

		T getDate_entree_syst();
		void setDate_entree_syst(T new_des);

		T getDate_sortie_syst();
		void setDate_sortie_syst(T n_dss);

		int getNb_machines_vues();
		void setNb_machines_vues(int nbmv);

		int getMachine(int indice);
		void setMachine(int machine);

		friend bool operator==(const Client & cl1, const Client & cl2);
};

template <typename T>
bool operator==(const Client<T> & cl1, const Client<T> & cl2) {
	return cl1.id == cl2.id;
}

template <typename T>
Client<T>::Client() :id(0), date_entree_syst(0), date_sortie_syst(-1), nb_machines_vues(0) {}

template <typename T>
Client<T>::Client(int id, T des) : id(id), date_entree_syst(des), date_sortie_syst(-1), nb_machines_vues(0) {}

template <typename T>
Client<T>::Client(int id, T des, T dss) : id(id), date_entree_syst(des), date_sortie_syst(dss), nb_machines_vues(0) {}


template <typename T>
int Client<T>::getId() {
	return id;
}
template <typename T>
void Client<T>::setId(int n_id) {
	id = n_id;
};

template <typename T>
T Client<T>::getDate_entree_syst() {
	return date_entree_syst;
};
template <typename T>
void Client<T>::setDate_entree_syst(T new_des) {
	date_entree_syst = new_des;
}

template <typename T>
T Client<T>::getDate_sortie_syst() {
	return date_sortie_syst;
}
template <typename T>
void Client<T>::setDate_sortie_syst(T n_dss) {
	date_sortie_syst = n_dss;
};

template <typename T>
int Client<T>::getNb_machines_vues() {
	return nb_machines_vues;
}
template <typename T>
void Client<T>::setNb_machines_vues(int nbmv) {
	nb_machines_vues = nbmv;
}

template <typename T>
int Client<T>::getMachine(int indice) {
	return gamme[indice];
}
template <typename T>
void Client<T>::setMachine(int machine) {
	gamme[nb_machines_vues] = machine;
	nb_machines_vues++;
}
