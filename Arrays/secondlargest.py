class Solution:
    def getSecondLargest(self, arr):
        # Code Here
        l = s = -1
        for num in arr:
            if num > l:
                s = l 
                l = num
            elif num != l and num > s:
                s = num
        return s
    

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.getSecondLargest(arr)
        print(ans)
        print("~")
# }