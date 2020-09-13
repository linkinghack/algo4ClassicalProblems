import "math"

/* 有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。
注意，不是必须有这些素因子，而是必须不包含其他的素因子。
例如，前几个数按顺序应该是 1，3，5，7，9，15，21。 */

// 这样的数满足 num = 3a * 5b * 7c
// 寻找a,b,c的合集组合

// 求第k小，从 1 开始，本数列内的数依次乘3,5,7，产生的数属于此数列，且从小到大排列

func getKthMagicNumber(k int) int {
	var p3, p5, p7 int
	products := make([]int, k)
	products[0] = 1

	for i := 1; i < k; i++ {
		products[i] = int(math.Min(float64(products[p3]*3), math.Min(float64(products[p5]*5), float64(products[p7]*7))))
		if products[i] == products[p3]*3 {
			p3++
		}
		if products[i] == products[p5]*5 {
			p5++
		}
		if products[i] == products[p7]*7 {
			p7++
		}
	}
	return products[k-1]
}