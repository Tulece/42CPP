#include "Point.hpp"
#include <iostream>

// Prototype de la fonction bsp
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    // Point bien à l'intérieur
    Point pointInside(1.0f, 1.0f);
    // Point en dehors
    Point pointOutside(11.0f, 11.0f);
    // Point sur un bord du triangle
    Point pointOnEdge(5.0f, 5.0f);
    // Point très proche du bord, mais à l'intérieur
    Point pointNearEdge(0.1f, 0.1f);
    // Point sur un sommet du triangle
    Point pointOnVertex(0.0f, 0.0f);
    // Point très proche du sommet, mais légèrement à l'intérieur
    Point pointNearVertex(0.01f, 0.01f);

    // Point au milieu exact du triangle (centre de gravité)
    Point pointCenter(3.333f, 3.333f);

    // Point proche du bord mais encore à l'intérieur
    Point pointNearOtherEdge(9.0f, 1.0f);

    // Point juste à l'extérieur d'une arête
    Point pointJustOutsideEdge(10.1f, 0.1f);

    // Point très loin du triangle
    Point pointFarAway(100.0f, 100.0f);

    // Affichage des résultats des tests
    std::cout << "Point inside: " << bsp(a, b, c, pointInside) << std::endl;
    std::cout << "Point outside: " << bsp(a, b, c, pointOutside) << std::endl;
    std::cout << "Point on edge: " << bsp(a, b, c, pointOnEdge) << std::endl;
    std::cout << "Point near edge: " << bsp(a, b, c, pointNearEdge) << std::endl;
    std::cout << "Point on vertex: " << bsp(a, b, c, pointOnVertex) << std::endl;
    std::cout << "Point near vertex: " << bsp(a, b, c, pointNearVertex) << std::endl;
    std::cout << "Point in center: " << bsp(a, b, c, pointCenter) << std::endl;
    std::cout << "Point near other edge: " << bsp(a, b, c, pointNearOtherEdge) << std::endl;
    std::cout << "Point just outside edge: " << bsp(a, b, c, pointJustOutsideEdge) << std::endl;
    std::cout << "Point far away: " << bsp(a, b, c, pointFarAway) << std::endl;

    return 0;
}
