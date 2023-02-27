import math

def digit_sum(n):
    digitsum = 0
    place = int(math.log10(n))
    while (place >= 0):
        digit = n // 10 ** place        
        digitsum += digit
        n -= digit * 10 ** place
        place -= 1
    return digitsum

def count_pnums_in_interval(toval, fromval=1):
    primelist = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]
    cnt = 0
    for i in range(fromval, toval + 1):
        if digit_sum(i) in primelist:
            cnt += 1
    return cnt

def main():
    print (f'Number of p-numbers in the range 1-1M is {count_pnums_in_interval(1000000)}')

if __name__ == "__main__":
    main()
