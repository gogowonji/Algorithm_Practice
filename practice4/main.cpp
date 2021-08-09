//
//  main.cpp
//  practice4
//
//  Created by 지원 on 2021/08/09.
//
#include <string>
#include <iostream>
#include <forward_list>
using namespace std;

struct citizen
{
    string name;
    int age;
};

ostream &operator<<(ostream &os, const citizen &c){
    return (os << "[" << c.name << ", " << c.age << "]");
}
int main() {
    
//    forward_list<int> fwd_list = {1,2,3};
//
//    fwd_list.push_front(0); //앞에 0 삽입
//
//    auto it = fwd_list.begin(); //시작 위치 받아오기 front x begin o
//
//    fwd_list.insert_after(it, 5); // 시작 위치에 5 삽입
//    fwd_list.insert_after(it, 6); // 시작 위치에 6 삽입
//
//    fwd_list.pop_front(); //시작 위치의 원소 삭제
//
//    fwd_list.erase_after(it); //시작 위치 다음 원소 삭제
//    fwd_list.erase_after(it, fwd_list.end()); // 시작 위치 다음 원소부터 끝 원소까지 삭제
    
//    forward_list<int> list1 = {23,0,1,-3,34,32};
//    list1.reverse(); //리스트의 원소들을 거꾸로
//    list1 = {0,1,0,1,-1,10,5,5,10,0};
//    list1.unique(); // 연달아 중복 되는 것 제거 (제거 x)
//
//    list1 = {0,1,0,1,-1,10,5,5,10,0};
//    list1.sort(); // 정렬후
//    list1.unique(); // 연달아 중복 되는 것 제거 (제거 o)

        
    forward_list<citizen> citizens = {
        {"kim, 22"}, {"Lee, 25"}, {"Park, 18"}, {"Jin, 17"}
    };
    auto citizens_copy = citizens;
    
    cout << "전체 시민들 : ";
    for(const auto &c : citizens)
        cout << c << " ";
    cout << endl;
    
    citizens.remove_if([]
                       (const citizen &c)
    {
        return (c.age < 19);
    });
    
    cout << "투표권이 있는 시민들 : ";
    for(const auto &c : citizens)
        cout << c << " ";
    cout << endl;
    
    citizens_copy.remove_if([]
                            (const citizen &c)
    {
        return (c.age != 18);
    });
    
    cout << "내년에 투표권이 생기는 시민들 : ";
    for(const auto &c : citizens_copy)
        cout << c << " ";
    cout << endl;

    
    
    return 0;
}
