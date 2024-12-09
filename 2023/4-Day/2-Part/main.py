from collections import defaultdict

def prefix_sum(total):
    nums = total[:]
    for i in range(1, len(total)): nums[i] += nums[i-1]
    return nums

with open('input', 'r') as r:
    inp = r.read().split('\n')
    total = [1 for _ in range(len(inp) + 1)]
    extra = [0 for _ in range(len(inp) + 1)]
    count, extra_copies = 0, 0

    for line in inp:
        extra_copies += extra[count]
        left, right = line.split('|')
        winning_cards = set(map(int, left.split(':')[1].split()))
        won = 0
        for num in right.split():
            if int(num) in winning_cards:
                won += 1
        
        if won:
            extra[count + 1] += total[count] * (extra_copies + 1)
            if count + 1 + won < len(extra): extra[won + count + 1] -= total[count] * (1 + extra_copies)
        
        total[count] += extra_copies

        count += 1
    print(sum(total[:-1]))