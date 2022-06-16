/*
	题意：作为国王的统治者，你有一支巫师军队听你指挥。
	给你一个下标从 0 开始的整数数组 strength ，其中 strength[i] 表示第 i 位巫师的力量值。对于连续的一组巫师（也就是这些巫师的力量值是 strength 的 子数组），总力量 定义为以下两个值的 乘积 ：
	巫师中 最弱 的能力值。
	组中所有巫师的个人力量值 之和 。
	请你返回 所有 巫师组的 总 力量之和。由于答案可能很大，请将答案对 109 + 7 取余 后返回。
	子数组 是一个数组里 非空 连续子序列。

	题解：前缀和的前缀和+单调栈分别处理区间和以及最小值，我们思考某个元素对于总的结果的影响，我们先处理左边的最小值，再处理右边的最小值
	我们思考，对于某个元素arr[i]来说，其对于区间[L,R]内的子数组的和的影响为
	∑r=[i+1,R+1]∑l=[L,i](s[r]-s[l])=(i-L+1)∑r=[i+1,R+1](s[r])-(R-i+1)∑l=[L,i](s[l])
	因此我们还要计算出前缀和的前缀和，来简化这个子数组的影响
	令ss为前缀和的前缀和，那么上述式子可以改写为
	(i-L+1)*(ss[R+2]-ss[i+1])+(R-i+1)*(ss[i+1]-ss[L])
	最后的解就是把每个元素的影响加起来乘上对应的最小值即可
*/
package main

func totalStrength(strength []int) int {
	const MOD int = 1e9 + 7
	var n int = len(strength)
	left := make([]int, n)
	right := make([]int, n)
	for i := range right {
		right[i] = n
	}
	st := []int{}
	for i, v := range strength {
		for len(st) > 0 && strength[st[len(st)-1]] >= v {
			right[st[len(st)-1]] = i
			st = st[:len(st)-1]
		}
		if len(st) > 0 {
			left[i] = st[len(st)-1] //由于单调栈内存的是一个严格递增的序列，所以栈顶元素就是left[i]
		} else {
			left[i] = -1
		}
		st = append(st, i)
	}
	prefix := 0
	pprefix := make([]int, n+2)
	for i, v := range strength {
		prefix += v
		pprefix[i+2] = (pprefix[i+1] + prefix) % MOD //前缀和的前缀和由于s[1]才开始有值，所以下标需要从2开始
	}
	//自此预处理完成了，开始计算
	ans := 0
	for i, v := range strength {
		l, r := left[i]+1, right[i]-1 //记得加1，-1，用{1,2,3,1}这个数组元素2来方便理解
		tot := ((i-l+1)*(pprefix[r+2]-pprefix[i+1]) - (r-i+1)*(pprefix[i+1]-pprefix[l])) % MOD
		ans = (ans + v*tot) % MOD
	}
	return (ans + MOD) % MOD
}
