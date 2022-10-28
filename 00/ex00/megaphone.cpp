#include <iostream>

int main(int argc, char **argv)
{
    int j;
    int i = 0;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
           std::cout << static_cast <char> (std::toupper(argv[i][j]));  
    }
    std::cout << std::endl;
    return (0);
}