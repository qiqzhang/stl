#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <list>         // std::list
using namespace std;
// distance() 函数用于计算两个迭代器表示的范围内包含元素的个数
int main() {
    //创建一个空 list 容器
    list<int> mylist;
    //向空 list 容器中添加元素 0~9
    for (int i = 0; i < 10; i++) {
        mylist.push_back(i);
    }
    //指定 2 个双向迭代器，用于执行某个区间
    list<int>::iterator first = mylist.begin();//指向元素 0
    list<int>::iterator last = mylist.end();//指向元素 9 之后的位置
    //获取 [first,last) 范围内包含元素的个数
    cout << "distance() = " << distance(first, last);
    return 0;
}
