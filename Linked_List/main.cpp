/* @file main.hpp
 * @brief Main function to teste the List data structure
 * @author maxsuel-fa
 */
#include "List.hpp"

int main(void)
{
    List <int> list;

    for (int i = 0; i < 5; ++i)
        list.push_front(i);
    list.print();                      // Expected: 4 3 2 1 0

    for (int i = 5; i < 10; ++i)
        list.push_back(i);
    list.print();                      // Expected: 4 3 2 1 0 5 6 7 8 9

    list.pop_front();
    list.pop_front();
    list.pop_back();
    list.pop_back();
    list.print();                      // Expected: 2 1 0 5 6 7
    
    list.search(5)->data *= (-1);      // Search for the value in the list
    list.search(7)->data *= (-1);      // if the value is found, multiplies
    list.search(10)->data *= (-1);     // it by -1, otherwise do nothing.
    
    list.print();                      // Expected: 2 1 0 -5 6 -7

    return 0;
}
