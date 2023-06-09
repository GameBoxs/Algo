-- 코드를 입력하세요
SELECT (
    CASE
        WHEN PRICE / 10000 > 0 THEN FLOOR(PRICE/10000)*10000 ELSE 0
    END
) AS 'PRICE_GROUP', COUNT(PRODUCT_ID) AS PRODUCTS
FROM PRODUCT
GROUP BY PRICE_GROUP
ORDER BY PRICE_GROUP