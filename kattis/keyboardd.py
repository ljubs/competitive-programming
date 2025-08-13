text = input()
sticky = input()

textCount = {}
for t in text:
    textCount[t] = textCount.get(t, 0) + 1
    
stickyCount = {}
for s in sticky:
    stickyCount[s] = stickyCount.get(s, 0) + 1
    
result = ""
for k in textCount.keys() & stickyCount.keys():
    if textCount[k] != stickyCount[k]:
        result += k

print(result)