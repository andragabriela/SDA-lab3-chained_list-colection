#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


//Complexitate Theta(1)
Colectie::Colectie() {
	/* de adaugat */

	colectieLDI = new LDI;
	colectieLDI->prim = NULL;
	colectieLDI->ultim = NULL;


}

//Complexitate Theta(1)
void Colectie::insertNod(TElem elem) {
	//adaug la sfarsit un nou nod cu elementul dat si cu frecventa 1
	NodLDI* newNod = new NodLDI();
	newNod->elem = elem;
	newNod->frecventa = 1;
	newNod->urmator = NULL;
	newNod->precedent = colectieLDI->ultim;
	if (colectieLDI->prim == NULL) {//daca nu am nimic in colectie
		colectieLDI->prim = newNod;
		colectieLDI->ultim = newNod;
	}
	else {//setam pozitia legaturii urmatoare a ultimului nod la noul nod si setam ultimul nod din colectie
		//la noul nod
		colectieLDI->ultim->urmator = newNod;
		colectieLDI->ultim = newNod;
	}
}

//Complexitate Theta(1)
void Colectie::deleteNod(NodLDI* nodCurent) {
	//sterg nodul din lista (elementele a caror frecventa a ajuns la 0)
	if (nodCurent == colectieLDI->prim) {
		colectieLDI->prim = nodCurent->urmator;
	}

	if (nodCurent == colectieLDI->ultim) {
		colectieLDI->ultim = nodCurent->precedent;
	}

	if (nodCurent->urmator != NULL) {//nodul precedent nodului urmator va fi nodul precedat de nodul curent
		nodCurent->urmator->precedent = nodCurent->precedent;
	}

	if (nodCurent->precedent != NULL) {
		nodCurent->precedent->urmator = nodCurent->urmator;
	}

	delete nodCurent;
}

//Complexitate Theta(1)-best case,Theta(n)-worst case, Theta(n)-average case. Overall complexity O(n)
void Colectie::adauga(TElem elem) {
	/* de adaugat */
	NodLDI* newNod = colectieLDI->prim;
	while (newNod != NULL) {
		if (newNod->elem == elem) {
			newNod->frecventa++;
			return;
		}
		newNod = newNod->urmator;
	}
	//daca nu exista nodul cu elementul dat, adaug la sfarsit un nou nod care contine elem cu frecventa 1
	insertNod(elem);
}

//Complexitate Theta(1)-best case,Theta(n)-worst case not found, Theta(n)-average case. Overall complexity O(n)
bool Colectie::sterge(TElem elem) {
	/* de adaugat */
	NodLDI* nodCurent = colectieLDI->prim;
	while (nodCurent != NULL) {
		if (nodCurent->elem == elem) {
			nodCurent->frecventa--;
			//daca frecventa ajunge la 0, sterg nodul din lista
			if (nodCurent->frecventa == 0) {
				deleteNod(nodCurent);
			}
			return true;
		}
		nodCurent = nodCurent->urmator;
	}
	return false;
}

//Complexitate Theta(1)-best case,Theta(n)-worst case, Theta(n)-average case. Overall complexity O(n)
bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
	NodLDI* nodCurent = colectieLDI->prim;
	while (nodCurent != NULL) {
		if (nodCurent->elem == elem) {
			return true;
		}
		nodCurent = nodCurent->urmator;
	}
	return false;
}

//Complexitate Theta(1)-best case,Theta(n)-worst case, Theta(n)-average case. Overall complexity O(n)
int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
	NodLDI* nodCurent = colectieLDI->prim;
	while (nodCurent != NULL) {
		if (nodCurent->elem == elem) {
			return nodCurent->frecventa;
		}
		nodCurent = nodCurent->urmator;
	}
	return 0;
}

//Complexitate Theta(1)
int Colectie::dim() const {
	/* de adaugat */
	int count = 0;
	NodLDI* nodCurent = colectieLDI->prim;
	while (nodCurent != NULL) {
		count += nodCurent->frecventa;
		nodCurent = nodCurent->urmator;
	}

	return count;
}

//Complexitate Theta(1)
bool Colectie::vida() const {
	/* de adaugat */
	if (dim() != 0)
		return false;
	return true;
}

//Complexitate Theta(1)
IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

//Complexitate Theta(n)
Colectie::~Colectie() {
	/* de adaugat */
	NodLDI* nodCurent = colectieLDI->prim;
	while (nodCurent != colectieLDI->ultim) {
		nodCurent = nodCurent->urmator;
		delete nodCurent->precedent;
	}
	delete nodCurent;
	delete colectieLDI;
}


//complexitate caz favorabil Theta(1) cand avem elem e pe prima pozitie si apare o data
//caz defavorabil Theta(n) cand nu avem deloc numarul elem in colectie
// caz total O(n)
int Colectie::eliminaAparitii(int nr, TElem elem) {
	if (nr< 0)
		return 0;
	else {

		int nr_de_eliminari = 0;
		NodLDI* nodCurent = colectieLDI->prim;
		while (nodCurent != NULL && nr>0) {
			if (nodCurent->elem == elem) {
				deleteNod(nodCurent);
				nr_de_eliminari++;
			}	
			nodCurent = nodCurent->urmator;
			nr--;
		}
		return nr_de_eliminari;

	}

}

