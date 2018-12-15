#pragma once

#include "Client.h"

const int infini = 9999;

template < typename T>
class Machine{
	int Etat;
	T date_prochain_event;
	T duree_traitement;
	Client<T> client_present;

	public:
		Machine();
		Machine(int Etat, T date_prochain_event, T dt);

		int getEtat();
		void setEtat(int n_Etat);

		T getDPE();
		void setDPE(T new_des);

		T getDuree_traitement();
		void setDuree_traitement(T dt);

		Client<T> getClient_present();
		void setClient_present(Client<T> n_cl);
};

template <typename T>
Machine<T>::Machine() : Etat(0), date_prochain_event(infini) {
}

template <typename T>
Machine<T>::Machine(int Etat, T dpe, T dt) : Etat(Etat), date_prochain_event(dpe), duree_traitement(dt) {
}

template <typename T>
int Machine<T>::getEtat() {
	return Etat;
}
template <typename T>
void Machine<T>::setEtat(int n_Etat) {
	Etat = n_Etat;
}

template <typename T>
T Machine<T>::getDPE() {
	return date_prochain_event;
}
template <typename T>
void Machine<T>::setDPE(T new_des) {
	date_prochain_event = new_des;
}

template <typename T>
T Machine<T>::getDuree_traitement() {
	return duree_traitement;
}
template <typename T>
void Machine<T>::setDuree_traitement(T dt) {
	duree_traitement = dt;
}

template <typename T>
Client<T> Machine<T>::getClient_present() {
	return client_present;
}
template <typename T>
void Machine<T>::setClient_present(Client<T> n_cl) {
	client_present = n_cl;
}
