def solution(s):
    arr = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]    
    for idx in range(len(arr)):
        while arr[idx] in s: s = s.replace(arr[idx], str(idx))
            
    return int(s)
