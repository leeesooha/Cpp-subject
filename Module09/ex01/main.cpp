#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error : Must be two arguments!" << std::endl;
        return (0);
    }
    RPN rpn;
    rpn.run(argv[1]);
    return (0);
}
