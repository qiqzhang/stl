// lexicographical_compare()算法可以比较由开始和结束迭代器定义的两个序列。
// 它的前两个参数定义了第一个序列，第 3 和第 4 个参数分别是第二个序列的开始和结束迭代器。
// 默认用 < 运算符来比较元素，但在需要时，也可以提供一个实现小于比较的函数对象作为可选的第 5 个参数。
// 如果第一个序列的字典序小于第二个，这个算法会返回 true，否则返回 false。所以，返回 false 表明第一个序列大于或等于第二个序列。

#include <iostream>                                      // For standard streams
#include <vector>                                        // For vector container
#include <algorithm>                                     // For equal() algorithm
#include <string>                                        // For string class
#include <iterator>                                      // For stream iterators
using std::string;
int main()
{
    std::vector<string> phrase1 {"the", "tigers", "of", "wrath"};
    std::vector<string> phrase2 {"the", "horses", "of", "instruction"};
    auto less = std::lexicographical_compare (std::begin (phrase1), std::end (phrase1),
    std::begin(phrase2), std::end(phrase2)); std::copy(std::begin(phrase1), std::end(phrase1), std::ostream_iterator<string>{std::cout, " "});
    std::cout << (less ? "are":"are not") << " less than ";
    std::copy(std::begin(phrase2), std::end(phrase2), std::ostream_iterator <string>{std::cout, " "});
    std::cout << std::endl;
}