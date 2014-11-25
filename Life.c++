// --------
// includes
// --------

#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

#include "Life.h"

using namespace std;

// -------------
// Abstract Cell
// -------------

AbstractCell::AbstractCell(bool alive) :
	_alive(alive), _futureAlive(false)
	{}

void AbstractCell::changeState(){
	if(_alive == true)
		_futureAlive = false;
	else
		_futureAlive = true;
}

void AbstractCell::progress(){
	_alive = _futureAlive;
	_futureAlive = false;
}

// -------------------
// ONLY FOR TESTING!!!
// -------------------

bool AbstractCell::getState(){
	return _futureAlive;
}



// ----
// Cell
// ----

Cell::Cell(AbstractCell* p){
	_p = p;
}

Cell::Cell(const Cell& other){
	_p = other._p->clone();
}

Cell::~Cell(){
	delete _p;
}

Cell& Cell::operator= (const shape& other){
	if(this == &other)
		return *this;
	delete _p;
	_p = other._p->clone();
	return *this;
}

// -------------------
// ONLY FOR TESTING!!!
// -------------------

AbstractCell* Cell::getPointer(){
	return _p;
}



// ----------
// ConwayCell
// ----------

ConwayCell::ConwayCell(bool alive) :
	AbstractCell(alive)
	{}



// -----------
// FredkinCell
// -----------

FredkinCell::FredkinCell(bool alive) :
	AbstractCell(alive), _age(0)
	{}

void FredkinCell::incrementAge(){
	++_age;
}



// -------
// Life<T>
// -------

Life::Life(int rows, int cols) : _rows(rows), _cols(cols) {
	for (int i = 0; i < _rows; ++i) {
		vector<T> temp(_cols, 0);
		_grid.push_back(temp);
	}
}

void Life::run(){
	for(int i = 0; i < _rows; i++){
		for(int j = 0; j < _cols; j++){

		}
	}
}
