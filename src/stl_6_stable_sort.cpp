#include<iostream>
#include<algorithm>
#include<vector>
bool mycomp(int i,int j){
    return (i<j);
}
class mycomp2{
public:
    bool operator()(int i,int j){
        return (i<j);
    }
};
//除了可以实现排序，还可以保证不改变相等元素的相对位置。
int main(){
    std::vector<int>myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };
    std::stable_sort(myvector.begin(),myvector.begin()+4);//(12 32 45 71) 26 80 53 33
    std::stable_sort(myvector.begin(),myvector.begin()+4,std::greater<int>());//(71 45 32 12) 26 80 53 33
    std::stable_sort(myvector.begin(),myvector.end(),mycomp);//12 26 32 33 45 53 71 80
    for(std::vector<int>::iterator it = myvector.begin();it!=myvector.end();++it){
        std::cout << *it << ' ';
    }
    return 0;
}