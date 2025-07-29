import functools
import sys
sys.setrecursionlimit(1_000_000)

testScenarios = int(input())

for _ in range(testScenarios):
    numberOfDistances = int(input())
    distances = [int(x) for x in input().split()]

    @functools.cache
    def solve(index, currentHeight):
        if index == numberOfDistances:
            if currentHeight == 0:
                return (0, '')
            else:
                return (float('inf'), '')

        UH, UP = solve(index + 1, currentHeight + distances[index])
        UH = max(UH, currentHeight + distances[index])
        DH, DP = (float('inf'), '')
        if currentHeight - distances[index] >= 0:
            DH, DP = solve(index + 1, currentHeight - distances[index])
            DH = max(DH, currentHeight)

        return min((UH, 'U' + UP), (DH, 'D' + DP))

    smallestMaxHeight, path = solve(0, 0)
    if smallestMaxHeight == float('inf'):
        print('IMPOSSIBLE')
    else:
        print(path)

    solve.cache_clear()