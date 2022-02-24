#include<iostream>
#include<iterator>
#include<vector>
#include<forward_list>
using namespace std;

int main(){
    // 1.容器的的尾部插入元素
    // std::vector<int>foo;
    // std::back_insert_iterator<std::vector<int>> back_it(foo);
    // back_it=5;
    // back_it=4;
    // back_it=3;
    // back_it=6;
    // for(std::vector<int>::iterator it=foo.begin();it!=foo.end();++it){
    //     std::cout << *it << ' ';
    // }
    // 2.容器的头部插入元素
    // std::forward_list<int> foo;
    // std::front_insert_iterator<std::forward_list<int>> front_it = front_inserter(foo);
    // front_it=5;
    // front_it=4;
    // front_it=3;
    // front_it=6;
    // for(std::forward_list<int>::iterator it=foo.begin();it!=foo.end();++it)
    //     cout << *it << ' ';
    // 3.容器的任意位置插入元素
    std::list<int> foo(2,5);
    std::list<int>::iterator it = ++foo.begin();
    std::insert_iterator<std::list<int>>insert_it=inserter(foo,it);
    insert_it=1;
    insert_it=2;
    insert_it=3;
    insert_it=4;
    for(std::list<int>::iterator it=foo.begin();it!=foo.end();++it){
        std::cout << *it << ' ';
    }
    return 0;
}