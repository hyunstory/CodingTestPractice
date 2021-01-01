

import Foundation

// swift문자열은 첨자 접근이 안되기 때문에, 배열로 바꿔서 접근한다. Character로 바꾸려고 했더니, 이상한 아웃변수 이름 적어야하는데, 코딩테스트 때 IDE를 사용못해서 긴 영어는 외우지 말자
// 꼭 필요할 땐 arr.map{String($0)}로 하면 각 문자열을 배열로 담아준다. 그 다음 첨자 접근하고 다시 합쳐주어야 한다..-_-... C++, Python이 너무 효율적이다. 

var str = "Test"

var arr = str.map{String($0)}

for i in arr{
    print(arr)
}