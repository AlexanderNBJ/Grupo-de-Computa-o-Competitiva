/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas

    CAPITAL
*/

#include <iostream>

int main()
{

    int areas[4];

    for (int i = 0; i < 4; i++)
    {

        std::cin >> areas[i];
    }

    if (areas[0] * areas[1] == areas[2] * areas[3] || areas[0] * areas[2] == areas[1] * areas[3] || areas[0] * areas[3] == areas[1] * areas[2])
    {
        std::cout << "S" << std::endl;
    }
    else
    {
        std::cout << "N" << std::endl;
    }

    return 0;
}