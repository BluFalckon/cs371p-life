#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "Life.h"

TEST(Life, AbstractCell1){
	AbstractCell a(true);
	ASSERT_EQ(a.getState(), false);
}

TEST(Life, AbstractCell2){
	AbstractCell a(true);
	a.changeState();
	a.progress();
	ASSERT_EQ(a.getState(), false);
}

TEST(Life, AbstractCell3){
	AbstractCell a(false);
	ASSERT_EQ(a.getState(), false);
}

TEST(Life, changeState1){
	AbstractCell a(true);
	a.changeState();
	ASSERT_EQ(a.getState(), false);
}

TEST(Life, changeState2){
	AbstractCell a(false);
	a.changeState();
	ASSERT_EQ(a.getState(), true);
}

TEST(Life, changeState3){
	AbstractCell a(true);
	a.changeState();
	a.changeState();
	ASSERT_EQ(a.getState(), false);
}

TEST(Life, progress1){
	AbstractCell a(true);
	a.progress();
	ASSERT_EQ(a.getState(), false);
}

TEST(Life, progress2){
	AbstractCell a(false);
	a.progress();
	ASSERT_EQ(a.getState(), false);
}

TEST(Life, progress3){
	AbstractCell a(true);
	a.changeState();
	a.progress();
	ASSERT_EQ(a.getState(), false);
}

TEST(Life, Cell1){
	Cell c(new AbstractCell(true));
	ASSERT_TRUE(c.getPointer());
}

// TEST(Life, Cell2){
// 	Cell c(new AbstractCell(true));
// 	Cell c2(c);
// 	ASSERT_NE(c.getPointer(), c2.getPointer());
// }

// TEST(Life, Cell3){
// 	Cell c(new AbstractCell(true));
// 	Cell c2 = c;
// 	ASSERT_NE(c.getPointer(), c2.getPointer());
// }

TEST(Life, ConwayCell1){
	ConwayCell c(true);
	ASSERT_EQ(c.getState(), false);
}

TEST(Life, ConwayCell2){
	ConwayCell c(true);
	c.changeState();
	c.progress();
	ASSERT_EQ(c.getState(), false);
}

TEST(Life, ConwayCell3){
	AbstractCell c(false);
	ASSERT_EQ(c.getState(), false);
}

TEST(Life, FredkinCell1){
	FredkinCell f(true);
	ASSERT_EQ(f.getState(), false);
}

TEST(Life, FredkinCell2){
	FredkinCell f(true);
	f.changeState();
	f.progress();
	ASSERT_EQ(f.getState(), false);
}

TEST(Life, FredkinCell3){
	FredkinCell c(false);
	ASSERT_EQ(c.getState(), false);
}

TEST(Life, incrementAge1){
	FredkinCell c(true);
	c.changeState();
	c.progress();
	c.changeState();
	c.progress();
	c.incrementAge();
	ASSERT_EQ(c.getAge(), 0);
}

TEST(Life, incrementAge2){
	FredkinCell c(false);
	c.changeState();
	c.progress();
	c.incrementAge();
	ASSERT_EQ(c.getAge(), 0);
}

TEST(Life, incrementAge3){
	FredkinCell c(false);
	c.incrementAge();
	ASSERT_EQ(c.getAge(), 0);
}





