def solution(record):
    answer = []
    dic = {}
    for r in record:
        d = r.split(" ")
        if d[0] != "Leave": dic[d[1]] = d[2]
    
    for r in record:
        d = r.split(" ")
        if d[0] == "Enter": answer.append(f'{dic[d[1]]}님이 들어왔습니다.')
        elif d[0] == "Leave": answer.append(f'{dic[d[1]]}님이 나갔습니다.')

    return answer
