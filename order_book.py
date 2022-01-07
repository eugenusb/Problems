class Order:
	def __init__(self, is_buy, qty, price):
		self.is_buy = is_buy
		self.qty = qty
		self.price = price

	def __repr__(self):
		return '{} {}@${:.1f}'.format(
			'buy' if self.is_buy else 'sell',
			self.qty,
			self.price)
	
	def __gt__(self, other):
		return self.price > other.price

class OrderBook:
	def __init__(self):
		self._buy_orders = []
		self._sell_orders = []

	def __enter__(self):
		return self

	def __exit__(self, *args):
		'''
		formats and prints the order book as the test cases expect
		'''
		#buys, sells = self._split_into_buy_and_sell_orders()
		buys, sells = self._buy_orders, self._sell_orders
		buys = sorted(buys)
		sells = sorted(sells)
		for o in [*buys, *sells]:
			print(o)

	def _split_into_buy_and_sell_orders(self):
		'''
		splits orders into buy and sell orders.
		returns a pair of iterables:
		first iterable points to the first buy order.
		second points to the first sell order.
		'''
		from itertools import tee, filterfalse
		is_buy = lambda o: o.is_buy
		buys, sells = tee(self._orders)
		return filter(is_buy, buys), filterfalse(is_buy, sells)


	def add(self, order):
		'''
		checks the opposing side's available orders.
		for a buy order, look at existing sell orders, and vice versa.
		if a trade is possible, update the order book accordingly.
		otherwise, insert the order into the book.
		'''
		other = self._find_trade(order)
		if other:			
			qty_order = order.qty
			qty_other = other.qty
			
			if other.is_buy:
				self._buy_orders.remove(other)
			else:
				self._sell_orders.remove(other)
		
			if qty_order != qty_other:
				if qty_order < qty_other:
					residual_order = Order(other.is_buy, qty_other - qty_order, other.price)
				else:
					residual_order = Order(order.is_buy, qty_order - qty_other, order.price)
				self.add(residual_order)            
		else:
			if order.is_buy:
				merge_order = None
				for o in self._buy_orders:
					if o.price == order.price:
						merge_order = o
						break

				if merge_order:
					order.qty += merge_order.qty
					order.price += merge_order.price
					self._buy_orders.remove(merge_order)

				self._buy_orders.append(order)
			else:
				merge_order = None
				for o in self._sell_orders:
					if o.price == order.price:
						merge_order = o
						break
				
				if merge_order:
					order.qty += merge_order.qty
					order.price += merge_order.price
					self._sell_orders.remove(merge_order)
					
				self._sell_orders.append(order)


	def _find_trade(self, order):
		'''
		returns an order for the best "match" for a give order.
		for buy orders, this would be the lowest sell price.
		for sell orders,the highest buy price.
		if no orders meet the criteria, return None.
		'''

		ret = None
		if order.is_buy:
			# Check sell orders
			i = 0
			best_sell = -1
			while i < len(self._sell_orders):
				if order.price >= self._sell_orders[i].price:
					if best_sell == -1 or self._sell_orders[i].price < self._sell_orders[best_sell].price:
						best_sell = i
				i += 1
			if best_sell != -1:
				ret = self._sell_orders[best_sell]
		else:
			# Check buy orders
			i = 0
			best_buy = -1
			while i < len(self._buy_orders):
				if order.price <= self._buy_orders[i].price:
					if best_buy == -1 or self._buy_orders[i].price > self._buy_orders[best_buy].price:
						best_buy = i
				i += 1

			if best_buy != -1:
				ret = self._buy_orders[best_buy]
			
		return ret
			
def parse(order_book = OrderBook()):
	while True:
		line = input().strip().split()		
		if line[0] == 'end':
			break

		is_buy = line[0] == 'buy'
		qty, price = line[1:]
		qty, price = int(qty), float(price)
		order_book.add(Order(is_buy, qty, price))

	return order_book

with OrderBook() as order_book:
	parse(order_book)	

	order_book.add(Order(True, 10, 11.0))