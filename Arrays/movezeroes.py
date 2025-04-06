class Solution:
	def pushZerosToEnd(self,arr):
		non_zero_index = 0
		for i in range(len(arr)):
			if arr [i] != 0:
				arr[non_zero_index] = arr[i]
				non_zero_index += 1
		while non_zero_index < len(arr):
			arr[non_zero_index] = 0 
			non_zero_index += 1

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ob.pushZerosToEnd(arr)
        for x in arr:
            print(x, end=" ")
        print()
        tc -= 1
        print("~")
