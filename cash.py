import cs50
while (True):
    try:
        cash = cs50.get_float("Change: ")
        if cash > 0:
            break
    except ValueError:
        pass
cash = round(cash * 100)
res = 0
while (cash >= 25):
    cash -= 25
    res += 1
while (cash >= 10):
    cash -= 10
    res += 1
while (cash >= 5):
    cash -= 5
    res += 1
while (cash >= 1):
    cash -= 1
    res += 1
print(res)
