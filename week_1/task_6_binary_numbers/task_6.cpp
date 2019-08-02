#include <iostream>
#include <vector>

int main()

{
    unsigned int n;
    std::vector<bool> v;

    std::cin >> n;

    if (n == 0) {
        std::cout << 0;
    }
    else {
        while (n != 0)

        {
            v.push_back(n % 2);

            n /= 2;
        }

        for (int i = v.size() - 1; i >= 0; --i)

            std::cout << result[i];
    }

    return 0;
}