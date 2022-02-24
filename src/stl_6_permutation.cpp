// Finding rearrangements of the letters in a word
#include <iostream>                                      // For standard streams
#include <iterator>                                      // For iterators and begin() and end()
#include <string>                                        // For string class
#include <vector>                                        // For vector container
#include <algorithm>                                     // For next_permutation()
using std::string;
// next_permutation() 是按照字典升序的方式生成的排列。当我们想以降序的方式生成排列时，可以使用 prev_permutation()。
// prev_permutation 和 next_permutation() 一样有两个版本，默认使用 < 来比较元素。
// 因为排列是以降序的方式生成的，所以算法大多数时候会返回 true。当生成最大排列时，返回 false。例如：
int main()
{
    std::vector<string> words;
    string word;
    
    while(true)
    {
        std::cout << "\nEnter a word, or Ctrl+z to end: ";
        if((std::cin >> word).eof()) break;
        string word_copy {word};
        do
        {
            words.push_back(word);
            std::next_permutation(std::begin(word), std::end(word));
        } while(word != word_copy);
        size_t count{}, max{8};
        for(const auto& wrd : words)
            std::cout << wrd << ((++count % max == 0) ? '\n' : ' ');//输出每8个一换行
        std::cout << std::endl;
        words.clear();          // Remove previous permutations
        // 2.prev_permutation降序
        std::vector<double> data {44.5, 22.0, 15.6, 1.5};
        do {
            std::copy(std::begin(data), std::end(data), std::ostream_iterator<double> {std::cout, " "});
            std::cout << std::endl;
        } while(std::prev_permutation(std::begin(data), std::end(data)));//结束了就false,一般返回true
    }
}