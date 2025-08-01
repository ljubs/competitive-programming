dnaLength, alphabetSize, numberOfRequirements = map(int, input().split())
dna = list(map(int, input().split()))

requirements = {}
for _ in range(numberOfRequirements):
    nucleobase, mimimumRequiredQuantity = map(int, input().split())
    requirements[nucleobase] = mimimumRequiredQuantity

left, right = 0, 0
result = float('inf')
count = 0
currentWindow = {}

while right < dnaLength:
    currentWindow[dna[right]] = currentWindow.get(dna[right], 0) + 1
    if dna[right] in requirements and currentWindow[dna[right]] == requirements[dna[right]]:
        count += 1
    right += 1
    while count == numberOfRequirements:
        result = min(result, right - left)
        currentWindow[dna[left]] -= 1
        if dna[left] in requirements and currentWindow[dna[left]] < requirements[dna[left]]:
            count -= 1
        left += 1

if result == float('inf'):
    print("impossible")
else:
    print(result)