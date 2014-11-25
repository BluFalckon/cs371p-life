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

AbstractCell::AbstractCell(){}

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

// ----------
// ConwayCell
// ----------

ConwayCell:

// -----------
// FredkinCell
// -----------

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
