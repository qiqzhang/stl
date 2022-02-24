#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> values{1,2,3,4,5};
    // std::list<int>::iterator begin = --values.end();
    // std::list<int>::iterator end = --values.begin();
    // while(begin!=end){
    //     cout << *begin << " ";
    //     begin--;
    // }
    std::reverse_iterator<std::list<int>::iterator> begin = values.rbegin();
    std::reverse_iterator<std::list<int>::iterator> end = values.rend();
    while (begin!=end)
    {
        cout << *begin << " ";
        begin++;
    }
    
}