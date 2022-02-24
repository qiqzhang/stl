#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int main(){
    std::unordered_set<std::string>uset;
    uset.emplace("go");
    uset.emplace("ruby");
    uset.emplace("java");
    cout << "uset size = " << uset.size() << endl;
    for(auto iter=uset.begin();iter!=uset.end();++iter){
        cout << *iter << endl;
    }
}