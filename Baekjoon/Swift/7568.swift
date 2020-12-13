//
//  main.swift
//  코딩테스트
//
//  Created by David Lee on 2020/06/05.
//  Copyright © 2020 personal. All rights reserved.
//

import Foundation

var arr = Array<(Int, Int, Int)>()


let N = Int(readLine()!)!

for i in 1...N{
    
    let line = readLine()!
    
    let getA = line.components(separatedBy: " ")
    let a = Int(getA[0])!
    let b = Int(getA[1])!
    
    arr.append((a, b, i - 1))
}

var rank = 0
for i in 0...N-1{
    rank = 1
    for j in 0...N-1{
        if (arr[i].0 < arr[j].0) && ( arr[i].1 < arr[j].1) {
            rank += 1
        }
    }
    print(rank)
}