w, h, n = map(int, input().split())


left = 0
right = 1_000_000_000_000_000_000

def good(middle):
  a = middle // w
  b = middle // h
  return n <= a * b


while right > left + 1:
  middle = left + (right - left) // 2
  if good(middle):
    right = middle
  else:
    left = middle
    
print(right)
