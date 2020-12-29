//
//  main.swift
//  SwiftPractice
//
//  Created by HYUNSEUNG LEE on 2020/12/29.
//

import Foundation


/* C++의 map과 같이, key와 value를 저장해준다.

key는 유일한 값이다.
 
 Dictionary는 Set과 같이 순서가 없다.
 
 key에 Hashable이지만, enum이 들어갈 수 있음
 
 */


// 생성 방법
var dic: [Int : String] = [:]
var dic2 = [Int : String]()
var dic3 = Dictionary<Int, String>()


// 생성과 동시에 초기화
var dic4 = [1:"1", 2:"2"]

// 값 수정
dic[1] = "4"
dic.updateValue("4", forKey: 1) // 반대로 되어있다. value를 쓰고, 어디 위치인 key값을 뒤에 쓴다.

// 추가
dic[6] = "7" // 쓰고 없으면 바로 생성이 된다. upsert가 됨

// 접근, 옵셔널이기 때문에 강제 언래핑을 해준다.

print(dic[1]!)

// for 문
for (key, value) in dic{
    print(key)
    print(value, terminator: "")
}


// 있는지 검사하기
if dic.keys.contains(1){print("yes")}

// 그 외 유용한 프로퍼티즈
print(dic.count)
if dic.isEmpty{print("empty")}

//삭제
dic[1] = nil // deinit을해준다.
dic.removeValue(forKey: 1)
dic.removeAll() // 꼭 활성화해주기


// 정렬
// key정렬
let keyOrder = dic.keys.sorted(by: >)
// value정렬
let valueOrder = dic.values.sorted(by: >)






