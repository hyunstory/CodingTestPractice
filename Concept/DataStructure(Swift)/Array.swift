//
//  main.swift
//  SwiftPractice
//
//  Created by HYUNSEUNG LEE on 2020/12/29.
//

import Foundation

// 배열 정리


// Array 배열 생성
var arr1 = [Int](repeating: 0, count: 5)
var arr2: [Int] = []
var arr3 = Array<Int>()
var arr4 = [Int]()


// 배열에 요수 추가하기

arr1.append(5)
arr1.append(contentsOf: [8, 9])
arr1 += [7, 8] // 파이썬이랑 비슷하게, 뒤에서 +연산자로 붙일 수 있다. 이 +연산자가 append보다 쉬울것같다


// 특정 위치에 넣기
arr2.insert(0, at:0) // 0값을 0위치에 삽입하기
arr2.insert(contentsOf: [8, 9], at: 0) // [8, 9]를 0위치에 삽입하기

// 배열에서 요소 삭제하기
arr2.remove(at: 0) // 0인덱스에 있는 것 삭제하기
arr2.removeSubrange(0...1) // 0~1 모두 포함 인덱스의 값 삭제하기
arr2.removeAll() // 배열의 모든 값 초기화


// 첫번째 마지막 원소 접근하기
print(arr2.first!) // 첫번째 요소, 없을 수 있기 때문에 언래핑한다
print(arr2.last!) // 마지막 요소, 없을 수 있기 때문에 언래핑한다

// 배열 확인하기

if arr2.isEmpty{print("")} // ()쓰면 안된다. 활성화가 아니라, 여부를 묻는거임.
print(arr2.count) // 개수 세기









