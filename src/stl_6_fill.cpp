#include <iostream>
#include <deque>
#include <algorithm>
#include<iterator>
using namespace std;
int main(){
    std::deque<int> values (13); //Container has 13 elements
    int n{2};   // Initial element value
    const int step {7}; // Element value increment
    const size_t count{3};  // Number of elements with given value
    auto iter = std::begin(values);
    while(true)
    {
        auto to_end = std::distance(iter, std::end(values)); // Number of elements remaining
        if (to_end < count) //In case no. of elements not a multiple of count
        {
            std::fill (iter, iter + to_end, n); // Just fill remaining elements and end the loop
            break;
        }
        
        else
        {
            std::fill (iter, std::end (values), n); // Fill next count elements
        }
        iter = std::next(iter, count); // Increment iter
        n += step;
        std::copy(std::begin(values),std::end(values),std::ostream_iterator<int>{std::cout," "});
        std::cout << std::endl;
    }
    std::copy(std::begin(values),std::end(values),std::ostream_iterator<int>{std::cout," "});

}