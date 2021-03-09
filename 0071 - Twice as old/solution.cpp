int twice_as_old(int dad, int son) {
  return (dad - 2 * son) < 0 ? (dad - 2 * son) * - 1 : (dad - 2 * son);
}