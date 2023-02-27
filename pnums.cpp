#include <iostream>
#include <cmath>

bool p_number(int number);
int getTotal(int number);

using namespace std;
 
/*
    I'm going call a positive integer whose digits add up to a prime number a "p-number". So 124 would be a p-number (1+2+4=7, a prime),
    832 is a p-number (8+3+2=13, a prime), etc. Numbers might be prime themselves, but not be p-numbers (like 31 -- 3+1=4, not a prime).
*/
 
int main()
{
    int count = 0;
 
    for (int x = 1; x <= 1000000; x++)
    {
        if (p_number(x)) {
            count++;
        }
    }
    cout << "Count: " << count << endl;
}
 
bool p_number(int number)
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    int total = getTotal(number);
    for (int p =0; p < size(primes); p++) {
        if (total == primes[p]) {
            return true;
        }
    }
    return false;
}

int getTotal(int n)
{
    int digitsum = 0;
    int place = log10((double)n);
    while (place >= 0) {
        int placeval = pow(10, place);
        int digit = n / placeval;
        digitsum += digit;
        n -= (digit * placeval);
        place--;
    }
    return digitsum;
}
