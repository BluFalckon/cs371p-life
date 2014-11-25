

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
		Cell& operator= (const Cell& other);

		// -------------------
		// ONLY FOR TESTING!!!
		// -------------------

		char getType();
		AbstractCell* getPointer();

};

// ----------
// ConwayCell
// ----------

class ConwayCell : public AbstractCell{
	public:
		ConwayCell(bool alive);

		// -------------------
		// ONLY FOR TESTING!!!
		// -------------------

		char getType();
};

// -----------
// FredkinCell
// -----------

class FredkinCell : public AbstractCell{
	private:
		int _age;
	public:
		FredkinCell(bool alive);
		void incrementAge();

		// -------------------
		// ONLY FOR TESTING!!!
		// -------------------

		int getAge();
		char getType();
};

// -------
// Life<T>
// -------

template <typename T>

class Life{
	private:
		int _rows;
		int _cols;
		vector <vector<T> > _grid;
	public:
		Life(int rows, int cols);
		void run();
		void print();
};
