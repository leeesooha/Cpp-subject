#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Error" << std::endl;
        return (0);
    }
    PmergeMe fordJohnson;
    fordJohnson.run(&(argv[1]));
    return (0);
}
