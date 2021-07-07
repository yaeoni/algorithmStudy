import sys

# bubble sort
if __name__ == '__main__':

    n = int(sys.stdin.readline())
    ary = list(map(int, sys.stdin.readline().split()))

    cnt = 0

    # 일반 버블 소트 -> 시간 초과 (1초)
    """
    for i in range(n-1):
        for j in range( (n-1)-i ):
            if(ary[j] > ary[j+1]):
                temp = ary[j]
                ary[j] = ary[j+1]
                ary[j+1] = temp

                cnt +=1
    """
    print(cnt)