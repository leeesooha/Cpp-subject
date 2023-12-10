#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>


class Dog : public Animal
{
    public :
        Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog& other);
        virtual ~Dog();
        virtual void makeSound() const;
        virtual Brain* getBrain(void) const;
        void setBrain(Brain* brain);
    private :
        Brain *_brain;
};

#endif