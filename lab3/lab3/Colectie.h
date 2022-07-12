#pragma once
//4.TAD Colecție–reprezentare folosind o LDI  cu perechi de forma (element, frecvență)
#define NULL_TELEM -1
typedef int TElem;

typedef struct NodLDI {
	TElem elem;
	int frecventa = 0;
	NodLDI* urmator;
	NodLDI* precedent;
} NodLDI;


typedef struct LDI {
	NodLDI* prim;
	NodLDI* ultim;
}LDI;


class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	LDI* colectieLDI;

	void insertNod(TElem elem);
	void deleteNod(NodLDI* nodCurent);
public:
	friend class Iterator;
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;


	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();
	int eliminaAparitii(int nr, TElem elem);
};

