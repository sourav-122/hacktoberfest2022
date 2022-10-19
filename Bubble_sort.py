# Created Bubble Sort using Python 

def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(len(arr)-i):
            temp=arr[j+1]
            arr[j+1]=arr[j]
            arr[j]=temp
    return arr
arr=[9,8,7,6,5,4,32,1]
print("The Array Before Sorting: ")
print(arr)
print("The Array After Sorting : ")
print(bubble_sort(arr))
