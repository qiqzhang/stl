// Using the equal() algorithm
#include <iostream>                                      // For standard streams
#include <vector>                                        // For vector container
#include <algorithm>                                     // For equal() algorithm
#include <iterator>                                      // For stream iterators
#include <string>                                        // For string class
using std::string;

int main()
{
    std::vector<string> words1 {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<string> words2 {"two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    auto iter1 = std::begin(words1);
    auto end_iter1 = std::end(words1);
    auto iter2 = std::begin(words2);
    auto end_iter2 = std::end(words2);

    std::cout << "Container - words1:";
    std::copy(iter1, end_iter1, std::ostream_iterator<string>{std::cout, " "});
    std::cout << "\nContainer - words2:";
    std::copy(iter2, end_iter2, std::ostream_iterator<string>{std::cout, " "});
    std::cout << std::endl;

    std::cout << "\n1. Compare from words1[1] to end with words2:";
    std::cout << std::boolalpha << std::equal(iter1 + 1, end_iter1, iter2) << std::endl;

    std::cout << "2. Compare from words2[0] to second-to-last with words1:";
    std::cout << std::boolalpha << std::equal(iter2, end_iter2 - 1, iter1) << std::endl;

    std::cout << "3. Compare from words1[1] to words1[5] with words2:";
    std::cout << std::boolalpha << std::equal(iter1 + 1, iter1 + 6, iter2) << std::endl;
   
    std::cout << "4. Compare first 6 from words1 with first 6 in words2:";
    std::cout << std::boolalpha << std::equal(iter1, iter1 + 6, iter2, iter2 + 6) << std::endl;

    std::cout << "5. Compare all words1 with words2:";
    std::cout << std::boolalpha << std::equal(iter1, end_iter1, iter2) << std::endl;

    std::cout << "6. Compare all of words1 with all of words2:";
    std::cout << std::boolalpha << std::equal(iter1, end_iter1, iter2, end_iter2) << std::endl;

    std::cout << "7. Compare from words1[1] to end with words2 from first to second-to-last:";
    std::cout << std::boolalpha << std::equal(iter1 + 1, end_iter1, iter2, end_iter2 - 1) << std::endl;
}
// 第 1 条语句的输出为 true，因为 words1 的第二个元素到最后一个元素都从 words2 的第一个元素开始匹配。第二个序列的元素个数比第一个序列的元素个数多 1，但 第一个序列的元素个数决定了比较多少个对应的元素。
// 第 2 条语句的输出为 false，因为有直接的不匹配；words2 和 words1 的第一个元素不同。
// 第 3 条语句的输出为 true，因为 word1 中从第二个元素开始的 5 个元素和 words2 的前五个元素相等。
// 在第 4 条语句中，words2 的元素序列是由开始和结束迭代器指定的。序列长度相同，但它们的第一个元素不同，所以结果为 false。
// 在第 5 条语句中，两个序列的第一个元素直接就不匹配，所以结果为 false。
// 第 6 条语句的输出为 false，因为序列是不同的。这条语句不同于前面的 equal() 调用，因为指定了第二个序列的结束迭代器。
// 第 7 条语句会从 words1 的第二个元素开始，与 word2 从第一个元素开始比较相同个数的元素，所以输出为 true。