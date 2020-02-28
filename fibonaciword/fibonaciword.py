
def fibonaciword(n):
    if n == 0:
        return '0';
    if n==1 :
        return '1'
    
    if n>1:
        return fibonaciword(n-1) + fibonaciword(n-2)


def count(a, pattern):
    len_pattern = len(pattern)
    # print(len(a))
    count = 0
    for i in range(len(a)-len_pattern +1):
        if a[i:i+len_pattern] == pattern:
            # print(i)
            count +=1
    return count

if __name__ == '__main__':
    n = int(input())
    pattern = input()
    a = fibonaciword(n)
    print(count(a, pattern))
