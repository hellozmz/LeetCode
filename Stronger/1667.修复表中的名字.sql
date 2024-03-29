--
-- @lc app=leetcode.cn id=1667 lang=mysql
--
-- [1667] 修复表中的名字
--
-- https://leetcode.cn/problems/fix-names-in-a-table/description/
--
-- database
-- Easy (63.94%)
-- Likes:    57
-- Dislikes: 0
-- Total Accepted:    35K
-- Total Submissions: 54.6K
-- Testcase Example:  '{"headers":{"Users":["user_id","name"]},"rows":{"Users":[[1,"aLice"],[2,"bOB"]]}}'
--
-- 表： Users
-- 
-- 
-- +----------------+---------+
-- | Column Name    | Type    |
-- +----------------+---------+
-- | user_id        | int     |
-- | name           | varchar |
-- +----------------+---------+
-- user_id 是该表的主键。
-- 该表包含用户的 ID 和名字。名字仅由小写和大写字符组成。
-- 
-- 
-- 
-- 
-- 编写一个 SQL 查询来修复名字，使得只有第一个字符是大写的，其余都是小写的。
-- 
-- 返回按 user_id 排序的结果表。
-- 
-- 查询结果格式示例如下。
-- 
-- 
-- 
-- 示例 1：
-- 
-- 
-- 输入：
-- Users table:
-- +---------+-------+
-- | user_id | name  |
-- +---------+-------+
-- | 1       | aLice |
-- | 2       | bOB   |
-- +---------+-------+
-- 输出：
-- +---------+-------+
-- | user_id | name  |
-- +---------+-------+
-- | 1       | Alice |
-- | 2       | Bob   |
-- +---------+-------+
-- 
--

-- @lc code=start
# Write your MySQL query statement below

select 
    user_id,
    (
        CONCAT(upper(left(name, 1)), lower(right(name, length(name) - 1)))
    ) name
from
    Users
order by
    user_id


-- @lc code=end

