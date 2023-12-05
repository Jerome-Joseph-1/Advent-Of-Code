from collections import defaultdict

with open('input', 'r') as r:
    total = 0
    for line in r.readlines():
        left, right = line.split('|')
        winning_cards = set(map(int, left.split(':')[1].split()))
        ans = 0
        for num in right.split():
            if int(num) in winning_cards:
                if ans != 0: ans <<= 1
                else : ans = 1
        total += ans
    print(total)