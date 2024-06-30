-- Write your PostgreSQL query statement below
SELECT w.id
FROM Weather as w
WHERE w.temperature > (
    SELECT w2.temperature
    FROM Weather as w2
    WHERE w.recordDate = w2.recordDate + 1
);