class Solution {
 public:
  Solution(vector<int>& w) : gen(rd()), dist(w.begin(), w.end()) {}

  auto pickIndex() -> int {
    return dist(gen);
  }

 private:
  std::random_device rd;
  std::mt19937 gen;
  std::discrete_distribution<> dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */