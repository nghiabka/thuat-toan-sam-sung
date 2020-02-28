import numpy as np

def quickSort(a):
    """
    chon phan dau lam pivot
    """
    if len(a) < 2:
        return a
    else:
        pivot = 0
        tmp =[a[pivot]]
        less = [i for i in a[1:] if i <= a[pivot]]
        greater = [i for i in a[1:] if i > a[pivot]]
        return quickSort(less) + tmp + quickSort(greater)


def quickSort2(a):
    """
    chon phan tu giua
    """
    if len(a) < 2 :
        return a 
    else:
        pivot = a[int(len(a)/2)]
        print(pivot)
        tmp = [pivot]
        less = [ i for i in a[:] if i <= pivot]
        greater = [i for i in a[:] if i > pivot]
        return quickSort2(less) + tmp + quickSort2(greater)




if __name__ == '__main__':
    a = [1, 4, 6, 2, 10, 34]
    print(quickSort2(a))

    