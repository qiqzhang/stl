#include <iostream>
#include <map>  //map

using namespace std;   
// 和 map 容器的区别在于，multimap 容器中可以同时存储多（≥2）个键相同的键值对。
// template < class Key,                                   // 指定键（key）的类型
//            class T,                                     // 指定值（value）的类型
//            class Compare = less<Key>,                   // 指定排序规则
//            class Alloc = allocator<pair<const Key,T> >  // 指定分配器对象的类型
//            > class multimap;
int main()
{
    //创建并初始化 multimap 容器
    multimap<char, int>mymultimap{ {'a',10},{'b',20},{'b',15}, {'c',30} };
    //输出 mymultimap 容器存储键值对的数量
    cout << mymultimap.size() << endl;
    //输出 mymultimap 容器中存储键为 'b' 的键值对的数量
    cout << mymultimap.count('b') << endl;

    for (auto iter = mymultimap.begin(); iter != mymultimap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}