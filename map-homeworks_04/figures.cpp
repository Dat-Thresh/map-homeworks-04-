#define _USE_MATH_DEFINES
#include "figures.h"
#include <exception>
#include<cmath>

//родитель фигур
Figure::Figure() {};
double Figure::volume() {
	return 0;
}
double Figure::square() {
	return 0;
};

std::vector<std::vector<int>> Figure::getCoord() {
	std::vector<std::vector<int>> tmp{ x };
	return tmp;
}

void Figure::setCoord(int os, int index, int setting) {};

//int Figure::get_id() {
//	return id;
//}

//line
line::line() {};
void line::fill_sides() {
	sides.push_back(abs(x[0] - x[1]));
}
line::line(std::vector<int> x_coord, std::vector<int> y_coord) {
	if (x_coord.empty() || y_coord.empty()) throw std::exception("Неверный набор данных");
	x = { x_coord };
	y = { y_coord };
	
	fill_sides();

};
double line::volume() {
	return 0;
}
double line::square() {
	return 0;
}
std::vector<std::vector<int>> line::getCoord() {
	std::vector<std::vector<int>> tmp{ x,y };
	return tmp;
}
void line::setCoord(int os, int index, int setting) {
	switch (os) {
	case 0:
		x[index] = setting; break;
	case 1:
		y[index] = setting; break;
	}
};

//sqr
sqr::sqr() {};
sqr::sqr(std::vector<int> x_coord, std::vector<int> y_coord) {
	if (x_coord.empty() || y_coord.empty() || x_coord.size() != points || y_coord.size() != points) throw std::exception("Неверный набор данных");

	x = { x_coord };
	y = { y_coord };
	fill_sides();
}
void sqr::fill_sides() {
	std::cout << "setting sides..." << std::endl;
		sides.push_back(abs(x[0] - x[1]));
		sides.push_back(abs(y[0] - y[1]));
		std::cout << "side 1 = " << sides[0] << " side 2 = " << sides[1] << std::endl;

}
double sqr::square() {
	return sides[0] * sides[1];
}


//cube
cube::cube() {};
cube::cube(std::vector<int> x_coord, std::vector<int> y_coord, std::vector<int> z_coord) {
	if ((x_coord.empty() || y_coord.empty() || z_coord.empty()) || (x_coord.size() != points || y_coord.size() != points || z_coord.size() != points)){
		throw std::exception("Неверное количество данных");
	}
	x = { x_coord };
	y = { y_coord };
	z = { z_coord };
	fill_sides();
}

double cube::volume(){
	
	return sides[0]*sides[1]*sides[2];
}

void cube::fill_sides() {
		sides.push_back(abs(x[0] - x[1]));
		sides.push_back(abs(y[0] - y[1]));
		sides.push_back(abs(z[0] - z[1]));
}

double cube::square() {
	return 2 * sides[0] * sides[1] + 2 * sides[0] * sides[2] + 2 * sides[1] * sides[2];
}

std::vector<std::vector<int>> cube::getCoord() {
	std::vector<std::vector<int>> tmp{ x, y, z };
	return tmp;
}
void cube::setCoord(int os, int index, int setting) {
	switch (os) {
	case 0:
		x[index] = setting; break;
	case 1:
		y[index] = setting; break;
	case 2:
		z[index] = setting; break;
	}
}

//circle
circle::circle() {};
circle::circle(std::vector<int> _coord){
	if (_coord.size() != data_points) throw std::exception("Неверное количество данных");
	x1 = _coord[0];
	y1 = _coord[1];
	radius = _coord[2];
}

double circle::volume() {
	return 0;
}
double circle::square() {
	return M_PI * radius * radius;
}

//cylinder
cylinder::cylinder(std::vector<int> _coord) {
	if (_coord.size() != data_points) throw std::exception("Неверное количество данных");
	x1 = _coord[0];
	y1 = _coord[1];
	radius = _coord[2];
	height = _coord[3];
}
double cylinder::volume() {
	std::cout << "volume of " << id << " obj asked" << std::endl;
	return M_PI* radius * radius * height;
}
double cylinder::square() {
	std::cout << "square of " << id << " obj asked" << std::endl;
	return M_PI * radius * radius + 2 * radius * height;
}