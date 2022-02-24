#include <iostream>
#include <vector>
using namespace std;
template<typename T,typename N >
std::vector<T,N> print_vector(const std::vector<T,N> values){
    std::cout << "size:" << values.size() << std::endl;
    std::cout << "capacity:" << values.capacity() << std::endl;
    if(!values.empty()){            
            for(auto val=values.begin();val<values.end();val++){
                std::cout << *val << " ";
            }
            // for(int i=0;i<values.size();i++){
            //     std::cout << values[i] << " ";
            // }
            std::cout << "\n";
            
        }
    return values;
}
// 为什么可以重写构造、拷贝、移动函数
class testDeep{
public:
    testDeep(int num):num(num){
        std::cout << "构造" << std::endl;
    }
    testDeep(const testDeep& other):num(other.num){
        std::cout << "拷贝" << std::endl;
    }
    testDeep(const testDeep&& other):num(other.num){
        std::cout << "移动" << std::endl;
    }
private:
    int num;
    // string str;
};

int main(){
    // vector<char>value(3,'A');
    // std::cout << value[0] << std::endl;
//  test1
    vector<char>values;
    values.push_back('S');
    values.push_back('T');
    values.push_back('L');
    // std::cout << values.size() << std::endl;
    // std::cout << values.capacity() << std::endl;
    
    print_vector(values);
    values.insert(values.begin()+1,{'C','D'});//可以一次插入多个值
    values.emplace(values.begin()+3,'E');//一次只能插入一个值
    print_vector(values);
    values.pop_back();
    print_vector(values);
    values.emplace_back('A');
    print_vector(values);
    values.insert(values.begin(),'A');
    print_vector(values);

    values.erase(values.begin()+1);//擦除第二个元素
    print_vector(values);

    values.pop_back();//删除最后一个元素
    print_vector(values);

    values.pop_back();//删除最后一个元素
    print_vector(values);

    // values.erase(values.begin()+1);//
    values.clear();//删除所有
    print_vector(values);
    std::cout << "size:" << values.size() << std::endl;
    std::cout << "capacity:" << values.capacity() << std::endl;
    // std::cout << vaolues[0] << std::endl;
//  test2
// push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；
// 而 emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。
    std::vector<testDeep> Deepdemo1;
    std::cout << "emplace_back" <<std::endl;
    Deepdemo1.emplace_back(123);
    std::cout << "push_back" <<std::endl;
    std::vector<testDeep> Deepdemo2;
    Deepdemo2.push_back(456);

}
