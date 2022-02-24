#include <iostream>                                      // For standard streams
#include <iterator>                                      // For iterators and begin() and end()
#include <string>                                        // For string class
#include <vector>                                        // For vector container
#include <algorithm>                                     // For next_permutation()
using std::string;
int main(){
    std::vector<double> data1 {44.5, 22.0, 15.6, 1.5};
    std::vector<double> data3 {1.5, 44.5, 15.6, 22.0, 88.0, 999.0};
    std::copy(std::begin(data1), std::end(data1), std::ostream_iterator <double> {std::cout, " "});
    std::cout << (is_permutation(std::begin(data1), std::end(data1), std ::begin (data3))?"is" :"is not")<< " a permutation of ";
    std::copy(std::begin(data3), std::end(data3), std::ostream_iterator <double> {std::cout, " "});
    std::cout << std::endl;
}