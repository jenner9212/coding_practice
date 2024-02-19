def solution(array, commands):
    answer = []
    
    for c in commands:
        v = array[c[0]-1 : c[1]]
        v.sort()
        
        answer.append(v[c[2] - 1])
    
    return answer