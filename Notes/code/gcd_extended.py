def extendedGCD(a, b):
  if b == 0: return (a, 1, 0)
  nextRow = extendedGCD(b, a % b)
  return (nextRow[0], nextRow[2], nextRow[1] - (a / b) * nextRow[2])
