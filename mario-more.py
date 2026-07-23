
while(True):
    try:
        h = int(input("Height: "))
        if 1 <= h <= 8:
            break
    except ValueError:
        pass

for i in range(h):
    for j in range(2 * h + 2):
        if j > h + i + 2:
            break
        if j == h or j == h + 1 or j - i > h + 2 or i + j + 1 < h:
            print(" ",end="");
        else:
            print("#",end="");
    print();
