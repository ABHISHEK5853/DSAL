class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        dummy = ListNode()
        tail = dummy

        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        if list1:
            tail.next = list1
        if list2:
            tail.next = list2

        return dummy.next

def print_list(head: ListNode):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("None")

list1 = ListNode(1, ListNode(3, ListNode(5)))

list2 = ListNode(2, ListNode(4, ListNode(6)))

solution = Solution()
merged_list = solution.mergeTwoLists(list1, list2)

print("Merged Sorted List:")
print_list(merged_list)
