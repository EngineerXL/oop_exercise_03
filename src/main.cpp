#include "square.hpp"
#include "rectangle.hpp"
#include "trapeze.hpp"

/*
 * Инютин М А М8О-207Б-19
 * Разработать классы согласно варианту задания,
 * классы должны наследоваться от базового класса Figure.
 * Фигуры являются фигурами вращения.
 * Все классы должны поддерживать набор общих методов:
 * - Вычисление геометрического центра фигуры
 * - Вывод в стандартный поток std::cout координат вершин фигуры
 * - Вычисление площади фигуры
 * Создать программу, которая позволяет:
 * - Вводить в стандартный поток std::cin фигуры
 * - Сохранять заданные фигуры в вектор std::vector<Figure*>
 * - Вызывать для всего массива общие функции
 * - Необходимо уметь вычислять общую площадь фигур в массиве.
 * - Удалять из массива фигуру по индексу
 * Квадрат, прямоугольник, трапеция.
 */

long double TotalSquare(std::vector<Figure*> & figures) {
	long double res = 0.0;
	for (auto fig : figures) {
		res = res + fig->FigureSquare();
	}
	return res;
}

signed main() {
	long double x = 0.0, y = 0.0, a = -1.0, b = -1.0, c = -1.0;
	std::vector<Figure*> vec;

	/* Input square */
	std::cout << "Input square as follows: x y a" << std::endl;
	std::cout << "x, y is a left bottom corner cords" << std::endl;
	std::cout << "a is square side" << std::endl;
	std::cin >> x >> y >> a;
	Square * square = NULL;
	try {
		square = new Square(x, y, a);
	} catch (std::invalid_argument & ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	x = 0.0, y = 0.0, a = -1.0;
	vec.push_back(square);

	/* Input rectangle */
	std::cout << "Input rectangle as follows: x y a b" << std::endl;
	std::cout << "x, y is a left bottom corner cords" << std::endl;
	std::cout << "a and b are width and heigth" << std::endl;
	std::cin >> x >> y >> a >> b;
	Rectangle * rectangle = NULL;
	try {
		rectangle = new Rectangle(x, y, a, b);
	} catch (std::invalid_argument & ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	x = 0.0, y = 0.0, a = -1.0, b = -1.0;
	vec.push_back(rectangle);

	/* Input trapeze */
	std::cout << "Input trapeze as follows: x y a b c" << std::endl;
	std::cout << "x, y is a left bottom corner cords" << std::endl;
	std::cout << "a, b and c are larger, smaller base and side" << std::endl;
	std::cin >> x >> y >> a >> b >> c;
	Trapeze * trapeze = NULL;
	try {
		trapeze = new Trapeze(x, y, a, b, c);
	} catch (std::invalid_argument & ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	x = 0.0, y = 0.0, a = -1.0, b = -1.0, c = -1.0;
	vec.push_back(trapeze);

	for (auto fig : vec) {
		fig->FigurePrint();
		std::cout << "Center of figure is " << fig->FigureCenter() << std::endl;
		std::cout << "Square of figure is " << fig->FigureSquare() << std::endl;
	}
	std::cout << "Total square: " << TotalSquare(vec) << std::endl;
	int i = 0;
	std::cout << "Input index to remove figure" << std::endl;
	std::cin >> i;
	for (auto fig = vec.begin(); fig != vec.end() and i > 0; ++fig) {
		--i;
		if (i == 0) {
			vec.erase(fig);
		}
	}
	for (auto fig : vec) {
		fig->FigurePrint();
		std::cout << "Center of figure is " << fig->FigureCenter() << std::endl;
		std::cout << "Square of figure is " << fig->FigureSquare() << std::endl;
	}
	std::cout << "Total square after erase: " << TotalSquare(vec) << std::endl;
	return 0;
}
