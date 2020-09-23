/*
 * @lc app=leetcode.cn id=874 lang=golang
 *
 * [874] 模拟行走机器人
 */
package LeetCode

// @lc code=start
const (
	TURN_LEFT  = -2
	TURN_RIGHT = -1
)

type Coordinate struct {
	x int
	y int
}

func robotSim(commands []int, obstacles [][]int) int {
	// 上右下左分方向步长定义
	dx := []int{0, 1, 0, -1}
	dy := []int{1, 0, -1, 0}

	// 障碍坐标map,以支持查询
	hasObstacle := map[Coordinate]bool{}
	for _, obs := range obstacles {
		hasObstacle[Coordinate{x: obs[0], y: obs[1]}] = true
	}

	distMax := 0
	currentDirection := 0
	x, y := 0, 0
	for _, command := range commands {
		if command == TURN_LEFT {
			currentDirection += 3
			currentDirection %= 4
		} else if command == TURN_RIGHT {
			currentDirection += 1
			currentDirection %= 4
		} else {
			// step by step
			for ; command > 0; command-- {
				attemptX := x + dx[currentDirection]
				attemptY := y + dy[currentDirection]
				if _, exist := hasObstacle[Coordinate{attemptX, attemptY}]; !exist {
					x = attemptX
					y = attemptY
					if x*x+y*y > distMax {
						distMax = x*x + y*y
					}
				}
			}
		}
	}

	return distMax
}

// @lc code=end
