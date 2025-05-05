/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <numeric>

int main()
{

    int x, y, z;

    while (std::cin >> x >> y >> z)
    {

        bool pitagoras;

        if (x * x == y * y + z * z || y * y == x * x + z * z || z * z == x * x + y * y)
        {
            if (std::gcd(std::gcd(x, y), z) == 1)
            {
                std::cout << "tripla pitagorica primitiva" << std::endl;
            }
            else
            {
                std::cout << "tripla pitagorica" << std::endl;
            }
        }
        else
        {
            std::cout << "tripla" << std::endl;
        }
    }

    return 0;
}