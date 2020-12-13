//
//  main.swift
//  swift_test
//
//  Created by HYUNSEUNG LEE on 2020/10/09.
//

import Foundation

let N = Int(readLine()!)!

var ArrayN = readLine()!.split(separator: " ").map { Int(String($0))! }

let M = Int(readLine()!)!

//var ArrayM = Array(repeating: 0, count: M)
var ArrayM = readLine()!.split(separator: " ").map{ Int(String($0))! }
//let ArrayM = readLine()!.split(separator: " ").map { Int($0)! }

var result = Array<Int>()

func findValue(_ value: Int) -> Bool{
    
    var left = 0
    var right = ArrayN.count - 1
    
    while left <= right{
        
        let mid = (left + right) / 2
        
        if ArrayN[mid] > value{
            right = mid - 1
        }
        else if ArrayN[mid] < value{
           left = mid + 1
        }
        else{
            return true
        }
    }
    return false
    
    
}

ArrayN.sort()

for value in ArrayM{
    if findValue(value){
        result.append(1)
    }
    else{
        result.append(0)
    }
}

for value in result{
    
    print(value, terminator: " ")
}


