class Item:
    def __init__ (self, weight, value):
        self.weight = int(weight)
        self.value = int(value)

if __name__ == "__main__":
    capacity = input('Enter knapsack capacity: ')
    capacity = int(capacity)
    n_items = input('Enter number of items: ')
    n_items = int(n_items)
    list_items = []
    for i in range(n_items):
        print("For item", i, end = " ")
        temp_weight, temp_value = input("Enter weight and value as space saparated input: ").split()
        temp_item = Item(temp_weight, temp_value)
        list_items.append(temp_item)
    

    k_table = [[0 for i in range(capacity + 1)] for j in range(n_items + 1)]
    for i in range(n_items + 1):
        k_table[i][0] = 0
    
    for j in range(capacity + 1):
        k_table[0][j] = 0
    
    for i2 in range(1, len(list_items) + 1):
        for j2 in range(1, capacity+1):
            if(list_items[i2 - 1].weight <= j2):
                q = list_items[i2-1].value + k_table[i2-1][j2-list_items[i2-1].weight]
                if(q > k_table[i2 - 1][j2]):
                    k_table[i2][j2] =  q
                else:
                    k_table[i2][j2] = k_table[i2 - 1][j2]
            else:
                k_table[i2][j2] = k_table[i2 - 1][j2]
                
                
    for i in range(n_items + 1):
        for j in range(capacity +1):
            print(k_table[i][j], end = " ")
        print()
        
        
    i = len(list_items)
    k = capacity
    while (i>0 and k>0):
        if(k_table[i][k] != k_table[i - 1][k]):
            print('Item', i, "is taken")
            i = i - 1
            k = k - list_items[i].weight
        else:
            i = i - 1     
    
    print("The profit is", k_table[n_items][capacity])    
    