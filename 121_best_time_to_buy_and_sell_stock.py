import math


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0

        maxProfit = 0
        minPurchase = prices[0]
        for price in prices:
            curProfit = price - minPurchase
            if curProfit > maxProfit:
                maxProfit = curProfit
            if price < minPurchase:
                minPurchase = price
        return maxProfit
