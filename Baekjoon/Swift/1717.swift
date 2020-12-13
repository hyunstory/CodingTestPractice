//
//  main.swift
//  swift_test
//
//  Created by HYUNSEUNG LEE on 2020/10/09.
//

import Foundation

let t = readLine()!.split(separator: " ").map { Int(String($0))! }
let N = t[0]
let M = t[1]
var result = Array<String>()

struct NaiveUFSet{
    var root: [Int]
    
    init(_ N: Int){
        root = Array(0...N)
    }
    
    mutating func find(_ x: Int) -> Int{
        if root[x] == x{
            return x
        }
        root[x] = self.find(root[x])
        return root[x]
    }
    
    mutating func union(_ x: Int, _ y: Int){
        let a = self.find(x)
        let b = self.find(y)
        
        if b > a{
        root[b] = a
        }
        else if a > b{
            root[a] = b
        }
    }
}


var ufset = NaiveUFSet(N)

for _ in 0..<M{
    
    let temp = readLine()!.split(separator: " ").map { Int(String($0))! }
    let cmd = temp[0]
    let A = temp[1]
    let B = temp[2]
    
    if cmd == 0{
        ufset.union(A, B)
        
    }
    
    else if cmd == 1{
        
        if ufset.find(A) == ufset.find(B) { result.append("YES") }
        else { result.append("NO") }
        
    }
}

for str in result{
    print(str)
}

