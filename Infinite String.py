# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

def solve():
    b = get_number()
    X = get_number()
    if(b == 1):
        print('a')
        return
    elif(X < b):
        print(chr(ord('a') + X))
        return
    x = 1
    k = 1
    while(True): 
        x*=b
        if(x*k > X): 
            break;
        X -= x*k;
        k+=1

    order = X//k;
    x//=b;
    cnt = X%k
    while(x > 0):
        if(cnt == 0):
            print(chr(order//x + ord('a')));
            return;
        order%=x;
        x//=b;
        cnt -= 1

t = get_number();
for i in range(t): 
    solve();
