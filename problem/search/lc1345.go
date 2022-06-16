/*
   题意:给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。
       每一步，你可以从下标 i 跳到下标 i + 1 、i - 1 或者 j ：
       i + 1 需满足：i + 1 < arr.length
       i - 1 需满足：i - 1 >= 0
       j 需满足：arr[i] == arr[j] 且 i != j
       请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。
   题解：
       这题不能用dp，因为不满足dp“无后效性”的原则！因为你dp[i+1]和dp[i-1]是dp[i]的依赖项，但是你dp[i+1]又依赖于dp[i]，所以不满足
       无后效性的性质，因此本题只能用广搜
       但是直接广搜会超时，这是因为我们把权值相同的节点集合中的每条边都搜索了一遍，但是这样是不必要的，当我们访问到了这个子图的某一个节点的时候
       就等于访问到了所有节点，因为我们可以跳到这些节点
*/
package main

func minJumps(arr []int) int {
	n := len(arr)
	G := map[int][]int{} //存权值相同的子图
	for i, v := range arr {
		G[v] = append(G[v], i)
	}
	vis := map[int]bool{0: true}
	type pair struct{ idx, step int }
	q := []pair{{}}
	for {
		p := q[0]
		q = q[1:]
		if p.idx == n-1 {
			return p.step
		}
		for _, j := range G[arr[p.idx]] {
			if !vis[j] { //没有访问，把这个子图的所有节点置为true
				vis[j] = true
				q = append(q, pair{j, p.step + 1})
			}
		}
		delete(G, arr[p.idx])
		if !vis[p.idx+1] {
			vis[p.idx+1] = true
			q = append(q, pair{p.idx + 1, p.step + 1})
		}
		if p.idx >= 1 && !vis[p.idx-1] {
			vis[p.idx-1] = true
			q = append(q, pair{p.idx - 1, p.step + 1})
		}
	}
}
