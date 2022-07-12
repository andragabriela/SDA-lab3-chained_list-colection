#include "IteratorColectie.h"
#include "Colectie.h"

//Complexitate Theta(1)
IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	/* de adaugat */
	elemCurent = col.colectieLDI->prim;
	frecvCurenta = 1;
}
//Complexitate Theta(1)
void IteratorColectie::prim() {
	/* de adaugat */
	elemCurent = col.colectieLDI->prim;
	frecvCurenta = 1;
}

//Complexitate Theta(1)
//muta iteratorul in container
void IteratorColectie::urmator() {
	/* de adaugat */
	if (!valid()) {
		throw;
	}

	if (frecvCurenta < elemCurent->frecventa) {//daca nu am parcurs toate elementele egale cu valoarea elementului curent 
												//incrementez frecventa	
		frecvCurenta++;
	}

	else {
		elemCurent = elemCurent->urmator;
		frecvCurenta = 1;
	}
}

//Complexitate Theta(1)
bool IteratorColectie::valid() const {
	/* de adaugat */
	if (elemCurent != 0)
		return true;
	return false;
}

//returneaza valoarea elementului din container referit de iterator
//Complexitate Theta(1)
TElem IteratorColectie::element() const {
	/* de adaugat */
	if (valid()) {
		return elemCurent->elem;
	}
	else throw;
}
