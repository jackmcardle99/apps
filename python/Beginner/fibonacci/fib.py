#In this program you can enter the Nth term of a fib sequence and it will give you back the value

def Fib(N):    
    if N == 0:
        return 0
    if N == 1:
        return 1
    return Fib(N-1) + Fib(N-2)

userNth = int(input("Please enter N in fib sequence."))
print(Fib(userNth))