#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>


class Dog : public AAnimal
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