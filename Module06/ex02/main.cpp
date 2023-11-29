#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    Base *basePtr;
    int randNum;

	srand(static_cast<unsigned int>(time(NULL)));
    randNum = rand();
	if (randNum % 3 == 0) {
        std::cout << "A class created" << std::endl;
        basePtr = new A;        
    } else if (randNum % 3 == 1) {
        std::cout << "B class created" << std::endl;
        basePtr = new B;
    } else {
        std::cout << "C class created" << std::endl;
        basePtr = new C;
    }
    return (basePtr);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A class pointer type" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "B class pointer type" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "C class pointer type" << std::endl;
}

void identify(Base& p)
{
    Base temp;

    try {
        temp = dynamic_cast<A&>(p);
        std::cout << "A class type" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    } try {
        temp = dynamic_cast<B&>(p);
        std::cout << "B class type" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    } try {
        temp = dynamic_cast<C&>(p);
        std::cout << "C class type" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    Base *basePtr;

    basePtr = generate();
    identify(basePtr);
    identify(*basePtr);
    delete basePtr;
    return (0);
}
