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
char Cell::getType(){
	return 'a';
}



// ----------
// ConwayCell
// ----------

ConwayCell::ConwayCell(bool alive) :
	AbstractCell(alive)
	{}

// -------------------
// ONLY FOR TESTING!!!
// -------------------

char ConwayCell::getType(){
	return 'c';
}


// -----------
// FredkinCell
// -----------

FredkinCell::FredkinCell(bool alive) :
	AbstractCell(alive), _age(0)
	{}

void FredkinCell::incrementAge(){
	if(_futureAlive)
		++_age;
}

// -------------------
// ONLY FOR TESTING!!!
// -------------------

int FredkinCell::getAge(){
	return _age;
}
char FredkinCell::getType(){
	return 'f';
}



// -------
// Life<T>
// -------

template <typename T>
Life::Life<T>(int rows, int cols) : _rows(rows), _cols(cols) {
	for (int i = 0; i < _rows; ++i) {
		vector<T> temp(_cols, T(false));
		_grid.push_back(temp);
	}
}

void Life::run(){
	for(int i = 0; i < _rows; i++){
		for(int j = 0; j < _cols; j++){
			int numNeighborsAlive = 0;
			if(i == 0 && j == 0){
				//conway
				if(_grid[i][j].getType() == 'c'){
					if(_grid[i+1][j].getState())
						++numNeighborsAlive;
					if(_grid[i][j+1].getState())
						++numNeighborsAlive;
					if(_grid[i+1][j+1].getState())
						++numNeighborsAlive;
				}
				//fredkin
				else{
					if(_grid[i+1][j].getState())
						++numNeighborsAlive;
					if(_grid[i][j+1].getState())
						++numNeighborsAlive;
				}
			}//top left corner
			else if(i == 0 && j == cols-1){
				//conway
				if(_grid[i][j].getType() == 'c'){

				}
				//fredkin
				else{

				}
			}//top right corner
			else if(i == rows-1 && j == 0){
				//conway
				if(_grid[i][j].getType() == 'c'){

				}
				//fredkin
				else{

				}
			}//bottom left corner
			else if(i == rows-1 && j == rows-1){
				//conway
				if(_grid[i][j].getType() == 'c'){

				}
				//fredkin
				else{

				}
			}//bottom right corner
		}//for j
	}//for i
}
