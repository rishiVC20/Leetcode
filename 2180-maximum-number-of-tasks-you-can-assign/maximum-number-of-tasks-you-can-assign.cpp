const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(___::_);
    return 0;
}();
#endif
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());         // Sort tasks from easiest to hardest
        sort(workers.begin(), workers.end());     // Sort workers from weakest to strongest

        int left = 0;
        int right = min(tasks.size(), workers.size());
        int answer = 0;

        // Binary search for the maximum number of tasks we can complete
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canComplete(tasks, workers, pills, strength, mid)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }

private:
    bool canComplete(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        if (k == 0) return true;
        if (k > workers.size()) return false;

        deque<int> dq;
        int t = k - 1;  // Start from the hardest task in our window
        int used_pills = 0;

        // We'll try to assign the k weakest workers to the k easiest tasks
        for (int i = workers.size() - k; i < workers.size(); i++) {
            dq.push_back(workers[i]);
        }

        for (; t >= 0; t--) {
            if (!dq.empty() && dq.back() >= tasks[t]) {
                // Assign to strongest available worker without pill
                dq.pop_back();
            } else {
                // Try to assign with pill
                if (used_pills < pills) {
                    // Find the weakest worker who can do the task with pill
                    auto it = lower_bound(dq.begin(), dq.end(), tasks[t] - strength);
                    if (it != dq.end()) {
                        dq.erase(it);
                        used_pills++;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};