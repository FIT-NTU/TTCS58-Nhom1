import os


def inputFile(path):
    f = open(path, 'r')
    arr = f.readline().split(',')
    f.close()
    arr = list(map(int, arr))
    return arr

# Kiem tra xem co phai la 1 so nguyen hay la chuoi


def isInt(i):
    try:
        i = int(i)
        return True
    except:
        return False


def inputIsIntInRange(x, s, f=0, l=0):
    while True:
        x = input(s)
        try:
            x = int(x)
            if f == 0 and l == 0:
                return x

            if x in range(f, l + 1):
                return x
            else:
                print("So phai tu {} den {}".format(f, l))
        except:
            print("Phai nhap 1 so")

# Nhap vao mang arr voi n phan tu
def inputArr(arr, n):
    temp = 0
    for i in range(n):
        while True:
            temp = input("A[{}] = ".format(i))
            if isInt(temp):
                temp = int(temp)
                break
            else:
                print("Hay nhap 1 so. Nhap lai!")
        arr.append(temp)

# Xuat cac gia tri arr ra man hinh


def outputArr(arr):
    for i, x in enumerate(arr):
        print("A[{}] = {}".format(i, x))

# Sap xep day so tang dan


def sortArr(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(i + 1, n):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]     # Hoan vi 2 gia tri

# Tim kiem nhi phan
# arr phai duoc sap xep truoc


def binarySearch(arr, l, r, x):
    if r >= l:
        mid = int(l + (r - l)/2)
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binarySearch(arr, l, mid - 1, x)
        else:
            return binarySearch(arr, mid + 1, r, x)
    else:
        return -1


def searchSum(arr):
    max_tam = 0
    max_tong = 0
    for i in range(len(arr)):
        max_tam = max_tam + arr[i]
        if max_tam <= 0:
            max_tam = 0
        else:
            if max_tong < max_tam:
                max_tong = max_tam

    print("Tong: {}".format(max_tong))


def menu():
    print('1. Nhap mang')
    print('2. Nhap mang tu file')
    print('3. Tim kiem nhi phan')
    print('4. Tong lon nhat cac phan tu lien tiep nhau')
    print('5. Xuat ra mang')
    print('6. Thoat')


def select(arr):
    menu()
    temp, temp2 = 0, 0
    temp = inputIsIntInRange(temp, "Ban chon: ", 1, 6)
    if temp == 1:
        temp2 = inputIsIntInRange(temp2, "Nhap so luong phan tu muon nhap: ")
        os.system('cls')
        inputArr(arr, temp2)
        print("Da nhap thanh cong")
        select(arr)
    elif temp == 2:
        arr = inputFile('input2.txt')
        os.system('cls')
        print("Da nhap tu file thanh cong")
        select(arr)
    elif temp == 3:
        temp2 = inputIsIntInRange(temp2, "Nhap so can tim: ")
        os.system("cls")
        sortArr(arr)
        temp3 = binarySearch(arr, 0, len(arr), temp2)
        if temp3 == -1:
            print("Khong co so nay trong mang!")
        else:
            print("Vi tri: {}".format(temp3))
        select(arr)
    elif temp == 4:
        os.system('cls')
        searchSum(arr)
        select(arr)
    elif temp == 5:
        os.system('cls')
        outputArr(arr)
        select(arr)
    elif temp == 6:
        return


def main():
    arr = []
    select(arr)


if __name__ == "__main__":
    main()
