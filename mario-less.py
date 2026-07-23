
while(True):
    try:
        h = int(input("Height: "))
        if 1 <= h <= 8:
            break
    except ValueError:
        pass

for i in range(h):
    for j in range(h):
        if j >= h - i - 1:
            print("#", end="")
        else:
            print(" ", end="")
    print("")
