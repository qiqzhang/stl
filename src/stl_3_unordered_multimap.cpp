#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    std::unordered_multimap<std::string,std::string>myummap;
    myummap.emplace("ruby","https_ruby");
    myummap.emplace("go","https_go");
    myummap.emplace("java","https_java");
    cout << "myummap size = " << myummap.size() << endl;
    for(auto iter=myummap.begin();iter!=myummap.end();++iter){
        cout << iter->first << " " << iter->second << endl;
    }
 
}