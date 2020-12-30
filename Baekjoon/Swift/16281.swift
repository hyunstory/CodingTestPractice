//
//  main.swift
//  swift_test
//
//  Created by HYUNSEUNG LEE on 2020/10/09.
//

import Foundation

let N = Int(readLine()!)!
var ans = 0

var arr = Array(repeating: Array(repeating: 0, count : 11), count: N + 1)
var check = Array(repeating: false, count: 11)
var picked = Array(repeating: 0, count : 11)

func simul(){
    
    var score = 0
    var startPlayer = 1
    var baseState = Array(repeating: false, count: 4)
    
    for i in 1...N{
        var outCnt = 0
        var nextIning = false
        baseState = Array(repeating: false, count: 4)
        
        while true{
            for j in startPlayer..<10{
                let player = arr[i][picked[j]]
                
                if player == 0{outCnt+=1}
                else if player == 1{
                    for f in (1...3).reversed(){
                        if baseState[f]{
                            if f == 3{
                                baseState[f] = false
                                score += 1
                            }
                            else{
                                baseState[f+1] = true
                                baseState[f] = false
                            }
                        }
                    }
                    baseState[1] = true
                }
                else if player == 2{
                    for f in (1...3).reversed(){
                        if baseState[f]{
                            if f == 3 || f == 2{
                                baseState[f] = false
                                score += 1
                            }
                            else{
                                baseState[f+2] = true
                                baseState[f] = false
                            }
                        }
                    }
                    baseState[2] = true
                }
                else if player == 3{
                    for s in (1...3).reversed(){
                        if baseState[s]{
                            baseState[s] = false
                            score += 1
                        }
                    }
                    baseState[3] = true
                    
                }
                else{
                    for f in 1...3{
                        if baseState[f]{
                            baseState[f] = false
                            score += 1
                        }
                    }
                    score += 1
                }
                
                if outCnt == 3{
                    startPlayer = j + 1
                    if startPlayer == 10 {startPlayer = 1}
                    nextIning = true
                    break
                }
            }
            if nextIning{break} // 3진 아웃일 때 브레이크를 하기 때문에, 3진아웃이 되고, 만약 모든 선수가 돌았다면, 1로 다시 돌린다. 위의 코드
            startPlayer = 1
        }
    }
    
    ans = max(ans, score)
}

func dfs(_ idx: Int){
    
    if idx == 10{
        simul()
        return
    }
    
    for i in 1..<10{
        if check[i] {continue}
        
        check[i] = true
        picked[i] = idx // 이거 신기함.. 원래는 picked[idx] = i이다....흠..바꿔도 돌아갈듯..흠 흠...
        dfs(idx + 1)
        check[i] = false
    }
}


for i in 1...N{
    //let temp: [Int] = readLine()!.split(separator: " ").map{Int(String($0))!}
    arr[i] = [0] + readLine()!.split(separator: " ").map{Int(String($0))!}
    
}

check[4] = true
picked[4] = 1

dfs(2)


print(ans)




