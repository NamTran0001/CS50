import csv
import sys


def main():

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        people = list(reader)

    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    strs = reader.fieldnames[1:]

    counts = {}
    for s in strs:
        counts[s] = longest_match(sequence, s)

    for person in people:
        match = True
        for s in strs:
            if int(person[s]) != counts[s]:
                match = False
                break
        if match:
            print(person["name"])
            return
        
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0

        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run


main()
