/*
   题意:在大小为 n x n 的网格 grid 上，每个单元格都有一盏灯，最初灯都处于 关闭 状态。

       给你一个由灯的位置组成的二维数组 lamps ，其中 lamps[i] = [rowi, coli] 表示 打开 位于 grid[rowi][coli] 的灯。即便同一盏灯可能在 lamps 中多次列出，不会影响这盏灯处于 打开 状态。

       当一盏灯处于打开状态，它将会照亮 自身所在单元格 以及同一 行 、同一 列 和两条 对角线 上的 所有其他单元格 。

       另给你一个二维数组 queries ，其中 queries[j] = [rowj, colj] 。对于第 j 个查询，如果单元格 [rowj, colj] 是被照亮的，则查询结果为 1 ，否则为 0 。在第 j 次查询之后 [按照查询的顺序] ，关闭 位于单元格 grid[rowj][colj] 上及相邻 8 个方向上（与单元格 grid[rowi][coli] 共享角或边）的任何灯。

       返回一个整数数组 ans 作为答案， ans[j] 应等于第 j 次查询 queries[j] 的结果，1 表示照亮，0 表示未照亮。

   题解:两条对角线分别为x+y和x-y，注意存pair的擦耦哦

*/
package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func tallestBillboard(rods []int) int {
	n := len(rods)
	sum := 0
	for _, v := range rods {
		sum += v
	}
	dp := make([]int, sum+1)
	for i := 0; i <= sum; i++ {
		dp[i] = 0
	}
	for i := 0; i < n; i++ {
		tmp := []int{}           //这里不能写成tmp:=dp不然共享了内存空间
		tmp = append(tmp, dp...) //记得这样弄，才能够避免直接饮用
		for j := 0; j <= sum; j++ {
			if dp[j] < j {
				continue
			} //高度差为j的时候至少长度为j
			k := j + rods[i] //加到比较长的那一根去
			if k <= sum {
				tmp[k] = max(tmp[k], dp[j]+rods[i])
			}
			if j > rods[i] {
				k = j - rods[i]
			} else {
				k = rods[i] - j
			}
			//加到短的一侧去
			tmp[k] = max(tmp[k], dp[j]+rods[i])
		}
		dp, tmp = tmp, dp
	}
	return dp[0] / 2
}
func main() {
	a := []int{2, 4, 8, 16}
	tallestBillboard(a)
}
