--
-- @lc app=leetcode.cn id=183 lang=mysql
--
-- [183] 从不订购的客户
--
-- https://leetcode.cn/problems/customers-who-never-order/description/
--
-- database
-- Easy (66.50%)
-- Likes:    381
-- Dislikes: 0
-- Total Accepted:    270.8K
-- Total Submissions: 407.2K
-- Testcase Example:  '{"headers": {"Customers": ["id", "name"], "Orders": ["id", "customerId"]}, "rows": {"Customers": [[1, "Joe"], [2, "Henry"], [3, "Sam"], [4, "Max"]], "Orders": [[1, 3], [2, 1]]}}'
--
-- 某网站包含两个表，Customers 表和 Orders 表。编写一个 SQL 查询，找出所有从不订购任何东西的客户。
-- 
-- Customers 表：
-- 
-- +----+-------+
-- | Id | Name  |
-- +----+-------+
-- | 1  | Joe   |
-- | 2  | Henry |
-- | 3  | Sam   |
-- | 4  | Max   |
-- +----+-------+
-- 
-- 
-- Orders 表：
-- 
-- +----+------------+
-- | Id | CustomerId |
-- +----+------------+
-- | 1  | 3          |
-- | 2  | 1          |
-- +----+------------+
-- 
-- 
-- 例如给定上述表格，你的查询应返回：
-- 
-- +-----------+
-- | Customers |
-- +-----------+
-- | Henry     |
-- | Max       |
-- +-----------+
-- 
-- 
--

-- @lc code=start
# Write your MySQL query statement below
-- SELECT
--     c.name as Customers
-- FROM
--     Customers as c
-- left join Orders as o on c.Id = o.CustomerId
-- WHERE
--     o.Id IS NULL
SELECT
    c.name as Customers
FROM
    Customers as c
WHERE
    c.Id not in
    {
        SELECT
            CustomerId
        FROM
            order
    };
-- @lc code=end

