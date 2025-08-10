def getParent(node, k):
    return (node - 1) // k if node != 0 else 0

def distanceBetween(a, b, k):
    steps = 0
    while a != b:
        if a > b:
            a = getParent(a, k)
        else:
            b = getParent(b, k)
        steps += 1
    return steps

numberOfNodes, maxChildren, numberOfQueries = map(int, input().split())

for _ in range(numberOfQueries):
    a, b = map(int, input().split())
    print(distanceBetween(a - 1, b - 1, maxChildren))