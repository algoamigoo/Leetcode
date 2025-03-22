SELECT p.product_id,COALESCE(ROUND(SUM(price*units)/SUM(units),2),0) AS average_price
FROM Prices as p
LEFT JOIN UnitsSold AS u ON u.product_id=p.product_id
AND purchase_date BETWEEN start_date AND end_date
GROUP BY p.product_id;