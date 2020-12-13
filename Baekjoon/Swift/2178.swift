
//
//  main.swift
//  swift_test
//
//  Created by HYUNSEUNG LEE on 2020/10/09.
//

import Foundation

let t = readLine()!.split(separator: " ").map {Int($0)!}
let N = t[0]
let M = t[1]

var dx = [1, -1, 0, 0]
var dy = [0, 0, -1, 1]

var map = Array(repeating: Array(repeating: 0, count: M), count: N)
var check = Array(repeating: Array(repeating: false, count: M), count: N)
var distance = Array(repeating: Array(repeating: 0, count: M), count: N)

for i in 0..<N{
    var temp: [Int]
    temp = readLine()!.map { Int(String($0))! }
    
    map[i] = temp
}

func bfs(){
    
    distance[0][0] = 1
    
    check[0][0] = true
    
    var q = Array<(Int, Int)>()
    
    q.append((0, 0))
    
    while !q.isEmpty{
        let poped = q[0]
        q.remove(at: 0)
        
        let x = poped.0
        let y = poped.1
        
        for k in 0..<4{
            let nx = x + dx[k]
            let ny = y + dy[k]
            
            if nx >= 0 && nx < N && ny >= 0 && ny < M && !check[nx][ny] && map[nx][ny] == 1{
                
                distance[nx][ny] = distance[x][y] + 1
                
                check[nx][ny] = true
                q.append((nx, ny))
                
            }
            
        }
        
        
    }
    
    
}

bfs()

print(distance[N-1][M-1])
