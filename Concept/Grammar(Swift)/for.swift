import Foundation


// for문


// 자주 쓰는 for문 (범위)
for i in 0..<9{
    print(i)
    // 0부터 8까지 출력
}

//감소
for i in (0..<9).reversed(){
    print(i)
    // 8부터 0까지 출력
}


// stride를 사용해서 점프 할 수 있다.
for i in stride(from: 0, to: 100, by: 2){ // 마지막 100은 범위 안에 안들어감. 99까지 들어감..꼭 기억하기!
    print(i, terminator: " ")
}