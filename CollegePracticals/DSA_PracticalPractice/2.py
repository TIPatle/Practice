def insert(a):

    n = int(input("Enter the number of element to add :- "))
    
    for i in range(n):
        a.add((int(input("Enter the element :- "))))

    return

def search(a, key):

    for i in a:
        if ( i == key ):
            return 1

    return 0

def union(a, b):

    c = set()

    for i in a:
        c.add(i)

    for i in b:
        if ( search(a, i) == 0 ):
            c.add(i)

    return c


def intersection(a, b):

    c = set()

    for i in a:
        if ( search(b, i) ):
            c.add(i)

    return c

def coutelement( a ):

    for i in a:
        print(i, end=" ")

    print()

    return

a = set ()
b = set ()

print("Set A ")
insert(a)
coutelement(a)

print("Set B")
insert(b)
coutelement(b)

print("Union of two Set A & Set B is :- ")
coutelement(union(a, b))

print("Intersection of Set A & Set B is :- ")
coutelement( intersection(a, b) )
