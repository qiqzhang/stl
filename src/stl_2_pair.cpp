#include <iostream>
#include <utility>      // pair
#include <string>       // string
using namespace std;
int main() {
//  test1 3+2种构造函数，2种为引入右值引用带来的构造函数
    // 调用构造函数 1，也就是默认构造函数
    pair <string, double> pair1;
    // 调用第 2 种构造函数
    pair <string, string> pair2("STL教程","http");  
    // 调用拷贝构造函数
    pair <string, string> pair3(pair2);
    //调用移动构造函数
    pair <string, string> pair4(make_pair("C++教程", "http"));
    // 调用第 5 种构造函数
    pair <string, string> pair5(string("Python教程"), string("http"));  
   
    cout << "pair1: " << pair1.first << " " << pair1.second << endl;
    cout << "pair2: "<< pair2.first << " " << pair2.second << endl;
    cout << "pair3: " << pair3.first << " " << pair3.second << endl;
    cout << "pair4: " << pair4.first << " " << pair4.second << endl;
    cout << "pair5: " << pair5.first << " " << pair5.second << endl;

//  test2 pair判断是否相等，key与value必须全部相等
    pair <string, int> pair11("STL教程", 20);
    pair <string, int> pair12("C++教程", 20);
    pair <string, int> pair13("C++教程", 30);
    //pair11和pair12的key不同，value相同
    if (pair11 != pair12) {
        cout << "pair11 != pair12" << endl;
    }
    //pair12和pair13的key相同，value不同
    if (pair12 != pair13) {
        cout << "pair12 != pair13" << endl;
    }
//  test3 
    pair <string, int> pair21("pair21", 10);                   
    pair <string, int> pair22("pair22", 20);
    //交换 pair1 和 pair2 的键值对
    pair21.swap(pair22);
    cout << "pair21: " << pair21.first << " " << pair21.second << endl;
    cout << "pair22: " << pair22.first << " " << pair22.second << endl;

    return 0;
}