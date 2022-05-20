#include "servivors.h"

servivors::servivors() : servivors(0, 0) {}
servivors::servivors(int fst, int snd) : fstServ(fst), sndServ(snd) {}

void servivors::setFst(int fst) {
	this->fstServ = fst;
}

void servivors::setSnd(int snd) {
	this->sndServ = snd;
}

int servivors::getFst() {
	return this->fstServ;
}

int servivors::getSnd() {
	return this->sndServ;
}
