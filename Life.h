#ifndef Life_h
#define Life_h

// --------
// includes
// --------

#include <vector>
#include <string>

using namespace std;

// ------------
// AbstractCell
// ------------

class AbstractCell{
	private:
		bool _alive;
		bool _futureAlive;
	public:
		AbstractCell(bool alive);
		void changeState();
		void progress();

		// -------------------
		// ONLY FOR TESTING!!!
		// -------------------

		bool getState();
};

// ----
// Cell
// ----

class Cell{
	private:
		AbstractCell* _p;
	public:
		Cell(AbstractCell* p);
		Cell(const Cell& other);
		~Cell();
		Cell& operator = (const Cell& other);

		// -------------------
		// ONLY FOR TESTING!!!
		// -------------------

		AbstractCell* getPointer();

};

// ----------
// ConwayCell
// ----------

class ConwayCell : public AbstractCell{
	public:
		ConwayCell();
};

// -----------
// FredkinCell
// -----------

class FredkinCell : public AbstractCell{
	private:
		int _age;
	public:
		FredkinCell();
		void incrementAge();
};

// -------
// Life<T>
// -------

template <typename T>

class Life<T>{
	private:
		int _rows;
		int _cols;
		vector <vector<T> > _grid;
	public:
		Life(int rows, int cols);
		void run();
		void print();
};
