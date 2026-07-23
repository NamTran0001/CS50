import cs50

text = cs50.get_string("Text: ")
letters = 0
words = 1
sentences = 0

for c in text:
    if c.isalpha():
        letters += 1

for c in text:
    if c == " ":
        words += 1

for c in text:
    if c == '.' or c == '!' or c == '?':
        sentences += 1
L = letters * 100 / words
S = sentences * 100 / words
grade = round(0.0588 * L - 0.296 * S - 15.8)
if (grade < 1):
    print("Before Grade 1")
elif (grade <= 16):
    print("Grade", grade)
else:
    print("Grade 16+")
