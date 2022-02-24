#include <iostream>     // std::cout
#include <iterator>     // std::advance
#include <forward_list>
#include <vector>
using namespace std;
int main() {
    // 1.
    // //创建一个 forward_list 容器
    // forward_list<int> mylist{1,2,3,4};
    // //it为前向迭代器，其指向 mylist 容器中第一个元素
    // forward_list<int>::iterator it = mylist.begin();
    // //借助 advance() 函数将 it 迭代器前进 2 个位置
    // advance(it, 2);
    // cout << "*it = " << *it;
    // 2.
    //创建一个 vector 容器
    vector<int> myvector{1,2,3,4,5,6};
    //it为随机访问迭代器，其指向 myvector 容器中第一个元素
    vector<int>::iterator it = myvector.begin();
    //借助 advance() 函数将 it 迭代器前进 2 个位置
    advance(it, 2);
    cout << "1、*it = " << *it << endl;
    //继续使用it，其指向 myvector 容器中最后一个元素之后的位置
    it = myvector.end();
    //借助 advance() 函数将 it 迭代器后退 3 个位置
    advance(it, -3);
    cout << "2、*it = " << *it;
    return 0;
}