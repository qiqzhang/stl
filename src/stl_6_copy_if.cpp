#include <iostream>                                      // For standard streams
#include <iterator>                                      // For iterators and begin() and end()
#include <string>                                        // For string class
#include <vector>                                        // For vector container
#include <algorithm>                                     // For next_permutation()
#include <unordered_set>
using std::string;
using namespace std;
int main(){
    std::vector<string> names { "Al", "Beth", "Carol", "Dan", "Eve","Fred", "George", "Harry", "Iain", "Joe"};
    size_t max_length{4};
    std::copy_if(std::begin(names), std::end(names), std::ostream_iterator< string> {std::cout," "}, [max_length](const string& s) { return s.length() <= max_length; });
    std::cout << std::endl;
}