"""
- 음수값이면 절대값으로 계산

- 내가 연산자 우선순위를 정해서 값 최대로 만들기 / 최대 조합이아니라 최대값을 만드는..
- 그러면 모든연산자에대해 1빠로 계산하는거를 알아야게지
-------------- 내 생각 ---------------
- 문자열에 들어간 연산자 무엇인지 보고 -> 순열로 조합 만들어서 -> 어케어케 계산
    ~ 이 어케어케 계산이 계속 막혔었는데 ( 이상한 방식으로 풀으려고 했다.) 결국 답 봤따.
    
------------- 전개 --------------
- 우선순위가 낮은 놈은 높은 것의 계산이 먼저 필요함! -> 꺼꾸로 쪼개자.

1. 나올 수 있는 연산자 우선순위 경우의 수가 *,+,- 로 6가지뿐이므로 직접 정해줘도 된다.
2. 연산자 우선순위 거꾸로 식을 쪼개는 방식! (- > * 에서)
    ex) 50 * 6 - 3 * 2
        => 50 / 6-3 / 2
        => 50 / 3 / 2
        => 순서대로 이제 계산하기
        
    ex2) 100-200*300-500+20 / * > + > -
        => 100 / 200*300 / 500+20 ~ - 기준 쪼개기
        => 100 / 200*300 / 500 / 20 ~ + 기준 쪼개기
        
        => 100 / 60000 / 500 / 20 ~ * 계산
        => 100 / 60000 / 500+20 ~ + 계산
        => 100 - 60000 - 520 ~ - 계산
        
# join 은 list를 string화 해주는 함수!
# eval = 문자열로 된 수식의 결과값을 리턴함 = 숫자 자료형으로!

~ 다른 사람의 코드를 보고 에러가 났던 부분은 자료형 변환에 있었다.
~ 자주 쓰고 익혀놔야 알 것 같다. 모르겠으면 강제 변환으로 항상 시켜주자
"""
def calc(priority, n, expr):
    # n == 2 라는 소리는 priority를 다 돌았을 때 -> 합쳐서 계싼만 하면 된다.
    if(n == 2):
        return str(eval(expr))
    # priority속 원소를 기준으로 쪼갠 조각을 넣어준다.
    if priority[n]=="*":
        res = eval("*".join([calc(priority, n+1, e) for e in expr.split("*")]))
    elif priority[n]=="+":
        res = eval("+".join([calc(priority, n+1, e) for e in expr.split("+")])) 
    elif priority[n]=="-":
        res = eval("-".join([calc(priority, n+1, e) for e in expr.split("-")]))       
    return str(res)
def solution(expression):
    answer = 0
    
    priority = [
        ("+", "-", "*"),
        ("+", "-", "*"),
        ("-", "+", "*"),
        ("-", "*", "+"),
        ("*", "+", "-"),
        ("*", "-", "+")
    ]
    
    for p in priority:
        res = int(calc(p, 0, expression))
        # 음수값의 경우 절대값을 씌워줘야함
        answer = max(answer, abs(res))
        
    return answer