/*
题意：你正在安装一个广告牌，并希望它高度最大。这块广告牌将有两个钢制支架，两边各一个。每个钢支架的高度必须相等。

你有一堆可以焊接在一起的钢筋 rods。举个例子，如果钢筋的长度为 1、2 和 3，则可以将它们焊接在一起形成长度为 6 的支架。

返回 广告牌的最大可能安装高度 。如果没法安装广告牌，请返回 0 。
题解：dp[i][j]表示前i根钢筋组成的两个框架高度差为j的时候的最大加和，由于dp[i]仅和dp[i-1]有关，所以直接用一维数组dp[j]表示
*/
package problem

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
