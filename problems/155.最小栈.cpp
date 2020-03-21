/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (51.10%)
 * Likes:    360
 * Dislikes: 0
 * Total Accepted:    68.1K
 * Total Submissions: 133.2K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stack_.reserve(10000);
        min_value_.reserve(10000);
    }
    
    void push(int x) {
        int current_min = x;
        if (pos_ >= 0) {
            current_min = std::min(min_value_[pos_], x);
        }

        if (stack_.capacity() > pos_ + 1) {
            ++pos_;
            stack_[pos_] = x;
            min_value_[pos_] = current_min;
        } else {
            stack_.push_back(x);
            min_value_.push_back(current_min);
            ++pos_;
        }
    }
    
    void pop() {
        --pos_;
        if (pos_ < 0) {
            pos_ = -1;
        }
    }
    
    int top() {
        if (pos_ < 0) {
            return 0;
        }
        return stack_[pos_];
    }
    
    int getMin() {
        std::cout << "pos=" << pos_ << std::endl;
        if (pos_ < 0) {
            return 0;
        }
        return min_value_[pos_];
    }
private:
    std::vector<int> stack_;
    std::vector<int> min_value_;
    int pos_ = -1;  // 当前索引
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

