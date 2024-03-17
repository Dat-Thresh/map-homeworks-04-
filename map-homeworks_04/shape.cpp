#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>


void Shape::what_figure_set(Data data) {
	switch (type)
	{
	case LINE:
		figure = new line(data.x_coord, data.y_coord);
		break;
	case SQR:
		//std::cout << "type is " << SQR << std::endl;
		figure = new sqr(data.x_coord, data.y_coord);
		break;
	case CUBE:
		figure = new cube(data.x_coord, data.y_coord, data.z_coord);
		break;

	case CIRCLE:
		figure = new circle(data.x_coord);
		break;
	case CYLINDER:
		figure = new cylinder(data.x_coord);
		break;
	default:
		break;
	}

}

Shape::Shape(int _type, Data data)
{
	type = _type;
	// заполн¤ем координаты фигуры
	what_figure_set(data);

	std::cout << "figure was set" << std::endl;
	// считаем площадь фигуры
	square = figure->square();

	// считаем объем фигуры
	volume = figure->volume();

	std::cout << "obj  created!" << std::endl;

}

int Shape::getType() {
	return type;
};
void Shape::CallsetCoord(int os, int index, int setting) {
	figure->setCoord(os, index, setting);
}

std::vector<std::vector<int>> Shape::getFullCoord() {
	return figure->getCoord();
}

std::vector<int> Shape::getXco() {
	return figure->getCoord()[0];
}
std::vector<int> Shape::getYco() {
	if (figure->getCoord().size() != 2) throw std::exception("cant scale on Y-vec line object");
	return figure->getCoord()[1];
}
std::vector<int> Shape::getZco() {
	if (figure->getCoord().size() != 3) throw std::exception("cant scale on Z-vec line flat object");
	return figure->getCoord()[2];
}
