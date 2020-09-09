type ListNode struct {
	Val  int
	Next *ListNode
}

/* func reversePrint(head *ListNode) []int {
	result := []int{}
	stack := list.New()
	for head != nil {
		stack.PushBack(head.Val)
		head = head.Next
	}

	for stack.Len() > 0 {
		elem := stack.Back()
		stack.Remove(elem)
		result = append(result, elem.Value.(int))
	}

	return result
} */

func reversePrint(head *ListNode) []int {
	result := []int{}
	temp := []int{}

	for head != nil {
		temp = append(temp, head.Val)
		head = head.Next
	}

	for i := 1; i <= len(temp); i++ {
		result = append(result, temp[len(temp)-i])
	}

	return result
}