#include<iostream>
#include <algorithm>
// #include <>
using namespace std;
int main(){

    // string chars (30, ' ');// 30 space characters
    // char ch {'a'};
    // int incr {};
    // std::generate (std::begin (chars) , std::end (chars), [ch, &incr]
    // {
    //     incr += 3;
    //     return ch + (incr % 26);
    // });
    // std::cout << chars << std::endl;
    // // chars is: dgjmpsvybehknqtwzcfiloruxadgjm



    string chars (30,' '); // 30 space characters
    char ch {'a'};
    int incr {};
    std::generate_n(std::begin(chars), chars.size()/2,[ch, &incr]
    {
        incr += 3;
        return ch + (incr % 26);
    });
    std::cout << chars << std::endl;

}