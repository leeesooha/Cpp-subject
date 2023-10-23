#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    public :
        Animal();
        Animal(std::string type);
        Animal(const Animal &other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        virtual std::string getType() const;
        virtual void makeSound() const = 0;
    protected :
        std::string _type;
};

#endif