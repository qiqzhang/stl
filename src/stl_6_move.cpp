#include <iostream>     // std::cout
#include <algorithm>    // std::search_n
#include <vector>   
#include <iterator> 
#include<deque>
using namespace std;
int main(){
    std::vector<int> srce {1, 2, 3, 4};
    std::deque<int> dest {5, 6, 7, 8};
    std::move(std::begin(srce), std::end(srce), std::back_inserter(dest));
    for (auto iter = dest.begin(); iter != dest.end(); ++iter) {
        cout << *iter << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> data {1, 2, 3, 4, 5, 6, 7, 8};
    std::move(std::begin(data) + 2, std::end(data), std::begin(data));
    std::copy(std::begin (data), std::end(data), std::ostream_iterator<int> {std::cout, " "});
    std::cout << std::endl;

    data.erase(std::end(data) - 2, std::end(data)); // Erase moved elements
    std::copy(std::begin (data), std::end(data), std::ostream_iterator<int> {std::cout, " "});
    std::cout << std::endl;
    // 3, 4, 5, 6, 7, 8
}