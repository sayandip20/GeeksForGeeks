#User function Template for python3

''' Node for linked list:

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''
class Solution:
    def reverse(self,num):
        prev,curr = None,num
        while curr != None:
            nextNode = curr.next
            curr.next = prev
            prev =curr
            curr = nextNode
        return prev
        
    def remove_zeros(self,num):
        while num and num.data == 0:
            num = num.next
        return num
    
    def addTwoLists(self, num1, num2):
        num1 = self.remove_zeros(num1)
        num2 = self.remove_zeros(num2)
        num1 = self.reverse(num1)
        num2 = self.reverse(num2)
        carry = 0
        sum1 = 0
        result = Node(0)
        ptr = result
        while num1 != None or num2 != None:
            sum1 = 0 + carry
            if num1 != None:
                sum1 += num1.data
                num1 = num1.next
            if num2 != None:
                sum1 += num2.data
                num2 = num2.next
            carry = sum1 // 10
            sum1 = sum1 % 10
            ptr.next = Node(sum1)
            ptr = ptr.next
        if carry == 1:
            ptr.next = Node(1)
        result = self.reverse(result.next)
        return result            


#{ 
 # Driver Code Starts
#Initial Template for Python 3


# Node Class
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


# Linked List Class
class LinkedList:

    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next


# prints the elements of linked list starting with head
def printList(n):
    while n:
        print(n.data, end=' ')
        n = n.next
    print()


if __name__ == '__main__':
    for _ in range(int(input())):

        arr1 = (int(x) for x in input().split())
        num1 = LinkedList()
        for i in arr1:
            num1.insert(i)

        arr2 = (int(x) for x in input().split())
        num2 = LinkedList()
        for i in arr2:
            num2.insert(i)

        res = Solution().addTwoLists(num1.head, num2.head)
        printList(res)
        print("~")

# } Driver Code Ends