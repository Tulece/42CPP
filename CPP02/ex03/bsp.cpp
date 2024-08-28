#include "Point.hpp"

// Fonction pour calculer l'aire d'un triangle donné par trois points
static Fixed area(Point const &p1, Point const &p2, Point const &p3) {
	return Fixed((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
				  p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
				  p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed A = area(a, b, c);  // Aire du triangle ABC
	Fixed A1 = area(point, b, c);  // Aire du triangle PBC
	Fixed A2 = area(a, point, c);  // Aire du triangle APC
	Fixed A3 = area(a, b, point);  // Aire du triangle ABP

	// Le point est à l'intérieur si les aires sont égales et non nulles
	return (A1 > 0 && A2 > 0 && A3 > 0) && (A == (A1 + A2 + A3));
}
