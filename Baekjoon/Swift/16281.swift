//
//  main.swift
//  swift_test
//
//  Created by HYUNSEUNG LEE on 2020/10/09.
//

import Foundation

var N = Int(readLine()!)!

let memberSize = 10

var arr = Array(repeating: Array(repeating: 0, count: 10), count: N + 1)
var check = Array(repeating: false, count: 10)
var picked = Array(repeating:0, count: 10)

var result = 0

func simul(){
    
    var score = 0
    var startPlayer = 1
    var base = Array(repeating: false, count: 4)
    
    
    
    for i in 1...N{
        
        var outCnt = 0
        var nextIning = false
        
        base = Array(repeating: false, count: 4)
        
        while true{
            for j in startPlayer...9{
                let player = arr[i][picked[j]]
                
                
                // 아웃 일 때,
                if player == 0{outCnt += 1}
                
                else if player == 1{
                    for f in (1...3).reversed(){
                        if base[f]{
                            if f == 3{
                                base[f] = false
                                score += 1
                            }
                            else{
                                base[f+1] = true
                                base[f] = false
                            }
                        }
                        
                    }
                    base[1] = true
                    
                }
                else if player == 2{
                    for f in (1...3).reversed(){
                        if base[f]{
                            if f == 3 || f == 2{
                                base[f] = false
                                score += 1
                            }
                            else{
                                base[f+2] = true
                                base[f] = false
                            }
                        }
                    }
                    
                    
                    base[2] = true
                }
                else if player == 3{
                    for f in (1...3).reversed(){
                        if base[f]{
                            base[f] = false
                            score += 1
                        }
                    }
                    
                    base[3] = true
                }
                else{
                    // 바로 홈런일 때
                    for f in 1...3{
                        if base[f]{
                            base[f] = false
                            score += 1
                        }
                    }
                    score += 1
                    
                }
                
                if outCnt >= 3{
                    startPlayer = j + 1
                    if startPlayer == 10{startPlayer = 1}
                    nextIning = true
                    break
                }
                
            }
            
            if nextIning {break}
            startPlayer = 1
        }
        
    }
    
    result = max(result, score)
}


func dfs(_ idx: Int){
    
    if (idx == memberSize){
        simul()
        return
    }
    
    for i in 1...9{
        if check[i] {continue}
        
        check[i] = true
        picked[i] = idx
        dfs(idx + 1)
        check[i] = false
        
    }
    
}


for i in 1...N{
    
    arr[i] = [0] + readLine()!.split(separator: " ").map{Int(String($0))!}
    
}


check[4] = true
picked[4] = 1

dfs(2)



print(result)
