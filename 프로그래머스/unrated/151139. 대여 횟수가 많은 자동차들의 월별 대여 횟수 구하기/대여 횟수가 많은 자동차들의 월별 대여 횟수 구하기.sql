-- 코드를 입력하세요
SELECT MONTH(START_DATE) MONTH, CAR_ID, COUNT(CAR_ID) RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE CAR_ID IN (
    SELECT CAR_ID
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE DATE_FORMAT(START_DATE,'%Y-%m') >= '2022-08' AND DATE_FORMAT(START_DATE,'%Y-%m') <= '2022-10'
    GROUP BY CAR_ID
    HAVING COUNT(CAR_ID) >= 5
) AND DATE_FORMAT(START_DATE,'%Y-%m') >= '2022-08' AND DATE_FORMAT(START_DATE,'%Y-%m') <= '2022-10'
GROUP BY CAR_ID, MONTH(START_DATE)
ORDER BY MONTH(START_DATE), CAR_ID DESC