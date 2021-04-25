def bubble(ary):
    for i in range(len(ary)-1):
        for j in range(len(ary)-1-i):
            if(ary[j] > ary[j+1]):
                temp = ary[j]
                ary[j] = ary[j+1]
                ary[j+1] = temp
    
    print(ary)


# 좀 더 쉽게 생각해보자잔자리장
def insertion(ary):
    

    for i in range(1, len(ary)):
        # 2번쨰 요소부터 시작
        key = ary[i]
        idx = 0

        # 끝에서부터 돌면서 삽입 위치 찾기
        for j in range(i, -1, -1):
            if(key > ary[j]):
                idx = j
            else:
                ary[j] = ary[j-1]

        
        ary[idx] = key

    print(ary)
    

def selection(ary):

    for i in range(len(ary)):
        idx = i # 해당 위치에 들어간다

        for j in range(i+1, len(ary)):
            if(ary[idx] > ary[j]):
                idx = j

        temp = ary[i]
        ary[i] = ary[idx]
        ary[idx] = temp

    print(ary)





    

def selection(ary):

    for i in range(len(ary)):
        
        # i번쨰 요소와 바꾼다.
        # 이후의 배열 들에서 최소값 인덱스 찾기
        idx = i
        for j in range(i+1, len(ary)):
            if(ary[idx] > ary[j]):
                idx = j
        
        temp = ary[i]
        ary[i] = ary[idx]
        ary[idx] = temp
    
    print(ary)




def quick(ary, left, right):

    if(left < right):
        idx = partition(ary, left, right)
        quick(ary, left, idx)
        quick(ary, idx+1, right)

    return ary

def partition(ary, left, right):
    i = left
    pivot = ary[left]
    #print("pivot", pivot, ary)
    for j in range(left+1, right):
        if(ary[j]<pivot):
            i +=1
            temp = ary[j]
            ary[j] = ary[i]
            ary[i] = temp
            #print("part",ary)

    temp = ary[i]
    ary[i] = pivot
    ary[left] = temp

    return i






sorted=[]
def merge(ary, left, right):

    if(right-left < 2):
        return
    mid = (left+right) // 2
   
    merge(ary, left, mid)
    merge(ary, mid, right)

    # 2개의 부분 배열 합병
    _merge(ary, left, mid, right)

def _merge(ary, left, mid, right):
    temp = []
    l, h = left, right
    print("enter", left, mid, right)
    while(l < mid and h < right):
        if (ary[l]< ary[h]):
            temp.append(ary[l])
            l +=1
        else:
            temp.append(ary[h])
    
        print("whie", temp)
        while l < mid:
            temp.append(arr[l])
            l += 1
        while h < high:
            temp.append(arr[h])
            h +=1

    print(temp)
ary = [6, 10, 13, 5, 8, 3, 2, 11]
#bubble(ary)
#insertion2(ary)
#insertion(ary)
#selection(ary)


end = quick(ary, 0, len(ary))
print(end)

#merge(ary, 0, len(ary))
#print(sorted)

#print((2+2)/2)
