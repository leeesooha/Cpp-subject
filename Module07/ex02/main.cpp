#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

//-----------------------------------------------mytest-----------------------------------------------//

    const int num = 30;
    Array<char> characters(num);
    char* mirror_2 = new char[num];
    for (int i = 0; i < num; i++)
    {
        char value_2 = 'a' + i;
        characters[i] = value_2;
        mirror_2[i] = value_2;
    }
    for (int i = 0; i < num; i++)
        std::cout << characters[i];
    std::cout << std::endl;
    //SCOPE
    {
        Array<char> tmp = characters;
        Array<char> test(tmp);
    }

    for (int i = 0; i < num; i++)
    {
        if (mirror_2[i] != characters[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        characters[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        characters[num] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < num; i++)
    {
        characters[i] = rand();
    }
    for (int i = 0; i < num; i++)
        std::cout << characters[i];
    std::cout << std::endl;
    delete [] mirror_2;//
    return 0;
}