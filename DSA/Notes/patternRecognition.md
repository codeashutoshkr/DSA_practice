# 🚀 The Ultimate Competitive Programming & OA Reference Guide

> *Whether you're warming up before an OA or looking up a quick template mid-practice, this guide covers constraint analysis, C++ STL tricks, and battle-tested boilerplates for the most common algorithmic patterns.*

---

## 📊 1. Constraint-to-Complexity Cheat Sheet

> **Golden Rule:** Before writing a single line of code, look at the input size `N` to narrow down the optimal time complexity and pattern.

| Input Size (N) | Target Time Complexity | Common Patterns & Algorithms |
|:---:|:---:|:---|
| **N ≤ 12** | `O(N!)` or `O(2^N)` | Backtracking, Permutations, Travelling Salesperson |
| **N ≤ 20** | `O(2^N)` or `O(N·2^N)` | Bitmask DP, Subsets, Meet-in-the-Middle (up to N ≤ 40) |
| **N ≤ 100** | `O(N³)` | Floyd-Warshall, 3D DP, Matrix Multiplication |
| **N ≤ 2,000** | `O(N²)` | 2D DP, Nested Loops, All-pairs shortest path (BFS/Dijkstra) |
| **N ≤ 10⁵** | `O(N log N)` | Sorting, Binary Search, Heap/Priority Queue, Merge Sort, Segment Tree |
| **N ≤ 10⁶** | `O(N)` | Two Pointers, Sliding Window, Monotonic Stack, Hash Map, BFS/DFS |
| **N > 10⁸** | `O(log N)` or `O(1)` | Binary Search on Answer, Math, Bit Manipulation, Matrix Exponentiation |

---

## 🛠️ 2. Essential C++ Tricks & Snippets

### 2.1 ⚡ Fast I/O
> Drop at the top of your `Solution` class or inside `main()`.

```cpp
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
```

### 2.2 🧭 Constants & Direction Vectors
> For 4-way and 8-way grid traversal.

```cpp
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

const int dirs[5] = {-1, 0, 1, 0, -1};   // Usage: r + dirs[i], c + dirs[i + 1]

const int dirs8[8][2] = {
    {-1,-1},{-1,0},{-1,1},
    {0,-1},         {0,1},
    {1,-1}, {1,0},  {1,1}
};
```

### 2.3 🔢 Bit Manipulation Built-ins

```cpp
int setBits        = __builtin_popcount(x);    // Count 1s (use __builtin_popcountll for long long)
int leadingZeros   = __builtin_clz(x);          // Count leading zeros (x != 0)
int trailingZeros  = __builtin_ctz(x);          // Count trailing zeros (x != 0)
bool isPowerOfTwo  = (x > 0) && ((x & (x - 1)) == 0);
int lowestSetBit   = x & -x;                    // Isolates lowest set bit (Fenwick trick)
```

### 2.4 🔻 Custom Min-Heap / Lambda Comparator

```cpp
auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;  // Min-heap ordered by second element
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
```

### 2.5 🗜️ Coordinate Compression
> Shrink large values into `[0, K)`.

```cpp
vector<int> vals = nums;
sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());

auto getRank = [&](int x) {
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
};
```

---

## 🧩 3. Core Pattern Boilerplates

### A. 🪟 Sliding Window (Variable Size)

> **When to use:** Longest/shortest subarray or substring satisfying a condition (e.g., sum ≤ K, at most K distinct characters).

```cpp
int slidingWindow(const vector<int>& nums, int k) {
    int left = 0, ans = 0, windowState = 0;

    for (int right = 0; right < nums.size(); ++right) {
        // 1. Add nums[right] to windowState
        windowState += nums[right];

        // 2. Shrink window while condition is violated
        while (windowState > k) {
            windowState -= nums[left];
            left++;
        }

        // 3. Update answer for valid window [left, right]
        ans = max(ans, right - left + 1);
    }
    return ans;
}
```

> 💡 **Pro Tip:** For "Exactly K" subarray problems, rewrite as `atMost(K) - atMost(K - 1)`.

---

### B. 🎯 Binary Search on Answer

> **When to use:** "Minimize the maximum" or "Maximize the minimum" (e.g., Koko Eating Bananas, Split Array Largest Sum). Whenever the feasibility function `check(mid)` is monotonic (`FFFFFTTTTT`).

```cpp
long long binarySearchOnAnswer(const vector<int>& nums, int k) {
    auto check = [&](long long mid) -> bool {
        // Return true if 'mid' is a feasible answer
        long long count = 0;
        for (int x : nums) count += x / mid;
        return count >= k;
    };

    long long low = 1, high = 1e14, ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;  // Prevents overflow
        if (check(mid)) {
            ans = mid;         // Record valid answer
            high = mid - 1;    // Try to find a smaller valid answer
                               // (or low = mid + 1 for maximizing)
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
```

---

### C. 📈 Monotonic Stack

> **When to use:** Next Greater/Smaller Element, Previous Greater/Smaller Element, Largest Rectangle in Histogram, Trapping Rain Water.

```cpp
vector<int> nextGreaterElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> nextGreater(n, -1);
    stack<int> st;  // Stores indices (maintains monotonically decreasing values)

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            nextGreater[st.top()] = nums[i];  // nums[i] is the next greater for st.top()
            st.pop();
        }
        st.push(i);
    }
    return nextGreater;
}
```

---

### D. ➕ Prefix Sum + Hash Map

> **When to use:** Count or find maximum length of subarrays with sum equal to K (or divisible by K).

```cpp
int subarraySum(const vector<int>& nums, int k) {
    unordered_map<long long, int> prefixCount;
    prefixCount[0] = 1;  // Base case: empty prefix has sum 0

    long long curSum = 0;
    int count = 0;

    for (int x : nums) {
        curSum += x;
        if (prefixCount.count(curSum - k)) {
            count += prefixCount[curSum - k];
        }
        prefixCount[curSum]++;
    }
    return count;
}
```

---

### E. 🔁 Backtracking (Subsets / Permutations / Combinations)

> **When to use:** Exhaustive search, generating every subset or combination that satisfies a condition.

```cpp
void backtrack(int idx, const vector<int>& nums,
               vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);

    for (int i = idx; i < nums.size(); ++i) {
        // Skip duplicates (requires 'nums' to be sorted first)
        if (i > idx && nums[i] == nums[i - 1]) continue;

        path.push_back(nums[i]);
        backtrack(i + 1, nums, path, res);
        path.pop_back();
    }
}
```

---

### F. 🌊 Multi-Source BFS (Shortest Distance on Unweighted Grid)

> **When to use:** Shortest distance from the nearest source (e.g., 01 Matrix, Rotting Oranges).

```cpp
vector<vector<int>> bfsGrid(const vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    // dist = -1 everywhere; sources get 0 and go into queue first
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] == 0) {
                dist[r][c] = 0;
                q.push({r, c});
            }
        }
    }

    const int dirs[5] = {-1, 0, 1, 0, -1};
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nr = r + dirs[d], nc = c + dirs[d + 1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return dist;
}
```

---

### G. 🛣️ Dijkstra's Algorithm (Shortest Path in Weighted Graph)

> **When to use:** Shortest path from a source with **non-negative** edge weights.

```cpp
vector<long long> dijkstra(int n, int src, const vector<vector<pair<int, int>>>& adj) {
    const long long INF = 1e18;
    vector<long long> dist(n, INF);

    // Min-heap storing {distance, u}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;  // Crucial skip for outdated heap entries

        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

---

### H. 🔗 Topological Sort (Kahn's Algorithm)

> **When to use:** Course Schedule, task dependencies, cycle detection in Directed Graphs, DP on DAGs.

```cpp
vector<int> topoSort(int n, const vector<vector<int>>& adj) {
    vector<int> indegree(n, 0), order;
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }
    // If order.size() < n, the graph contains a cycle!
    return order.size() == n ? order : vector<int>{};
}
```

---

### I. 🤝 Disjoint Set Union (DSU / Union-Find)

> **When to use:** Dynamic connectivity, Kruskal's MST, counting connected components, cycle detection in undirected graphs.

```cpp
struct DSU {
    vector<int> parent, size;
    int components;

    DSU(int n) : parent(n), size(n, 1), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);  // Path compression
    }

    bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i == root_j) return false;
        if (size[root_i] < size[root_j]) swap(root_i, root_j);  // Union by size
        parent[root_j] = root_i;
        size[root_i] += size[root_j];
        components--;
        return true;
    }
};
```

---

### J. 🌳 Prefix Tree (Trie)

> **When to use:** Word Search II, autocomplete, prefix matching, Maximum XOR of Two Numbers (Bitwise Trie).

```cpp
struct Trie {
    struct Node {
        int next[26]{};
        bool isWord = false;
    };
    vector<Node> tree;

    Trie() { tree.emplace_back(); }  // Root at index 0

    void insert(const string& word) {
        int curr = 0;
        for (char c : word) {
            int idx = c - 'a';
            if (!tree[curr].next[idx]) {
                tree[curr].next[idx] = tree.size();
                tree.emplace_back();
            }
            curr = tree[curr].next[idx];
        }
        tree[curr].isWord = true;
    }

    bool search(const string& word) {
        int curr = 0;
        for (char c : word) {
            int idx = c - 'a';
            if (!tree[curr].next[idx]) return false;
            curr = tree[curr].next[idx];
        }
        return tree[curr].isWord;
    }
};
```

> 💡 **Why `vector<Node>` instead of `new Node()`?** Allocating flat memory inside a `std::vector` prevents memory leaks, avoids pointer overhead, and significantly improves cache locality on LeetCode.

---

### K. 🧠 Top-Down DP (Memoization with Self-Referencing Lambda)

> **When to use:** House Robber style (best sum with no two adjacent picks) or turning brute force into DP.

```cpp
int solveDP(int n, const vector<int>& nums) {
    // state = 1 if the previous item was taken
    vector<vector<int>> memo(n, vector<int>(2, -1));

    auto dfs = [&](auto& self, int i, int state) -> int {
        if (i == n) return 0;
        if (memo[i][state] != -1) return memo[i][state];

        int res = self(self, i + 1, 0);  // Skip (resets state to 0)
        if (state == 0) {
            res = max(res, nums[i] + self(self, i + 1, 1));  // Take
        }
        return memo[i][state] = res;
    };

    return dfs(dfs, 0, 0);
}
```

---

### L. 🌲 Fenwick Tree (Binary Indexed Tree)

> **When to use:** Point updates and range sum queries in `O(log N)` time with minimal code (e.g., Count of Smaller Numbers After Self, Range Sum Query Mutable).

```cpp
struct Fenwick {
    int n;
    vector<long long> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, long long delta) {  // 1-indexed
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    long long query(int i) {  // Prefix sum [1..i]
        long long sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    long long query(int l, int r) { return query(r) - query(l - 1); }
};
```

---

## ✅ 4. Quick Problem-Solving Checklist (When You're Stuck)

Use this as a mental triage when you hit a wall:

| # | Question to Ask | What It Unlocks |
|:---:|:---|:---|
| 1 | 🗂️ **Can you sort the input?** | If order doesn't matter, sorting unlocks **Two Pointers**, **Binary Search**, and **Greedy** choices. |
| 2 | 📉 **Are there monotonic properties?** | If increasing `X` never invalidates a valid condition, try **Binary Search on Answer** or **Sliding Window**. |
| 3 | 🔄 **Need to query ranges repeatedly?** | Reach for **Prefix Sums** (static), **Difference Arrays** (batch range updates), or **Fenwick/Segment Trees** (dynamic). |
| 4 | 🪞 **Dealing with substrings or palindromes?** | Consider **Expand Around Center**, **Rolling Hash**, or **Manacher's / KMP**. |
| 5 | 🎲 **Small constraints (N ≤ 20)?** | Represent visited/chosen elements as a **Bitmask** (`1 << N`) and run **DP**. |

---

## 📋 Quick Reference: Pattern → Problem Type

| Pattern | Classic Problems |
|:---|:---|
| Sliding Window | Longest Substring Without Repeating Characters, Minimum Window Substring |
| Binary Search on Answer | Koko Eating Bananas, Split Array Largest Sum, Capacity to Ship Packages |
| Monotonic Stack | Next Greater Element, Daily Temperatures, Largest Rectangle in Histogram |
| Prefix Sum + Hash Map | Subarray Sum Equals K, Contiguous Array |
| Backtracking | Subsets, Permutations, Combination Sum, N-Queens |
| Multi-Source BFS | Rotting Oranges, 01 Matrix, Walls and Gates |
| Dijkstra | Network Delay Time, Cheapest Flights Within K Stops |
| Topological Sort | Course Schedule I/II, Alien Dictionary |
| DSU | Number of Provinces, Redundant Connection, Accounts Merge |
| Trie | Implement Trie, Word Search II, Design Add and Search Words |
| Top-Down DP | House Robber, Climbing Stairs, Coin Change |
| Fenwick Tree | Count of Smaller Numbers After Self, Range Sum Query Mutable |

---

> 📌 **Bookmark this guide** — it's designed to be your single-page reference for both OA warm-ups and mid-practice lookups. Happy coding! 🎯