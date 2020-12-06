bool shared_bits(long a, long b){
  return (a&b & (a & b) - 1);
}