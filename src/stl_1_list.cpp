#include <iostream>
#include <list>
#include <array>
using namespace std;
bool demo(double first, double second)
{
    return (int(first) == int(second));
}
int main()
{
//  插入
    std::list<double>values;
    values.push_back(3.1);
    values.push_back(3.6);
    values.push_back(2.1);
    cout << values.size() << endl;
    values.sort();
    // for(std::list<double>::iterator it=values.begin();it!=values.end();++it){
    //     cout << *it << " ";
    // }
    for(auto it=values.begin();it!=values.end();++it){
        cout << *it << " ";
    }
    cout << endl;
//  test2 list逆序
    //创建 list 容器
    std::list<char> values1{'h','t','t','p'};
    //使用begin()/end()迭代器函数对输出list容器中的元素
    for (std::list<char>::iterator it = values1.begin(); it != values1.end(); ++it) {
        std::cout << *it;
    }
    cout << endl;
    // 使用 rbegin()/rend()迭代器函数输出 lsit 容器中的元素
    for(std::list<char>::reverse_iterator it = values1.rbegin();it!=values1.rend();++it){
        std::cout << *it;
    }
    std::cout << std::endl;

//  test3 list插入会有遗漏
    //创建 begin 和 end 迭代器
    std::list<char>::iterator begin = values1.begin();
    std::list<char>::iterator end = values1.end();
    //头部和尾部插入字符 '1'
    values1.insert(begin, '1');
    values1.insert(end, '1');
    while (begin != end)
    {
        std::cout << *begin;
        ++begin;
    }
    std::cout<<std::endl;
//  test4 插入
    std::list<int> values3{1,2,3};
    values3.push_front(0);//{0,1,2,3}
    values3.push_back(4); //{0,1,2,3,4}
    values3.emplace_front(-1);//{-1,0,1,2,3,4}
    values3.emplace_back(5);  //{-1,0,1,2,3,4,5}
   
    //emplace(pos,value),其中 pos 表示指明位置的迭代器，value为要插入的元素值
    values3.emplace(values3.end(), 6);//{-1,0,1,2,3,4,5,6}
    for (auto p = values3.begin(); p != values3.end(); ++p) {
        cout << *p << " ";
    }
    std::cout<<std::endl;
//  test5 插入
    std::list<int> values4{ 1,2 };
    //第一种格式用法
    values4.insert(values4.begin() , 3);//{3,1,2}
    //第二种格式用法
    values4.insert(values4.end(), 2, 5);//{3,1,2,5,5}
    //第三种格式用法
    std::array<int, 3>test1{ 7,8,9 };
    values4.insert(values4.end(), test1.begin(), test1.end());//{3,1,2,5,5,7,8,9}
    //第四种格式用法
    values4.insert(values4.end(), { 10,11 });//{3,1,2,5,5,7,8,9,10,11}
    for (auto p = values4.begin(); p != values4.end(); ++p)
    {
        cout << *p << " ";
    }
    std::cout << std::endl;
//  test6 当使用 splice() 成员方法将 x 容器中的元素添加到当前容器的同时，该元素会从 x 容器中删除。
    //创建并初始化 2 个 list 容器
    list<int> mylist1{ 1,2,3,4 }, mylist2{10,20,30};
    list<int>::iterator it = ++mylist1.begin(); //指向 mylist1 容器中的元素 2
   
    //调用第一种语法格式
    mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                 // mylist2:
                                 // it 迭代器仍然指向元素 2，只不过容器变为了 mylist1
    //调用第二种语法格式，将 it 指向的元素 2 移动到 mylist2.begin() 位置处
    mylist2.splice(mylist2.begin(), mylist1, it);   // mylist1: 1 10 20 30 3 4
                                                    // mylist2: 2
                                                    // it 仍然指向元素 2
   
    //调用第三种语法格式，将 [mylist1.begin(),mylist1.end())范围内的元素移动到 mylist2.begin() 位置处                  
    mylist2.splice(mylist2.begin(), mylist1, mylist1.begin(), mylist1.end());//mylist1:
                                                                             //mylist2:1 10 20 30 3 4 2
   
    cout << "mylist1 包含 " << mylist1.size() << "个元素" << endl;
    cout << "mylist2 包含 " << mylist2.size() << "个元素" << endl;
    //输出 mylist2 容器中存储的数据
    cout << "mylist2:";
    for (auto iter = mylist2.begin(); iter != mylist2.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
//  test7 删除元素
    list<int>values7{ 1,2,3,4 };
    //删除当前容器中首个元素
    values7.pop_front();//{2,3,4}
    //删除当前容器最后一个元素
    values7.pop_back();//{2,3}
    //清空容器，删除容器中所有的元素
    values7.clear(); //{}
    for (auto begin = values7.begin(); begin != values7.end(); ++begin)
    {
        cout << *begin << " ";
    }
    cout << endl;

//  test8 删除元素
    list<int>values8{ 1,2,3,4,5 };
    //指定删除区域的左边界
    auto first = values8.begin();
    ++first;//指向元素 2
    //指向删除区域的右边界
    auto last = values8.end();
    --last;//指向元素 5
    //删除 2、3 和 4
    values8.erase(first, last);
    for (auto begin = values8.begin(); begin != values8.end(); ++begin)
    {
        cout << *begin << " ";
    }
    cout << endl;
//  test9 删除元素
    list<char>values9{'a','b','c','d'};
    values9.remove('c');
    for (auto begin = values9.begin(); begin != values9.end(); ++begin)
    {
        cout << *begin << " ";
    }
    cout << endl;
//  test10 删除相邻重复元素
    list<double> mylist{ 1,1.2,1.2,3,4,4.5,4.6};
    //删除相邻重复的元素，仅保留一份
    mylist.unique();//{1, 1.2, 3, 4, 4.5, 4.6}
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << *it << ' ';
    cout << endl;
    //demo 为二元谓词函数，是我们自定义的去重规则
    mylist.unique(demo);
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << *it << ' ';
    cout << endl;


}