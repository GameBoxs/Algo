-- 코드를 입력하세요
# SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
# FROM REST_INFO RI JOIN (
#     SELECT MAX(FAVORITES) AS 'FAVORTIES'
#     FROM REST_INFO
#     GROUP BY FOOD_TYPE
# ) AS RI2
# ON RI.FAVORITES = RI2.FAVORTIES
# GROUP BY FOOD_TYPE
# ORDER BY FOOD_TYPE DESC

# SELECT FOOD_TYPE, MAX(FAVORITES)
# # REST_ID, REST_NAME, 

# FROM REST_INFO
# GROUP BY FOOD_TYPE
# # HAVING MAX(FAVORITES)
# ORDER BY FOOD_TYPE DESC;

SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
FROM REST_INFO
WHERE (FOOD_TYPE, FAVORITES) IN (
    SELECT FOOD_TYPE, MAX(FAVORITES)
    FROM REST_INFO
    GROUP BY FOOD_TYPE)
    
ORDER BY FOOD_TYPE DESC;