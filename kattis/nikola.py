import functools
import sys
sys.setrecursionlimit(1_000_000)

numberOfSquares = int(input())

entryFees = []
for _ in range(numberOfSquares):
    entryFees.append(int(input()))

@functools.cache
def solve(index, lastJump):
    if index == numberOfSquares - 1:
        return entryFees[numberOfSquares - 1]
    f = solve(index + lastJump + 1, lastJump + 1) if index + lastJump + 1 <= numberOfSquares - 1 else float('inf')
    b = solve(index - lastJump, lastJump) if index - lastJump >= 0 else float('inf')
    return entryFees[index] + min(f, b)

print(solve(1, 1))