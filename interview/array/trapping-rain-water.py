class Solution:
    def trap(self, height: List[int]) -> int:
        # 높이가 존재하지 않다 = 민둥이다
        if not height:
            return 0;
        volume = 0
        left, right = 0, len(height)-1
        
        left_max, right_max = height[left], height[right]
        
        while left < right :
            left_max, right_max = max(height[left], left_max), max(height[right], right_max)

            # 높이가 더 높은 쪽을 향해 이동
            if left_max <= right_max: # 왼쪽으로 이동 (물을 담아 가면서!)
                volume += left_max - height[left]
                left += 1

            else:
                volume += right_max - height[right]
                right -= 1
            
        return volume