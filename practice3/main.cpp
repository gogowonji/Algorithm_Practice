//
//  main.cpp
//  practice3
//
//  Created by 지원 on 2021/07/24.
//

#include <iostream>
#include <vector>
using namespace std;


int main() {
    // insert code here...
    
    //vector 초기화
    vector<int> vec0; //크기0, 용량은 0 또는 작은 양수일 수 있음
    vector<int> vec1 = {1,2,3,4,5}; //크기 제공하지 않아도 됨
    vector<int> vec2(10);
    vector<int> vec3(10,5); //크기 10, 모든 원소 5로 초기화
    
    //vector 원소 추가
    vector<int> vec; //{ }
    //push_back O(1)이어서 짱 빠름
    vec.push_back(1); //{1}
    
    //*******범위기반반복문******** 익혀두기
    for(auto i : vec)
        cout << i << " ";
    cout << endl;
    
    vec.push_back(2); //{1,2}
    
    vec.insert(vec.begin(),0);//{0,1,2}
    
    vec.insert(find(vec.begin(), vec.end(), 1), 4); //1앞에 4추가 {0,4,1,2}
    for(auto i : vec)
        cout << i << " ";
    cout << endl;
    
    //emplace_back() or emplace 새로운 원소가 추가될 위치에서 해당 원소를 생성하는 방식으로 최적화 가능
    
    vec.clear();
    //vector 원소 제거
    vec = {0,1,2,3,4,5,6,7,8,9};
    for(auto i : vec)
        cout << i << " ";
    cout << endl;

    vec.pop_back(); // {0,1,2,3,4,5,6,7,8}
    
    vec.erase(vec.begin()); //{1,2,3,4,5,6,7,8}
    
    vec.erase(vec.begin()+1, vec.begin()+4); //{1,5,6,7,8}
    for(auto i : vec)
        cout << i << " ";
    cout << endl;
    
        
    
    return 0;
}
