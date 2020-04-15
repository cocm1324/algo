def mp(prices):
	if (len(prices) == 0):
		return 0
	profit = 0
	put = prices[0]
	exp_profit = 0
	for price in prices:
		print(price - put, exp_profit)
		if (price < put + exp_profit):
			profit += exp_profit
			put = price
			exp_profit = 0
		else:
			exp_profit = price - put
	profit += exp_profit
	return profit

a = [7, 6, 3, 2, 1]
r = mp(a)
print(r)
