#include "Point.hpp"
#include <iostream>

// Prototype de la fonction bsp
bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point const &a, Point const &b, Point const &c, Point const &p, std::string testName) {
    std::cout << testName << ": ";
    if (bsp(a, b, c, p)) {
        std::cout << "Inside" << std::endl;
    } else {
        std::cout << "Outside" << std::endl;
    }
}

int main() {
    // Triangle ABC
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Points à tester
    Point p1(5.0f, 5.0f);   // Point clairement à l'intérieur
    Point p2(10.0f, 0.0f);  // Point sur le sommet B
    Point p3(7.5f, 5.0f);   // Point à l'intérieur, proche du bord AB
    Point p4(0.0f, 0.0f);   // Point sur le sommet A
    Point p5(5.0f, 0.0f);   // Point sur l'arête AB
    Point p6(5.0f, 10.0f);  // Point sur le sommet C
    Point p7(5.0f, 11.0f);  // Point juste au-dessus du sommet C, donc à l'extérieur
    Point p8(-5.0f, -5.0f); // Point clairement à l'extérieur
    Point p9(0.0f, 5.0f);   // Point à l'extérieur du triangle mais sur la même hauteur que C
    Point p10(2.5f, 5.0f);  // Point à l'intérieur, à mi-chemin entre A et C
    Point p11(10.0f, 10.0f); // Point très à l'extérieur du triangle
    Point p12(0.0f, 10.0f);  // Point sur l'extension de AC
    Point p13(10.0f, -10.0f); // Point sur l'extension de AB
    Point p14(5.0f, 5.1f);  // Point juste au-dessus de l'intérieur

    // Triangle dégénéré (tous les points alignés)
    Point a_degenerate(0.0f, 0.0f);
    Point b_degenerate(5.0f, 0.0f);
    Point c_degenerate(10.0f, 0.0f);
    Point p_degenerate_inside(7.5f, 0.0f);  // Sur la ligne mais pas un sommet
    Point p_degenerate_outside(7.5f, 1.0f); // Au-dessus de la ligne

    // Tests
    test(a, b, c, p1, "Test 1 - Point à l'intérieur du triangle");
    test(a, b, c, p2, "Test 2 - Point sur le sommet B");
    test(a, b, c, p3, "Test 3 - Point à l'intérieur, proche du bord AB");
    test(a, b, c, p4, "Test 4 - Point sur le sommet A");
    test(a, b, c, p5, "Test 5 - Point sur l'arête AB");
    test(a, b, c, p6, "Test 6 - Point sur le sommet C");
    test(a, b, c, p7, "Test 7 - Point juste au-dessus du sommet C (extérieur)");
    test(a, b, c, p8, "Test 8 - Point clairement à l'extérieur");
    test(a, b, c, p9, "Test 9 - Point à l'extérieur sur la même hauteur que C");
    test(a, b, c, p10, "Test 10 - Point à l'intérieur, à mi-chemin entre A et C");
    test(a, b, c, p11, "Test 11 - Point très à l'extérieur du triangle");
    test(a, b, c, p12, "Test 12 - Point sur l'extension de AC");
    test(a, b, c, p13, "Test 13 - Point sur l'extension de AB");
    test(a, b, c, p14, "Test 14 - Point juste au-dessus de l'intérieur");

    // Tests pour triangle dégénéré
    test(a_degenerate, b_degenerate, c_degenerate, p_degenerate_inside, "Test 15 - Triangle dégénéré, point sur la ligne");
    test(a_degenerate, b_degenerate, c_degenerate, p_degenerate_outside, "Test 16 - Triangle dégénéré, point au-dessus de la ligne");

    return 0;
}
