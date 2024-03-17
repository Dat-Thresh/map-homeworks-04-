#include <iostream>
#include "shape.h"
#include "transform.h"


int main() {
	setlocale(LC_ALL, "rus");
	try {
		std::vector<int> a{ 0, 2, 0, 2 };
		std::vector<int> b{ 2, 0, 2, 0 };
		std::vector<int> z{ 5, 6 };
		Data data(a, b, z);
		data.print_data();
		Shape shape(1, data);

		auto vol = shape.volume;
		auto sqr = shape.square;

	
		std::cout << "vol = " << vol << "\n sqr = " << sqr << std::endl;

		std::cout << std::endl << "BEFORE" << std::endl;
		for (auto el : shape.getFullCoord()) {
			for (auto el_el : el) {
				std::cout << el_el << " ";
			}
			std::cout << std::endl;
		}
		transform tr(shape);
		tr.scaleX(4);
		tr.scaleY(-4);
		//tr.scaleZ(-1);
		std::cout << "after trans" << std::endl;
	

		for (auto el : shape.getFullCoord()) {
			for (auto el_el : el) {
				std::cout << el_el << " ";
			}
			std::cout << std::endl;
		}

	}
	catch (std::exception& er) {
		std::cout << er.what() << std::endl;
	}
	return 0;

}