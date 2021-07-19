//
//  main.cpp
//  Algorithm_Practice
//
//  Created by 지원 on 2021/07/19.
//

#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <sstream>
using namespace std;

template <size_t N>
void print(array<int,N>& arr){
    for(auto ele : arr)
        cout << ele << " ";
}

void test1(){
    array<int,10> arr1;
    arr1[0] = 1;
    cout << "arr1 배열의 첫 번째 원소 : " << arr1[0] << endl;
    
    array<int,4> arr2 = {1,2,3,4};
    cout << "arr2 배열의 모든 원소 : ";
    
    for(int i = 0; i < arr2.size(); i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    array<int,5> arr3 = {1,2,3,4,5};
    print(arr3);
    cout << endl;
    
    for(auto it = arr3.begin(); it != arr3.end(); it++){
        auto element = *(it);
        cout << element << ' ';
    }
    cout << endl;

}

template <typename T>
class dynamic_array{
    T* data;
    size_t n;
    
public:
    dynamic_array(int n){
        this->n = n;
        data = new T[n]; //동적 배열 new int[5]; typename = T
    }
    //복사생성자
    dynamic_array(const dynamic_array<T>& other){
        n = other.n;
        data = new T[n];
        for(int i = 0; i < n; i++)
            data[i] = other[i];
    }
    
    //[]연산자와 at() 함수 작성
    T& operator[] (int index)
    {
        return data[index];
    }
    const T& operator[] (int index) const
    {
        return data[index];
    }
    
    T& at(int index){
        if(index < n)
            return data[index];
        throw "Index out of range";
    }
    
    //size()함수와 소멸자
    size_t size() const{
        return n;
    }
    
    ~dynamic_array(){
        delete[] data; //메모리 릭 방지
    }
    
    T* begin(){
        return data;
    }
    //데이터의 초기화가 이뤄지면 그 값을 바꿀 수 없도록 해 주는 것
    const T* begin()const{
        return data;
    }
    T* end(){
        return data + n;
        
    }
    const T* end() const{
        return data + n;
    }
    
    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1,
                                      dynamic_array<T>& arr2)
    {
        dynamic_array<T> result(arr1.size() + arr2.size());
        
        copy(arr1.begin(), arr1.end(), result.begin());
        copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
        
        return result;
    }
    string to_string(const string& sep = ", "){
        if(n == 0)
            return "";
        ostringstream os; //#include <sstream> 문자 파싱(조립)
        os << data[0];
        
        for(int i = 1; i < n; i++){
            os << sep << data[i];
        }
        
        return os.str(); //조립된 문자열 꺼내기
        
        
    }
    
};

struct student{
    string name; //학생 이름
    int standard; //학급 정보
};

ostream& operator<<(ostream& os, const student &s){
    return (os << "[" << s.name << ", " << s.standard << "]");
}


int main(){
    //test1();
    
    int nStudents;
    cout << "1반 학생 수를 입력하세요 : ";
    cin >> nStudents;
    
    dynamic_array<student> class1(nStudents);
    for(int i = 0; i < nStudents; i++){
        string name;
        int standard;
        cout << i+1 << "번째 학생 이름과 나이를 입력하세요: ";
        cin >> name >> standard;
        class1[i] = student{name,standard};
    }
    
    try{
        class1[nStudents] = student{"john, 8"};
        class1.at(nStudents) = student{"john, 8"};
    }
    catch(...){
        cout << "예외 발생!" << endl;
    }
    
    auto class2 = class1;
    cout << "1반을 복사하여 2반 생성 : " << class2.to_string() << endl;
    auto class3 = class1 + class2;
    cout << "1반과 2반을 합쳐 3반 생성 : " << class3.to_string() << endl;
    
    return 0;
    
}

