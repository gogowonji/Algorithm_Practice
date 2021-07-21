//
//  main.cpp
//  practice2
//
//  Created by 지원 on 2021/07/21.
//

#include <iostream>
#include <array>
#include <type_traits>
using namespace std;

template<typename ... Args>
auto build_array(Args&&... args)
-> array <typename common_type <Args...>::type, sizeof...(args)>
//후행리턴타입 리턴값이 무엇인지 미리 명시해둠
{
    using commonType = typename common_type<Args...>::type;
    return {forward<commonType>((Args&&)args)...};
}


int main() {
    // insert code here...
    auto data = build_array(1,0u,'a',3.2f,false);
    
    for(auto i:data)
        cout << i << " ";
    cout << endl;
    
    // 공통 타입으로 변환 할 수 없어서 에러 발생
    //auto data2 = build_array(1,'fllo',2.0);

    
    return 0;
}
