/*
* @file main.cpp
* @brief Main function just to test the stack data structure.
* @author maxsuel-fa
*/
#include <iostream>
#include "Stack.hpp"

int main(void)
{
    Stack<int> st(10);

    try { std::cout << st.top() << std::endl; }            // Expected -> Underflow exception
    catch (std::runtime_error e) { std::cerr << e.what() << std::endl; }

    for (int i = 0; i < st.capacity(); ++i)
    {
        try { st.push(i); }
        catch (std::runtime_error e) { std::cerr << e.what() << std::endl; }
    }
    std::cout << "Stack size: " << st.size() << std::endl; // Expected -> Stack size: 10
    std::cout << "Stack: ";
    st.print();                                            // Expected -> Stack: 0 1 2 3 4 5 6 7 8 9

    try { st.push(10); }                                   // Expected -> Overflow exception
    catch (std::runtime_error e) { std::cerr << e.what() << std::endl; }

    std::cout << "Top: "<< st.top() << std::endl;                    // Expected -> 9

    for (int i = 0; i < st.capacity(); ++i)
    {
        try { st.pop(); }
        catch (std::runtime_error e) { std::cerr << e.what() << std::endl; }
    }
    std::cout << "Stack size: " << st.size() << std::endl; // Expected -> Stack size: 0
                                                           
    try { st.pop(); }                                      // Expected -> Underflow exception
    catch (std::runtime_error e) { std::cerr << e.what() << std::endl; }

    return 0;
}
