
#ifndef EOP_FEEDBACK_FEEDBACKNOTIFICATONDB_HPP
#define EOP_FEEDBACK_FEEDBACKNOTIFICATONDB_HPP

#include <dto/EOP_feedback_FeedbackNotificationDto.hpp>
#include <oatpp-postgresql/orm.hpp>

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * FeedbackNotificatonDb client definitions.
 */
class FeedbackNotificatonDb : public oatpp::orm::DbClient {
public:

	FeedbackNotificatonDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
		: oatpp::orm::DbClient(executor)
	{

		oatpp::orm::SchemaMigration migration(executor);
		migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/001_init.sql");
		// TODO - Add more migrations here.
		migration.migrate(); // <-- run igrations. This guy will throw on error.

		auto version = executor->getSchemaVersion();
		OATPP_LOGD("FeedbackNotificatonDb", "Migration - OK. Version=%lld.", version);
	}

	QUERY(createNotificationFeedback,
		"insert into  feedback.feedback_notification (feedback_id, user_id, description) values "
		"(:notification.feedbackId, uuid(:notification.userId), :notification.description ) RETURNING <!! id, feedback_id as \"feedbackId\", CAST(user_id AS text) as \"userId\", description, notification_status as \"notificationStatus\", CAST(creation_date AS text) as \"creationDate\" !!>;",
		PREPARE(true), PARAM(oatpp::Object<FeedbackNotificationDto>, notification))


		QUERY(getNotificationById,
			"SELECT  <!! id, feedback_id as \"feedbackId\", CAST(user_id AS text) as \"userId\", description, notification_status as \"notificationStatus\", CAST(creation_date AS text) as \"creationDate\" !!>"
			" FROM  feedback.feedback_notification "
			"WHERE  id=:id;",
			PREPARE(true),  PARAM(oatpp::Int32, id))

		QUERY(readNotificationFeedback,
			"UPDATE  feedback.feedback_notification "
			"SET notification_status = 2 "
			"WHERE id = :id;",
			PREPARE(true),  PARAM(oatpp::Int32, id))

		QUERY(getNotificationsForUserId,
			"SELECT <!! id, feedback_id as \"feedbackId\", CAST(user_id AS text) as \"userId\", description, notification_status as \"notificationStatus\", CAST(creation_date AS text) as \"creationDate\" !!> FROM  feedback.feedback_notification WHERE  user_id = uuid(:userId) and notification_status = 1 order by creation_date desc;",
			PREPARE(true),  PARAM(oatpp::String, userId))

		QUERY(deleteReadNotifications,
			"delete FROM feedback.feedback_notification WHERE notification_status = 2;")
};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //EOP_FEEDBACK_FEEDBACKNOTIFICATONDB_HPP
