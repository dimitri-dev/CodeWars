#define vI std::vector<int>

vI josephus(vI items, int k) {
    if (items.empty()) return vI();
    vI copy = items, returned;

    int pos = 0;
    while (copy.size() >= 1) {
        pos += k - 1;
        pos %= copy.size();
        returned.push_back(copy[pos]);
        copy.erase(copy.begin() + pos);
    }

    return returned;
}