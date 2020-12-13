//
//  main.swift
//  swift_test
//
//  Created by HYUNSEUNG LEE on 2020/10/09.
//

import Foundation

let N = Int(readLine()!)!
let M = Int(readLine()!)!

var map: [[Bool]] = Array(repeating: Array(repeating: false, count: N + 1), count: N + 1)
var check: [Bool] = Array(repeating: false, count: N + 1)
var result = 0


func dfs(_ index: Int){
    
    
    check[index] = true
    
    
    
    for value in 1...N{
        
        
        if !map[index][value] || check[value] { continue }
        
        check[value] = true
        
        result += 1
        dfs(value)
    }
}

for _ in 0..<M{
    let temp = readLine()!.split(separator: " ").map { Int($0)! }
    let A = temp[0]
    let B = temp[1]
    
    map[A][B] = true
    map[B][A] = true
    
}


dfs(1)

print(result)

