# 덧셈해서 타겟 숫자를 만들 수 있는 두 숫자 인덱스의 리턴
# 해당 경우, ary가 이미 sorted 되어있다고 가정
class Solution:
    # Two pointer
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        left, right = 0, len(nums)-1
        while not left == right:
            # 값이 작다면, 왼쪽 포인터 옮김
            if nums[left] + nums[right] < target:
                left +=1
            elif nums[left] + nums[right] > target:
                right +=1
            else:
                return left, right

if __name__ == '__main__':
    sol = Solution()
    print(sol.twoSum([2, 7, 11, 15], 9))