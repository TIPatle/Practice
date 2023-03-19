#Declaring a set
A = {1, 2, 3, 4, 5, 6}
B = {6, 7, 8, 9, 0}

print ("Set A :- ", A )
print ("Set B :- ", B )

C = A.union(B)
print("Union Set A and Set B :- ", C)

D = A.intersection(B)
print("Intersection A and B :- ", D)

# Adding New Element 
print("Adding 45 in Set A..")
A.add(45) 
print("New Set A :- ", A)

#Removing Element 
print("Removing 0 from Set B..")
B.remove(0)
print("New Set B :- ", B)



#size of Set A
size = 0
for i in A:
    size+=1

print("Size of Set A :- ", size)

#Checking element is in Set A
print("Checking 3 is in Set A :- ", 3 in A )

#creating Subset of A
subA = set(list(A)[2:4])
ans = True
for i in subA:
    ans &= i in A
print ("Do ", subA, " is subset of ", A, " :- ", ans  )