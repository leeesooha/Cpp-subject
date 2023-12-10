#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>


class Brain
{
    public :
        Brain();
        Brain(const Brain &other);
        Brain& operator=(const Brain& other);
        virtual ~Brain();
        std::string getIdeas(const size_t index) const;
        bool setIdeas(const size_t index, const std::string ideas);
    private :
        std::string _ideas[100];
};

#endif