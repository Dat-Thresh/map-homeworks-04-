#pragma once
#include <string>
#include <vector>
#include <iostream>

//int x1 = 0, y1 = 0, z1 = 0,
//x2 = 0, y2 = 0, z2 = 0,
//x3 = 0, y3 = 0, z3 = 0,
//x4 = 0, y4 = 0, z4 = 0,
//x5 = 0, y5 = 0, z5 = 0,
//x6 = 0, y6 = 0, z6 = 0,
//x7 = 0, y7 = 0, z7 = 0,
//x8 = 0, y8 = 0, z8 = 0;


class Figure {
protected:
	const int id=-1;
	
	Figure();
public:
	std::vector<int> x;
	virtual double volume();
	virtual double square();
	//int get_id();
	virtual std::vector<std::vector<int>> getCoord();
	virtual void setCoord(int os, int index, int setting);
};

//линия
class line : public Figure {
protected:
	const int id = 0;
	int points = 2;	
	line();
public:
	std::vector<int> x, y, sides;
	line(std::vector<int> x_coord, std::vector<int> y_coord);
	void virtual fill_sides();
	double volume() override;
	double square() override;
	std::vector<std::vector<int>> getCoord() override;
	void setCoord(int os, int index, int setting) override;
};

//квадрат из линии
class sqr : public line {
	const int id = 1;
	int points = 4;

protected:
	sqr();
public:
	sqr(std::vector<int> x_coord, std::vector<int> y_coord);// :line(x_coord, y_coord) {};

	//double volume() override;
	double square() override;
	void fill_sides() override;
};

//куб
class cube : public sqr {
	const int id = 2;
	int points = 8;
protected:
	std::vector<int> z;
	cube();
public:
	cube(std::vector<int> x_coord, std::vector<int> y_coord, std::vector<int> z_coord); //:sqr(x_coord, y_coord); {};

	void fill_sides() override;
	double volume() override;
	double square() override;
	std::vector<std::vector<int>> getCoord() override;
	void setCoord(int os, int index, int setting);

};

//круг
class circle : public Figure {
	const int id = 3;
	int x1 = 0, y1 = 0;
	int data_points = 3;
	std::vector<int> coord;
	double radius;
protected:

	circle();
public:
	circle(std::vector<int> _coord);
	
	double volume() override;
	double square() override;
	//std::vector<std::vector<int>> getCoord() override;
};

//цилиндр
class cylinder : public circle {
	const int id = 4;
	int x1 = 0, y1 = 0;
	int data_points = 4;
	double radius;
	double height;
public:
	cylinder(std::vector<int> _coord); //: circle(_coord);

	double volume() override;
	double square() override;
	//std::vector<std::vector<int>> getCoord() override;
};