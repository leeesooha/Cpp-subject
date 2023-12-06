#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) 
    {
        std::cout << *it << std::endl;
        ++it; 
    }
    std::stack<int> s(mstack);
    // std::cout << std::endl;
    // s.push(12);
    // s.push(33);
    // std::cout << s.top() << std::endl;

//--------------------------------------Change stack to list--------------------------------------//
    std::cout << std::endl;

    std::list<int> mstack2;

    mstack2.push_back(5);
    mstack2.push_back(17);

    std::cout << mstack2.back() << std::endl;

    mstack2.pop_back();

    std::cout << mstack2.size() << std::endl;

    mstack2.push_back(3);
    mstack2.push_back(5);
    mstack2.push_back(737);
    //[...]
    mstack2.push_back(0);

    std::list<int>::iterator it2 = mstack2.begin();
    std::list<int>::iterator ite2 = mstack2.end();

    ++it2;
    --it2;
    while (it2 != ite2) 
    {
        std::cout << *it2 << std::endl;
        ++it2; 
    }
    std::list<int> s2(mstack2);

//--------------------------------------myTest--------------------------------------//
    std::cout << std::endl;
    MutantStack<int> mystack;
    
    for (int i = 0; i < 10; i++)
    {
        mystack.push(i);
    }
    const MutantStack<int> ConstMstack = mystack;
    std::cout << *(ConstMstack.rbegin()) << std::endl;

    const MutantStack<int>::ReverseIterator ConstReverseIter1 = static_cast<const MutantStack<int>::ReverseIterator>(mystack.rbegin());
    std::cout << *(ConstReverseIter1) << std::endl;

    MutantStack<int>::ConstReverseIterator ConstReverseIter2 = static_cast<MutantStack<int>::ConstReverseIterator>(mystack.rbegin());
    std::cout << *(ConstReverseIter2) << std::endl;
    return 0;
}