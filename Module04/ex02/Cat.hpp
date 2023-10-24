#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>


class Cat : public AAnimal
{
    public :
        Cat();
        Cat(const Cat &other);
        Cat& operator=(const Cat& other);
        virtual ~Cat();
        virtual void makeSound() const;
        virtual Brain* getBrain(void) const;
        void setBrain(Brain* brain);
    private :
        Brain *_brain;
};

#endif