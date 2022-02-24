#include <iostream>                                      // For standard streams
#include <iterator>                                      // For iterators and begin() and end()
#include <string>                                        // For string class
#include <vector>                                        // For vector container
#include <algorithm>                                     // For next_permutation()
#include <unordered_set>
using std::string;
using namespace std;
int main(){
    std::vector<string> names {"A1","Beth", "Carol", "Dan", "Eve","Fred","George" ,"Harry", "Iain", "Joe"};
    std::unordered_set<string> more_names {"Janet", "John"};
    std::copy_n(std::rbegin(names)+1, 3, std::inserter(more_names, std::begin(more_names)));
    // std::copy_n(std::begin(more_names), more_names.size()-1,std::ostream_iterator<string> {std::cout, " "});
}