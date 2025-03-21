SELECT 
    machine_id,
    ROUND(
        2*SUM(CASE WHEN activity_type = 'end' THEN timestamp ELSE -timestamp END) / 
        COUNT(process_id), 
        3
    ) AS processing_time
FROM 
    Activity
GROUP BY 
    machine_id;