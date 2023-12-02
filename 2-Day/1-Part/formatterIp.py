from collections import defaultdict
import re

order = ['green', 'red', 'blue']

with open('formatted_input', 'w') as f:
    with open('input', 'r') as r:
        for line in r.readlines():
            f.write("NEXT\n")
            game_details, rest = line.split(':')
            game_id = game_details.split()[1]

            round_details = rest.split(';')

            f.write(f'{game_id} {len(round_details)}\n')
            for round in round_details:
                d = defaultdict(lambda : 0)
                cubes = round.split(',')

                for cube in cubes:
                    count, color = cube.strip().split()
                    d[color] = int(count)
                for color in order:
                    f.write(f'{d[color]} ')
                f.write('\n')