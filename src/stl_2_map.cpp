#include <iostream>
#include <map>      // map
#include <string>       // string
using namespace std;

int main() {
//  test1排序
    //创建空 map 容器，默认根据个键值对中键的值，对键值对做降序排序
    std::map<std::string, std::string, std::greater<std::string>>myMap;
    //创建空 map 容器，默认根据个键值对中键的值，对键值对做升序排序
    // std::map<std::string, std::string, std::less<std::string>>myMap;
    //调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
    myMap.emplace("C语言教程","http1");
    myMap.emplace("Python教程", "http2");
    myMap.emplace("STL教程", "http3");
    myMap.emplace("Java教程", "http4");
    //输出当前 myMap 容器存储键值对的个数
    cout << "myMap size==" << myMap.size() << endl;
    //判断当前 myMap 容器是否为空
    if (!myMap.empty()) {
        //借助 myMap 容器迭代器，将该容器的键值对逐个输出
        for (auto i = myMap.begin(); i != myMap.end(); ++i) {
            cout << i->first << " " << i->second << endl;
        }
    }
//  test22遍历查找
    cout << "test22" <<endl;
     //创建并初始化 map 容器
    std::map<std::string, std::string>myMap1{ {"STL教程","http1"},{"C语言教程","http2"} };
    //调用 begin()/end() 组合，遍历 map 容器
    for (auto iter = myMap1.begin(); iter != myMap1.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
//  test23 find函数
    cout << "test23" <<endl;
    //查找键为 "Java教程" 的键值对
    auto iter = myMap.find("Java教程");
    //从 iter 开始，遍历 map 容器
    for (; iter != myMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
//  test24 lower_bound 与 upper_bound  函数
    cout << "test24" <<endl;
    //找到第一个键的值不小于 "Java教程" 的键值对
    iter = myMap.lower_bound("Java教程");
    cout << "lower：" << iter->first << " " << iter->second << endl;
   
    //找到第一个键的值大于 "Java教程" 的键值对
    iter = myMap.upper_bound("Java教程");
    cout <<"upper：" << iter->first << " " << iter->second << endl;

//  test25 key查询
    cout << "test251" <<endl;
    pair<std::map<string,string>::iterator, std::map<string,string>::iterator>myPair = myMap.equal_range("C语言教程");
    for(auto iter=myPair.first;iter!=myPair.second;++iter){
        cout << iter->first << " " << iter->second << endl;
    }
    cout << "test252" <<endl;
    map< std::string, std::string >::iterator myIter = myMap.find("C语言教程");
    cout << myIter->first << " " << myIter->second << endl;
    cout << "test253" <<endl;

    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        //调用 string 类的 compare() 方法，找到一个键和指定字符串相同的键值对
        if (!iter->first.compare("C语言教程")) {
            cout << iter->first << " " << iter->second << endl;
        }
    }
//  test3  4种insert()插入数据
    cout << "test31" << endl;
    // std::map<string, string> mymap
    //向 map 容器添加新键值对
    myMap["Python教程"] = "http2";
    //修改 map 容器已存储键值对中，指定键对应的值
    myMap["STL教程"] = "http33";
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
// test3 1) 无需指定插入位置，直接将键值对添加到 map 容器中。insert() 方法的语法格式有以下 2 种：
    cout << "test32" << endl;
    // //1、引用传递一个键值对
    // pair<iterator,bool> insert (const value_type& val);
    // //2、以右值引用的方式传递键值对
    // template <class P>
    //     pair<iterator,bool> insert (P&& val);
        //创建一个空 map 容器
    std::map<string, string> mymap;
   
    //创建一个真实存在的键值对变量
    std::pair<string, string> STL = { "STL教程","http1" };
   
    //创建一个接收 insert() 方法返回值的 pair 对象
    std::pair<std::map<string, string>::iterator, bool> ret;
   
    //插入 STL，由于 STL 并不是临时变量，因此会以第一种方式传参
    ret = mymap.insert(STL);
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //以右值引用的方式传递临时的键值对变量
    ret = mymap.insert({ "C语言教程","http2" });
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //插入失败样例
    ret = mymap.insert({ "STL教程","http3" });
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;

    cout << "test33" << endl;
//  3) insert() 方法还支持向当前 map 容器中插入其它 map 容器指定区域内的所有键值对，   
//     template <class InputIterator>
//   void insert (InputIterator first, InputIterator last);
    mymap.insert({{"STL教程","http2"},
            {"C语言教程","http3"},
            {"Java教程","http4"} });
    //创建一个空 map 容器
    std::map<std::string, std::string>copymap;
    //指定插入区域
    std::map<string, string>::iterator first = ++mymap.begin();
    std::map<string, string>::iterator last = mymap.end();
    //将<first,last>区域内的键值对插入到 copymap 中
    copymap.insert(first, last);
    //遍历输出 copymap 容器中的键值对
    for (auto iter = copymap.begin(); iter != copymap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }


//  4) 除了以上一种格式外，insert() 方法还允许一次向 map 容器中插入多个键值对，其语法格式为：
//  void insert ({val1, val2, ...});
//  其中，vali 都表示的是键值对变量。上述已用


//  test4 map emplace()和emplace_hint()
    cout << "test41" << endl;
//     template <class... Args>
//   pair<iterator,bool> emplace (Args&&... args);
    // std::pair<std::map<string, string>::iterator, bool> ret;
    //插入键值对
    ret = mymap.emplace("STL教程", "http1");
    cout << "1、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //插入新键值对
    ret = mymap.emplace("C语言教程", "http2");
    cout << "2、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //失败插入的样例
    ret = mymap.emplace("STL教程", "http0");
    cout << "3、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
// emplace_hint() 方法的功能和 emplace() 类似，其语法格式如下：
// template <class... Args>
//   iterator emplace_hint (const_iterator position, Args&&... args);
    // //创建并初始化 map 容器
    // std::map<string, string>mymap;
    //指定在 map 容器插入键值对

//     该方法不仅要传入创建键值对所需要的数据，还需要传入一个迭代器作为第一个参数，指明要插入的位置（新键值对键会插入到该迭代器指向的键值对的前面）；
// 该方法的返回值是一个迭代器，而不再是 pair 对象。当成功插入新键值对时，返回的迭代器指向新插入的键值对；反之，如果插入失败，则表明 map 容器中存有相同键的键值对，返回的迭代器就指向这个键值对。
    cout << "test42" << endl;
    map<string, string>::iterator iter1 = mymap.emplace_hint(mymap.begin(),"STL教程11", "http11");
    cout << iter1->first << " " << iter1->second << endl;
    iter1 = mymap.emplace_hint(mymap.begin(), "C语言教程", "http22");
    cout << iter1->first << " " << iter1->second << endl;
    //插入失败样例
    iter1 = mymap.emplace_hint(mymap.begin(), "STL教程33", "http");
    cout << iter1->first << " " << iter1->second << endl;





    return 0;
}