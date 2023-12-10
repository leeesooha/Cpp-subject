#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
    public :
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal &other);
        AAnimal& operator=(const AAnimal& other);
        virtual ~AAnimal();
        virtual std::string getType() const;
        virtual void makeSound() const = 0;
    protected :
        std::string _type;
};

#endif