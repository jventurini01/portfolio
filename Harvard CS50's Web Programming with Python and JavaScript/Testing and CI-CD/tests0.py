from prime import isPrime

def testPrime(n, expected):
    if isPrime(n) != expected:
        print(f"Error on isPrime({n}), expected {expected}")