#include <iostream>     // std::cout
#include <algorithm>    // std::search_n
#include <vector>   
#include <iterator> 
using namespace std;
int main(){
    std::vector<string> words { "one", "two", "three", "four", "five","six", "seven", "eight"};
    auto iter = std::rotate(std::begin(words), std::begin(words)+3, std::end(words));
    std::copy(std::begin(words), std::end(words),std::ostream_iterator<string> {std::cout, " "});
    std::cout << std::endl << "First element before rotation: " << *iter << std::endl;
}