numberOfTrees, windowSize = map(int, input().split())
heightOfTrees = list(map(int, input().split()))

left = 0
right = windowSize - 1

shortest = min(heightOfTrees[left:right + 1])
tallest = max(heightOfTrees[left:right + 1])
smallestDifference = tallest - shortest

while right < numberOfTrees - 1:
    left += 1
    right += 1

    if heightOfTrees[right] > tallest:
        tallest = heightOfTrees[right]
    elif heightOfTrees[left - 1] == tallest:
        tallest = max(heightOfTrees[left:right + 1])

    if heightOfTrees[right] < shortest:
        shortest = heightOfTrees[right]
    elif heightOfTrees[left - 1] == shortest:
        shortest = min(heightOfTrees[left:right + 1])

    smallestDifference = min(smallestDifference, tallest - shortest)

print(smallestDifference)