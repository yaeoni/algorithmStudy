from collections import deque
def solution(bridge_length, weight, truck_weights):
    
    # 정말 다리 자체를 표현한거구만 / 0 으로 초기화
    bridge = deque( 0 for _ in range(bridge_length))
    totalWeight = 0
    step = 0
    truck_weights.reverse() # 빼내기 쉽게!
    
    while truck_weights:
        # 다리 다 건넌 트럭은 무게에서 빼주기
        # 무게 or 0 으로 들어가있음
        totalWeight -= bridge.popleft()
        
        if totalWeight + truck_weights[-1] > weight:
            bridge.append(0)
        else:
            t = truck_weights.pop()
            bridge.append(t)
            totalWeight += t
        
        step += 1
    
    # 마지막 트럭이 다리에 올라가면 while문 종료
    # 즉 마지막 트럭이 가는 길이 또한 더해줘야한다!
    step += bridge_length

    return step