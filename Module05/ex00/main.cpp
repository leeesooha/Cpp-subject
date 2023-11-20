#include "Bureaucrat.hpp"
#include <cstdlib>

void leak_check(void)
{
    std::system("leaks a.out");
}

int main(void)
{
    std::atexit(leak_check);

    return (0);
}
