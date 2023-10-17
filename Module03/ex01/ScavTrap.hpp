#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();
        std::string getName();
        unsigned int getHitPoints();
        unsigned int getEnergyPoints();
        unsigned int getAttackDamage();
        // std::string setName();
        // unsigned int setHitPoints();
        // unsigned int setEnergyPoints();
        // void setAttackDamage(unsigned int amount);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount); 
    private :
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
};

#endif