import Foundation


    

let N = Int(readLine()!)!

for _ in 1...N{

    
    let line = readLine()!
    
    let getA = line.components(separatedBy: ",")
    let a = Int(getA[0])!
    let b = Int(getA[1])!
    
    print(a+b)
}