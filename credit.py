import cs50

while True:
    number = cs50.get_string("Number: ")
    if number.isdigit():
        break
rev = number[::-1]
length = len(number)
first = int(number[0])
first2 = int(number[:2])
total = 0
for i in range(len(rev)):
    digit = int(rev[i])
    if i % 2 == 0:
        total += digit
    else:
        digit *= 2
        if digit > 9:
            digit -= 9
        total += digit
if total % 10 != 0:
    print("INVALID")
if length == 15 and (first2 == 34 or first2 == 37):
    print("AMEX")
elif length == 16 and 51 <= first2 <= 55:
    print("MASTERCARD")
elif (length == 13 or length == 16) and first == 4:
    print("VISA")
else:
    print("INVALID")
