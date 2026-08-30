def binary_search(find,a):
    i=0
    j=len(a)
    if(j==0):
        return "we can't search in zero length array"
    while(i<j):
        mid=i+(j-i)//2
        if(a[mid]==find):
            return mid
        elif(a[mid]>find):
            j-=1
        else:
            i+=1
    return "number not found"

a=[1,2,3,4,100]
find=int(input("enter you number  "))
print(binary_search(find,a))