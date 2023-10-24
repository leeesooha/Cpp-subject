#ifndef WRONGCat_HPP
#define WRONGCat_HPP

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>


class WrongCat : public WrongAnimal
{
    public :
        WrongCat();
        WrongCat(const WrongCat &other);
        WrongCat& operator=(const WrongCat& other);
        virtual ~WrongCat();
        virtual void makeSound() const;
};

#endif