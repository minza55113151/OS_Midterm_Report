import time

FILE_NAME = 'array.txt'

def init():
    array = [i for i in range(1000000)]
    with open(FILE_NAME, 'w') as f:
        for i in array:
            f.write(str(i) + '\n')
    return array

def average_with_io():
    summ = 0
    array = []
    with open(FILE_NAME, 'r') as f:
        for line in f:
            array.append(int(line))
    n = len(array)
    
    for i in range(n):
        if i % (n/10) == 0:
            print(f'Progress: {i / n * 100:.2f} %')
        summ += array[i]
    
    print('Progress: 100.00 %')
    
    return summ / n

def average_without_io(array: list[int]):
    summ = 0
    n = len(array)
    
    for i in range(n):
        summ += array[i]
    
    return summ / n

def main():
    array = init()
    
    t1 = time.time()
    res1 = average_with_io()
    t2 = time.time()
    print(f'Average with I/O: {t2-t1:.2f} seconds')
    
    t1 = time.time()
    res2 = average_without_io(array)
    t2 = time.time()
    print(f'Average without I/O: {t2-t1:.2f} seconds')
    
    print('Average with I/O: ', res1)
    print('Average without I/O: ', res2)
    
    return 0


if __name__ == '__main__':
    main()