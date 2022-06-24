/*
	题意：给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
		设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
		注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

	题解：dpp表示在第i天，已经进行了j次交易，且有股票的最大利润，dpp[i][j]表示在第i天，已经进行了j次交易，且持有股票
	的最大利润
		dps[i][j]表示在第i天，且已经进行了j次交易，并且不持有股票的收益
		则dpp[i][j]=max(dpp[i-1][j],dps[i-1][j]-price[i])（扣除买入花费）
		dps[i][j]=max(dpp[i-1][j-1]+price[i],dps[i-1][j])
		我们设置一下边界条件：
			dpp[0][1-k]我们设置为一个很小很小的值，表示花了钱买入了股票
			dps[0][1-k]我们设置为很小的值，表示非法状态
			dpp[0][0]=-price[0]表示买入了第0股
			dps[0][0]=0表示啥都没做
		另外，这题可以用滚动数组进行优化，我们注意到dpp[i][j]和dps[i][j]都由dpp[i-1][...]和dps[i-1][...]转移过来，所以我们可以
		抽象为一个p数组和一个s数组来进行计算，这样的话，我们的转移方程如下所示
		dpp[i][j]=p[j]=max(p[j-1],s[j]-prices[i])
		dps[i][j]=s[j]=max(s[j],p[j-1]+prices[i])
		但是如果我们先更新p再更新s，那么在更新s的时候，我们的p[j-1]已经被更新过了，那么这样是否还是正确的呢？

*/
package problem

import "math"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func max_element(a ...int) int { //牢记golang传数组的方式
	ans := 0
	for _, v := range a {
		if v > ans {
			ans = v
		}
	}
	return ans
}
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
func maxProfit(k int, prices []int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}
	dpp := make([][]int, n)
	dps := make([][]int, n)
	k = min(k, n/2)
	for i := range dpp {
		dpp[i] = make([]int, k+1)
		dps[i] = make([]int, k+1)
	}
	dpp[0][0] = -prices[0]
	for i := 1; i <= k; i++ {
		dpp[0][i] = math.MinInt64 / 2
		dps[0][i] = math.MinInt64 / 2
	}
	for i := 1; i < n; i++ {
		dpp[i][0] = max(dpp[i-1][0], dps[i-1][0]-prices[i])
		for j := 1; j <= k; j++ {
			dpp[i][j] = max(dpp[i-1][j], dps[i-1][j]-prices[i]) //由于dps表示的是不持有股票的状态，所以这里不用dps[i-1][j-1]
			dps[i][j] = max(dpp[i-1][j-1]+prices[i], dps[i-1][j])
		}
	}
	return max_element(dps[n-1]...)
}
func maxProfit2(k int, prices []int) int {
	n := len(prices)
	if n <= 0 {
		return 0
	}
	p := make([]int, k+1)
	s := make([]int, k+1)
	for i := 1; i <= k; i++ {
		p[i] = math.MinInt64 / 2
		s[i] = math.MinInt64 / 2
	}
	s[0] = 0
	p[0] = -prices[0]
	for i := 1; i <= k; i++ {
		p[0] = max(p[0], s[0]-prices[i])
		p[i] = max(p[i], s[i]-prices[i])
		s[i] = max(s[i], p[i-1]+prices[i])
	}
	return max_element(s...)
}
