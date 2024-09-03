// MateriaSource.cpp

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete _materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            _materias[i] = m->clone();
            delete m; // Ajoutez cette ligne pour éviter la fuite
            return;
        }
    }
    delete m; // Si aucun emplacement n'est libre, il faut aussi supprimer m ici
}


AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type) {
			return _materias[i]->clone();
		}
	}
	return NULL;
}
