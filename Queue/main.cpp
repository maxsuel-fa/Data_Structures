/*
* @file main.cpp
* @brief Main function just to test the queue data structure.
* @author maxsuel-fa
*/
#include <iostream>
#include "Queue.hpp"

int main(void)
{
    Queue<int> q(10);

    for (int i = 0; i < q.capacity(); ++i)
    {
        try { q.enqueue(i); }
        catch (std::runtime_error e) { std::cerr << e.what() << std::endl; }
    }
    std::cout << "Queue: ";
    q.print();                                             // Expected -> Queue: 0 1 2 3 4 5 6 7 8 9

    try { q.enqueue(10); }                                 // Expected -> Overflow exception
    catch (std::runtime_error e) { std::cerr << e.what() << std::endl; }

    for (int i = 0; i < q.capacity(); ++i)                  
    {
        try 
        { 
            q.dequeue(); 
            std::cout << "Queue after the " << i + 1
                << "th dequeue operation: ";
            q.print();
        }
        catch (std::runtime_error e) { std::cerr << e.what() << std::endl; }
    }

    try { q.dequeue(); }                                   // Expected -> Underflow exception
    catch (std::runtime_error e) { std::cerr << e.what() << std::endl; }

    return 0;
}
