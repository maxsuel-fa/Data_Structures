/*
* Main function just to test the stack data structure.
* @Author maxsuel-fa
*/
#include <iostream>
#include "Stack.hpp"

int main(void)
{
    Stack<int> st = Stack<int>(10);

    std::cout << st.size() << std::endl;

    for (int i = 0; i < 8; i++)
    {
        try
        {
            st.push(i);
        }
        catch (std::runtime_error e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "Stack size: " << st.size() << std::endl; // Expected -> Stack size: 8
    std::cout << "Stack: ";
    st.print();                                            // Expected -> Stack: 0 1 2 3 4 5 6 7

    for (int i = 0; i < 3; i++)                            // Is expected an overflow exception.
    {
        try
        {
            st.push(i);
        }
        catch (std::runtime_error e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        try
        {
            st.pop();
        }
        catch (std::runtime_error e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "Stack size: " << st.size() << std::endl; // Expected -> Stack size: 2
    std::cout << "Stack: ";
    st.print();                                            // Expected -> Stack: 0 1

    for (int i = 0; i < 3; i++)                            // Is expected an underflow exception.
    {
        try
        {
            st.pop();
        }
        catch (std::runtime_error e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
