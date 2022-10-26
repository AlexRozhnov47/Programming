import numpy as np

def Initial():
	'' 'Определите вес, стоимость и общий вес рюкзака' ''
	option = input('Использовать ли данные по умолчанию (Да / Нет):')
	if option == 'Y':
		weight = [35, 30, 60, 50, 40, 10, 25]
		price = [10, 40, 30, 50, 35, 40, 30]
		C = 150
	else:
		weight = list(map(int, input("Пожалуйста, введите вес предмета через пробел:").split( )))
		price = list(map(int, input("Введите соответствующее значение элемента, разделенное пробелами:").split( )))
		C = int(input("«Пожалуйста, введите общий предел веса рюкзака:»"))
	item = list(zip(weight,price))
	print('Вес, значение:' + item.__str__() + '\ nПредел общего веса:' + C.__str__())
	return item, C


def Weight(item):
	'' 'Выберите предмет наименьшего веса' ''
	data = np.array(item)
	idex = np.lexsort([-1*data[:,1], data[:,0]])
	return idex

def Price(item):
	'' 'Выбери самый ценный предмет' ''	
	data = np.array(item)
	idex = np.lexsort([data[:,0], -1*data[:,1]])
	return idex

def Density(item):
	'' 'Выберите элемент с наибольшей плотностью значений' ''
	number = len(item)
	data = np.array(item)
	data_list = [0] * number
	for i in range(number):
		data_list[i] = (data[i,1])/(data[i,0])
	data_set = np.array(data_list)
	idex = np.argsort(-1*data_set)
	return idex
def GreedyAlgo(item, C, idex):
	'''как поживаешь'''
	number = len(item)
	status = [0] * number
	total_weight = 0
	total_value = 0
	for i in range(number):
		if item[idex[i],0] <= C:
			total_weight += item[idex[i],0]
			total_value += item[idex[i],1]
			status[idex[i]] = 1
			C -= item[idex[i],0]
		else:
			continue
	return total_weight, total_value, status
def Compare(total_value1, total_value2, total_value3):
	'' 'Сравните три результата' ''
	values = zip(total_value1, total_value2, total_value3)
	data = np.array([total_value1[1], total_value2[1], total_value3[1]])
	idex = np.argsort(data)
	value = list(zip(*values))
	results = list(value[idex[2]])
	return results

def main():
	'' 'основная структура' ''
	item0, C = Initial()
	item = np.array(item0)
	idex_weight = Weight(item)
	idex_price = Price(item)
	idex_Density = Density(item)
	results_weight = GreedyAlgo(item, C, idex_weight)
	print(results_weight)
	results_Price = GreedyAlgo(item, C, idex_price)
	print(results_Price)
	results_Density = GreedyAlgo(item, C, idex_Density)
	print(results_Density)
	results = Compare(results_weight, results_Price, results_Density)
	print(results)
main()
