numberOfFish, numberOfFishmongers = map(int, input().split())

weights = list(map(int, input().split()))
weights.sort(reverse=True)

fishmongers = []
for _ in range(numberOfFishmongers):
    demand, moniesPerKilogram = map(int, input().split())
    fishmongers.append([demand, moniesPerKilogram])

fishmongers.sort(key=lambda x: x[1], reverse=True)

totalMonies = 0
fishIndex = 0
for i in range(numberOfFishmongers):
    while fishmongers[i][0] > 0 and fishIndex < numberOfFish:
        totalMonies += weights[fishIndex] * fishmongers[i][1]
        fishmongers[i][0] -= 1
        fishIndex += 1
    
    if fishIndex >= numberOfFish:
        break

print(totalMonies)