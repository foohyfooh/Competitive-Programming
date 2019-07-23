class BinaryIndexTree:

  def __init__(self, N):
    self.N = N
    self.tree = [0] * (N + 1)

  def update(self, pos, val):
    while pos <= self.N:
      self.tree[pos] += val
      pos += pos & -pos

  def query(self, pos):
    total = 0
    while pos > 0:
      total += self.tree[pos]
      pos -= pos & -pos
    return total

  def rangeQuery(self, start, end):
    return self.query(end) - self.query(start - 1)
