#include <iostream>
#include <cmath>
int main()
{
    double a;
    double b;
    double c;

    std::cin >> a >> b >> c;

    if ((b * b - 4 * a * c) > 0) {

        std::cout << ((-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a)) << "  ";
        std::cout << ((-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a));
    }
    else if ((b * b - 4 * a * c) == 0) {

        std::cout << ((-1 * b / (2 * a)));
    }
    else {
        std::cout << "The equation has no valid solutions";
    }
    return 0;
}