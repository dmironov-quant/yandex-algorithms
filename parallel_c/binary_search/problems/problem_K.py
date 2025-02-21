# Задача K: Космическое поселение
# https://informatics.msk.ru/mod/statements/view.php?chapterid=113097#1


n, a, b, w, h = map(int, input().split())


def good1(d):
  x1 = h // (a + 2*d)
  x2 = w // (b + 2*d)
  return x1*x2 >= n
  
def good2(d):
  x1 = h // (b + 2*d)
  x2 = w // (a + 2*d)
  return x1*x2 >= n
  
left = 0
right = max(h, w) + 1

while right > left + 1:
  middle = left + (right - left) // 2
  if good1(middle):
    left = middle;
  else:
    right = middle

curr = left

left = 0
right = max(h, w) + 1

while right > left + 1:
  middle = left + (right - left) // 2
  if good2(middle):
    left = middle;
  else:
    right = middle
    
print(max(curr, left))
