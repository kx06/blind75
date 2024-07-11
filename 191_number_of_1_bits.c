static unsigned char table[256];

void initialize() {
  table[0] = 0;
  for (unsigned int i = 1; i < 256; i++)
    table[i] = (i & 1) + table[i >> 1];
}

int hammingWeight(unsigned int n) {
  initialize();
  int res = table[n & 0xff];
  n = n >> 8;
  res = res + table[n & 0xff];
  n = n >> 8;
  res = res + table[n & 0xff];
  n = n >> 8;
  res = res + table[n & 0xff];
  return res;
}
