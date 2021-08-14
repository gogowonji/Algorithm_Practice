//
//  main.cpp
//  practice5
//
//  Created by 지원 on 2021/08/14.
//

#include <iostream>
#include <forward_list>
#include <vector>
#include <algorithm>
using namespace std;

void practice(){
    //vector
    vector<string> vec = {
        "Lewis Hamilton", "Levis Hamilton", "Nico Roseberg",
        "Sevastian Vettel","Lewis Hamilton", "Sevastian Vettel",
        "Sevastian Vettel", "Sevastian Vettel", "Fernando Alonso"
        
    };
    
    auto it = vec.begin(); //상수 시간 (일정)
    cout << "가장 최근 우승자 : " << *it << endl;
    
    it+= 8; //상수 시간
    cout << "8년 전 우승자 : " << *it << endl;
    
    advance(it,-3); //상수 시간
    cout << "그후 3년 뒤 우승자 : " << *it << endl;
    
    
    //forward_list
    forward_list<string> fwd(vec.begin(),vec.end()); //*****
    
    auto it1 = fwd.begin();
    cout << "가장 최근 우승자 : " << *it1 << endl;
    
    advance(it1, 5); //선형 시간
    cout << "5년 전 우승자 : " << *it1 << endl;
    
    //advance(it1,-3); // forward_list는 순방향으로만 이동할 수 있으므로 에러 발생
    //it+=2; //forward_list 에러

}

struct singly_ll_node
{
    int data;
    singly_ll_node* next;
};

class singly_ll{
public:
    using node = singly_ll_node;
    using node_ptr = node*;
    
private:
    node_ptr head;
    
public:
    void push_front(int val)
    {
        auto new_node = new node {val, NULL};
        
        if(head != NULL)
            new_node->next = head;
        head = new_node;
    }
    
    void pop_front()
    {
        auto first = head;
        if(head){
            head = head->next;
            delete first;
        }
    }
    
    struct singly_ll_iterator{
    private:
        node_ptr ptr;
        
    public:
        singly_ll_iterator(node_ptr p) : ptr(p){} //생성자
        //멤버변수 ptr을 p로 초기화 (초기화 리스트)
        
        int& operator*() { //접근자
            return ptr->data;
        }
        node_ptr get() { //접근자
            return ptr;
        }
        singly_ll_iterator& operator++(){ //선행 증가
            ptr = ptr->next;
            return *this;
        }
        singly_ll_iterator operator++(int){ //후행 증가
            singly_ll_iterator result = *this;
            ++(*this);
            return result;
        }
        
        //반복자가 같은지 판단하는 관계 연산자 함수
        //firend 클래스는 friend로 선언된 다른 클래스의 private 및 protected 멤버에 접근할 수 있음
        friend bool operator==(const singly_ll_iterator& left,
                               const singly_ll_iterator& right){
            return left.ptr == right.ptr;
        }
        friend bool operator!=(const singly_ll_iterator& left,
                               const singly_ll_iterator& right){
            return left.ptr != right.ptr;
        }
    };
    
    singly_ll_iterator begin(){
        return singly_ll_iterator(head);
    }
    singly_ll_iterator end() {
        return singly_ll_iterator(NULL);
    }
    singly_ll_iterator begin() const {
        return singly_ll_iterator(head);
    }
    singly_ll_iterator end() const{
        return singly_ll_iterator(NULL);
    }
    
    
    singly_ll() = default;
    //sigly_ll(){}와 동일  (기본 생성자)
    
    //깊은 복사를 위한 복사 생성자
    singly_ll(const singly_ll& other) : head(NULL){
        
        if(other.head){
            head = new node{0,NULL};
            auto cur = head;
            auto it = other.begin();
            
            while(true){
                cur->data = *it;
                auto tmp = it;
                ++tmp; //이동
                
                if(tmp == other.end())
                    break;
                
                cur->next = new node{0,NULL};
                
                cur = cur->next;
                
                it = tmp;
            }
        }
    }
    singly_ll(const initializer_list<int>& ilist) : head(NULL){
        for(auto it = rbegin(ilist);
            it != rend(ilist);
            it++){
            push_front(*it);
        }
    }
};
void practice2(){
    singly_ll sll = {1,2,3};
    sll.push_front(0);
    
    cout << "첫 번째 리스트 : ";
    for(auto i :sll)
        cout << i << " ";
    cout << endl;
    
    auto sll2 = sll;
    sll2.push_front(-1);
    
    cout << "첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가 : ";
    for(auto i : sll2)
        cout << i << " ";
    cout << endl;
    
    //깊은 복사가 일어났기 때문에 처음 리스트 원소와 동일
    cout << "깊은 복사 후 첫 번째 리스트 : ";
    for(auto i : sll)
        cout << i << " ";
    cout << endl;
    
    
}

int main() {
    // insert code here...
    //practice();
    practice2();
    
    return 0;
}
