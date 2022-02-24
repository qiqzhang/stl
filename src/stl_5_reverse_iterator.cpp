#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main(){
    std::vector<int> myvector{1,2,3,4,5};
    // std::reverse_iterator<std::vector<int>::iterator>my_reiter(myvector.rbegin());//指向5
    // cout << *my_reiter << endl;//5
    // cout << *(my_reiter+3) << endl;//2
    // cout << *(++my_reiter) << endl;//4
    // cout << my_reiter[1] << endl;//0

    std::reverse_iterator<std::vector<int>::iterator>begin(myvector.begin());//指向5
    std::reverse_iterator<std::vector<int>::iterator>end(myvector.end());//指向5
    for(auto iter=begin.base();iter!=end.base();++iter){
        std::cout << *iter << ' ';
    }
    return 0;
}