//
//  main.swift
//  SwiftPractice
//
//  Created by HYUNSEUNG LEE on 2020/12/29.
//

import Foundation


/* Set타입은 NSSet 클래스를 브릿지로 한 형태이다.
Set은 순서가 중요하지 않거나, 하나의 항목만 가져와야 할 때 사용할 수 있다.
 
 유일한 값 1개만 저장된다.
 
 Array 배열에서 유일한 값들만 뽑아내고 싶다면, Set(배열) -> Array(결과값)을 하면, unique한 원소들만 뽑을 수 있다.
 Set은 원래 정렬이 되지 않지만,
 .sorted() 메서드를 이용하면 정렬된 결과값을 받을 수 있다.
 */

// 선언

var sets = Set<String>()
var sets2: Set<String> = []

// 초기값 대입
var sets3 = Set([1, 2, 3])

// 삽입, 삭제
sets.insert("1")

sets.remove("1")

sets.removeAll()

// 특정 항목이 있는지 검사
if sets.contains("1"){print(" ")} // 있으면 true, 없으면 false 반환

// isEmpty, count 프로퍼티 적용가능함
if sets.isEmpty{print(" ")}
print(sets.count)

// 정렬
var sets6 = sets.sorted(by: >) //내림차순 정렬




// Set 연산 작업 및 비교 (집합) -> 새로운 Set을 만든다.

// 교집합
var intersect = sets.intersection(sets2) // intersection 이름 꼭 외우기

//합집합
var union = sets.union(sets2)

//차집합
var subtract = sets.subtract(sets2)


// 과연 외울수 있을까? 아래.. 코테에서 추천해주면 좋은데..
//isSubsetOf : Set의 모든 값이 특정 Set에 포함되는지를 확인합니다.

//isSupersetOf : Set의 모든 값이 특정 Set을 포함하는지 확인합니다.

//isDisjointWith : 두 Set이 일치하지 않는지 확인합니다.






