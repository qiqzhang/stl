#include <iostream>                                      // For standard streams
#include <iterator>                                      // For iterators and begin() and end()
#include <string>                                        // For string class
#include <vector>                                        // For vector container
#include <algorithm>
#include <deque>
using std::string;
using namespace std;
int main(){
    std::deque<string> song{ "jingle", "bells", "jingle", "all", "the", "way"};
    song.resize(song.size()+2); // Add 2 elements
    // copy_backward() 算法会将原有的元素复制到向右的两个位置，保持前两个元素不变，
    std::copy_backward(std::begin(song), std::begin(song)+6, std::end(song));
    std::copy(std::begin(song), std::end(song), std::ostream_iterator <string> {std::cout, " "});
    std::cout << std::endl;
}