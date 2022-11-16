--
-- @lc app=leetcode.cn id=1050 lang=mysql
--
-- [1050] 合作过至少三次的演员和导演
--
-- https://leetcode.cn/problems/actors-and-directors-who-cooperated-at-least-three-times/description/
--
-- database
-- Easy (77.72%)
-- Likes:    53
-- Dislikes: 0
-- Total Accepted:    37.6K
-- Total Submissions: 48.5K
-- Testcase Example:  '{"headers":{"ActorDirector":["actor_id","director_id","timestamp"]},"rows":{"ActorDirector":[[1,1,0],[1,1,1],[1,1,2],[1,2,3],[1,2,4],[2,1,5],[2,1,6]]}}'
--
-- ActorDirector 表：
-- 
-- 
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | actor_id    | int     |
-- | director_id | int     |
-- | timestamp   | int     |
-- +-------------+---------+
-- timestamp 是这张表的主键.
-- 
-- 
-- 
-- 
-- 写一条SQL查询语句获取合作过至少三次的演员和导演的 id 对 (actor_id, director_id)
-- 
-- 示例：
-- 
-- 
-- ActorDirector 表：
-- +-------------+-------------+-------------+
-- | actor_id    | director_id | timestamp   |
-- +-------------+-------------+-------------+
-- | 1           | 1           | 0           |
-- | 1           | 1           | 1           |
-- | 1           | 1           | 2           |
-- | 1           | 2           | 3           |
-- | 1           | 2           | 4           |
-- | 2           | 1           | 5           |
-- | 2           | 1           | 6           |
-- +-------------+-------------+-------------+
-- 
-- Result 表：
-- +-------------+-------------+
-- | actor_id    | director_id |
-- +-------------+-------------+
-- | 1           | 1           |
-- +-------------+-------------+
-- 唯一的 id 对是 (1, 1)，他们恰好合作了 3 次。
-- 
--

-- @lc code=start
# Write your MySQL query statement below
select 
    d.actor_id actor_id,
    d.director_id director_id
from
    (
        select 
            actor_id,
            director_id,
            count(actor_id) as count
        from 
            ActorDirector
        group by 
            actor_id, director_id
    ) d 
where
    d.count >= 3
-- @lc code=end

