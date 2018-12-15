#pragma once

template <typename T>
class Entree {
	T date_prochain_event;
	T duree_inter_arrivee;
	int dernier_numero;

	public:
		Entree();
		Entree(T date_prochain_event, T duree_inter_arrivee, int dernier_numero);

		T getDPE();
		void setDPE(T new_dpe);
	
		T getDuree_inter_arrivee();
		void setDuree_inter_arrivee(T new_dia);

		int getDernier_numero();
		void setDernier_numero(int n_dn);
};

template <typename T>
Entree<T>::Entree() :date_prochain_event(0), dernier_numero(0) {
}
template <typename T>
Entree<T>::Entree(T dpe, T dia, int dn) : date_prochain_event(dpe), duree_inter_arrivee(dia), dernier_numero(dn) {
}

template <typename T>
T Entree<T>::getDPE() {
	return date_prochain_event;
}
template <typename T>
void Entree<T>::setDPE(T dpe) {
	date_prochain_event = dpe;
}

template <typename T>
T Entree<T>::getDuree_inter_arrivee() {
	return duree_inter_arrivee;
}
template <typename T>
void Entree<T>::setDuree_inter_arrivee(T new_dia) {
	duree_inter_arrivee = new_dia;
}

template <typename T>
int Entree<T>::getDernier_numero() {
	return dernier_numero;
}
template <typename T>
void Entree<T>::setDernier_numero(int n_dn) {
	dernier_numero = n_dn;
}