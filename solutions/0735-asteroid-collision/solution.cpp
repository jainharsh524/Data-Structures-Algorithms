class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for (int ele : asteroids) {
            if (ele > 0) {
                stack.push(ele);
            } else {
                while (!stack.empty() && stack.top() > 0 && stack.top() < -ele) {
                    stack.pop();
                }
                if (stack.empty() || stack.top() < 0) {
                    stack.push(ele);
                }
                if (!stack.empty() && stack.top() == -ele) {
                    stack.pop();
                }
            }
        }
        vector<int> res;
        int i = stack.size() - 1;
        while (!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;        
    }
};
