#include <iostream>                                      // For standard streams
#include <iterator>                                           // For string class
#include <vector>                                        // For vector container
#include <algorithm>                                     // For next_permutation()
#include <unordered_set>
using namespace std;
int main()
{
    std::vector<string> words {"one", "two", "two", "three", "two", "two", "two"};
    auto end_iter = std::unique(std::begin(words), std::end(words));
    std::copy(std::begin(words), std::end(words), std::ostream_iterator<string>{std::cout, " "});
    std::cout << std::endl;
    std::copy(std::begin(words), end_iter, std::ostream_iterator<string>{std::cout, " "});
    std::cout << std::endl;
}