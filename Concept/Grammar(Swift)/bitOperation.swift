import Foundation

// C언어와 비트 연산이 같다

var bit1: UInt32 = 1 // c언어의 32비트로 만들어 줄 수 있다.
var bit2: UInt32 = 16

print("AND연산\(bit1 & bit2)")
print("OR연산\(bit1 | bit2)")
print("EOR연산\(bit1 ^ bit2)")

print("Left Shift 연산 \(bit1 << 3)")
print("Right Shift 연산 \(bit2 >> 2)")