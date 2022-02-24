#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include <iterator>                                      // For iterators and begin() and end()

using namespace std;
int main()
{
    std::deque<int> data {10, -5, 12, -6, 10, 8, -7, 10, 11};
    std::replace(std::begin(data), std::end(data), 10, 99);
    // Result: 99 -5 12 -6 99 8 -7 99 11
    std::copy(std::begin(data), std::end(data), std::ostream_iterator <int> {std::cout, " "});
    std::cout<< std::endl;


    string password { "This is a good choice !"};
    std::replace_if(std::begin(password), std::end(password),[](char ch){return std::isspace(ch);}, '_');
    //Result:This_is_a_good_choice!
    std::copy(std::begin(password), std::end(password), std::ostream_iterator <char> {std::cout, " "});
    std::cout<< std::endl;


    std::vector<string> words { "one","none", "two", "three", "none", "four"};
    std::vector<string> new_words;
    std::replace_copy (std::begin (words), std::end(words), std::back_inserter (new_words), string{"none"}, string{"0"});
    // Result:"one", "0", "two","three","0","four"
    std::copy(std::begin(words),std::end(words),std::ostream_iterator<string>{std::cout," "});
    std::cout<< std::endl;

    data={10, -5, 12, -6, 10, 8, -7, 10,11}; 
    std::vector<int> data_copy;
    std::replace_copy_if(std::begin(data), std::end(data),std::back_inserter(data_copy),[](int value) {return value == 10;}, 99);
    // Result:99 -5 12 -6 99 8 -7 99 11
    std::copy(std::begin(data_copy),std::end(data_copy),std::ostream_iterator<int>{std::cout," "});
    std::cout<< std::endl;
}