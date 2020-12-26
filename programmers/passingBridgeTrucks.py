from collections import deque

def solution(bridge_length, weight, truck_weights):
    time = 0
    bridge = deque([0]*bridge_length)
    truck_weights = truck_weights[::-1]
    total_weights = 0
    
    # while 조건을 truck_weights 로 두고, 마지막 남은 놈의 몫을 더해주는 것! 어떻게 이렇게 생각하지..
    while truck_weights:
        time +=1
        total_weight -= bridge.popleft()
        
        if total_weight + truck_weights[-1] > weight:
            bridge.append(0)
        else:
            truck = truck_weights.pop()
            bridge.append(truck)

            total_weight += truck
    time += bridge_length
      
    """
    # 아래 코드는 while 조건이 bridge의 len 기준이라서 truck_weights 다 소진해도 계속 돌아서 시간이 오래걸린거.
    while len(bridge) != 0:
        time +=1
        bridge.popleft()
        
        if truck_weights:
            if sum(bridge)+ truck_weights[-1] <= weight:
                bridge.append(truck_weights.pop())
            else:
                bridge.append(0)
    """
    return time



