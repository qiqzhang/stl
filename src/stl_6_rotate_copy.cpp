#include <iostream>     // std::cout
#include <algorithm>    // std::search_n
#include <vector>   
#include <iterator> 
using namespace std;
int main(){
    std::vector<string> words {"one", "two", "three", "four", "five","six", "seven", "eight", "nine", "ten"};
    auto start = std::find(std::begin(words), std::end(words), "two");
    auto end_iter = std::find (std::begin(words) , std::end (words) ,"eight");
    std::vector<string> words_copy;
    std::rotate_copy(start, std::find(std::begin(words), std::end(words),"five") , end_iter, std::back_inserter (words_copy));
    std::copy(std::begin(words_copy), std::end(words_copy),std::ostream_iterator<string> {std::cout, " "});
    std::cout << std::endl;
}