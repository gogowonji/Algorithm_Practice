//
//  main.cpp
//  music_player
//
//  Created by 지원 on 2021/08/16.
//

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>

struct cir_list_node{
    T* data;
    cir_list_node* next;
    cir_list_node* prev;
    
    ~cir_list_node(){
        delete data;
    }
};

template <typename T>
class cir_list{
public:
    using node = cir_list_node<T>;
    using node_ptr = node*;
    
private:
    node_ptr head;
    size_t n;
    
public:
    cir_list(){
        head = new node {NULL, NULL, NULL}; //dummy node
        head -> next = head;
        head -> prev = head;
    }
    size_t size() {
        return n;
    }
    void insert(const T& value){
        node_ptr newNode = new node {new T(value), NULL, NULL};
        n++;
        
        auto dummy = head->prev; //dummy는 항상 맨 마지막 노드
        dummy->next = newNode; //마지막 더미노드의 next변경
        newNode->prev = dummy; //추가한 노드의 prev를 더미로
        
        if(head == dummy){
            //size가 0일 때
            //원형으로 만들어줌
            dummy->prev = newNode; //더미의 prev를 새로 추가한 노드로
            newNode->next = dummy; //새로 추가한 노드의 next를 더미로
            head = newNode;
            return; //끝
        }
        
        newNode->next = head; //추가한 노드의 next를 첫 번째 노드로
        head->prev = newNode; //head 노드의 prev를 추가한 노드로
        head = newNode;
        
    }
    
    void erase(const T& value){
        auto cur = head;
        auto dummy = head->prev;
        
        while(cur != dummy){
            //list 내부 돌기
            if(*(cur->data) == value)
            {
                //이전 노드의 next 노드를 다음 노드로 바꿔주기
                cur->prev->next = cur->next;
                //다음 노드의 prev 노드를 이전 노드로 바꿔주기
                cur->next->prev = cur->prev;
                //가장 앞 노드라면 head 바꿔주기
                if(cur == head)
                    head = head->next;
                //삭제
                delete cur;
                n--;
                return; //끝
            }
            //value 안맞으면 다음 노드로 이동
            cur = cur->next;
        }
    }
    
    //반복자 세팅
    struct cir_list_it{
    private:
        node_ptr ptr;
        
    public:
        cir_list_it(node_ptr p) : ptr(p) {}
        
        T& operator*(){
            return *(ptr->data);
        }
        
        node_ptr get(){
            return ptr;
        }
        
        cir_list_it& operator++(){
            ptr = ptr->next;
            return *this;
        }
        
        cir_list_it& operator++(int){
            cir_list_it it = *this;
            ++(*this);
            return it;
        }
        
        cir_list_it& operator--(){
            ptr = ptr->prev;
            return *this;
        }
        
        cir_list_it& operator--(int){
            cir_list_it it = *this;
            --(*this);
            return it;
        }
        
        friend bool operator==(const cir_list_it& it1, const cir_list_it& it2){
            return it1.ptr == it2.ptr;
        }
        
        friend bool operator!=(const cir_list_it& it1, const cir_list_it& it2){
            return it1.ptr != it2.ptr;
        }

        
        
    };
    
    cir_list_it begin(){
        return cir_list_it {head};
    }
    
    cir_list_it begin() const {
        return cir_list_it {head};
    }
    
    cir_list_it end(){
        return cir_list_it {head->prev};
    }
    
    cir_list_it end() const{
        return cir_list_it {head->prev};
    }
    
    
    
    //복사 생성자
    cir_list(const cir_list<T>& other) : cir_list(){
        for(const auto& i : other)
            insert(i);
    }
    
    //초기화 리스트 생성자
    cir_list(const initializer_list<T>& il) : head(NULL), n(0){
        for(const auto& i : il)
            insert(i);
    }
    
    //소멸자
    ~cir_list(){
        while(size()){
            erase(*(head->data));
        }
        delete head;
    }
    
};


struct playlist{
    cir_list<int> list;
    
    void insert(int song){
        list.insert(song);
    }
    
    void erase(int song){
        list.erase(song);
    }
    
    void loopOnce(){
        for(auto& song : list){
            cout << song << " ";
        }
        cout << endl;
    }
};

int main() {
    playlist pl;
    pl.insert(1);
    pl.insert(2);
    cout << "재생목록 : ";
    pl.loopOnce();
    
    playlist pl2 = pl;
    pl2.erase(2);
    pl2.insert(3);
    cout << "두 번째 재생목록 : ";
    pl2.loopOnce();

    return 0;
}
