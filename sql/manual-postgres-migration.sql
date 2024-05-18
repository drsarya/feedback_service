
CREATE
USER feedback_admin WITH PASSWORD 'admin';
GRANT CONNECT
ON DATABASE feedback TO feedback_admin;
GRANT USAGE ON SCHEMA
feedback TO feedback_admin;
GRANT SELECT, INSERT, UPDATE, DELETE ON feedback.feedback TO feedback_admin;
GRANT SELECT ON feedback."notificationReadStatus" TO feedback_admin;
GRANT INSERT, UPDATE, DELETE ON feedback."feedbackNotification" TO feedback_admin;

-- Проверка прав
SELECT pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'SELECT')     AS "SELECT",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'INSERT')     AS "INSERT",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'UPDATE')     AS "UPDATE",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'DELETE')     AS "DELETE",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'TRUNCATE')   AS "TRUNCATE",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'REFERENCES') AS "REFERENCES",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'TRIGGER')    AS "TRIGGER";