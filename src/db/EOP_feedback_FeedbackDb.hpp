
#ifndef CRUD_FeedbackDb_HPP
#define CRUD_FeedbackDb_HPP

#include "dto/EOP_feedback_FeedbackDto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * FeedbackDb client definitions.
 */
class FeedbackDb : public oatpp::orm::DbClient {
public:

	FeedbackDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
		: oatpp::orm::DbClient(executor)
	{
	}

	QUERY(createFeedback,
		"insert into feedback.feedback(description, commentator_user_id, commentator_login, show_commentator_login, course_id, owner_course_user_id ) values "
		"(:feedback.description,  uuid(:feedback.commentatorUserId), :feedback.commentatorLogin, :feedback.showCommentatorLogin, uuid(:feedback.courseId), uuid(:feedback.ownerCourseUserId)) RETURNING <!! id,  description, CAST(commentator_user_id AS text) as \"commentatorUserId\"  , commentator_login as \"commentatorLogin\", show_commentator_login as \"showCommentatorLogin\", CAST(course_id AS text) as \"courseId\" , CAST(owner_course_user_id AS text) as \"ownerCourseUserId\" , is_read_by_owner_course as \"isReadByOwnerCourse\","
                                                                                                                                                                                                                                                             			"  owner_course_answer_comment as \"ownerCourseAnswerComment\",  CAST(owner_course_answer_comment_creation_date AS text)  as \"ownerCourseAnswerCommentCreationDate\", CAST(creation_date AS text)   as \"creationDate\", CAST(update_date AS text)   as \"updateDate\", "
                                                                                                                                                                                                                                                             			"   is_banned as \"isBanned\" , ban_description as \"banDescription\", CAST(ban_date AS text) as \"banDate\"!!>;",
		PREPARE(true), PARAM(oatpp::Object<FeedbackDto>, feedback))

		QUERY(updateFeedback,
			"UPDATE feedback.feedback "
			"SET update_date = CURRENT_TIMESTAMP, "
			"description = :feedback.description "
			"WHERE  id=:feedback.id;",
			PREPARE(true), PARAM(oatpp::Object<FeedbackDto>, feedback))

		QUERY(changeFeedbackLoginVisibility,
			"UPDATE feedback.feedback "
			"SET update_date = CURRENT_TIMESTAMP, "
			"show_commentator_login = :feedback.showCommentatorLogin "
			"WHERE  id=:feedback.id;",
			PREPARE(true), PARAM(oatpp::Object<FeedbackDto>, feedback))


		QUERY(getFeedbacks,
			"SELECT <!! id,  description, CAST(commentator_user_id AS text) as \"commentatorUserId\"  , commentator_login as \"commentatorLogin\", show_commentator_login as \"showCommentatorLogin\", CAST(course_id AS text) as \"courseId\" , CAST(owner_course_user_id AS text) as \"ownerCourseUserId\" , is_read_by_owner_course as \"isReadByOwnerCourse\","
                                                                                                                                                                                                                                                             			"  owner_course_answer_comment as \"ownerCourseAnswerComment\",  CAST(owner_course_answer_comment_creation_date AS text)  as \"ownerCourseAnswerCommentCreationDate\", CAST(creation_date AS text)   as \"creationDate\", CAST(update_date AS text)   as \"updateDate\", "
                                                                                                                                                                                                                                                             			"   is_banned as \"isBanned\" , ban_description as \"banDescription\", CAST(ban_date AS text) as \"banDate\"!!> FROM feedback.feedback order by creation_date desc LIMIT :limit OFFSET :offset;",
			PREPARE(true), PARAM(oatpp::UInt32, offset),
			PARAM(oatpp::UInt32, limit))

		QUERY(getFeedbackById,
			"SELECT <!! id,  description, CAST(commentator_user_id AS text) as \"commentatorUserId\"  , commentator_login as \"commentatorLogin\", show_commentator_login as \"showCommentatorLogin\", CAST(course_id AS text) as \"courseId\" , CAST(owner_course_user_id AS text) as \"ownerCourseUserId\" , is_read_by_owner_course as \"isReadByOwnerCourse\","
                                                                                                                                                                                                                                                             			"  owner_course_answer_comment as \"ownerCourseAnswerComment\",  CAST(owner_course_answer_comment_creation_date AS text)  as \"ownerCourseAnswerCommentCreationDate\", CAST(creation_date AS text)   as \"creationDate\", CAST(update_date AS text)   as \"updateDate\", "
                                                                                                                                                                                                                                                             			"   is_banned as \"isBanned\" , ban_description as \"banDescription\", CAST(ban_date AS text) as \"banDate\"!!> FROM feedback.feedback WHERE id=:feedbackId ;",
			PREPARE(true), PARAM(oatpp::Int32, feedbackId))

		QUERY(getFeedbackByUserId,
			"SELECT <!! id,  description, CAST(commentator_user_id AS text) as \"commentatorUserId\"  , commentator_login as \"commentatorLogin\", show_commentator_login as \"showCommentatorLogin\", CAST(course_id AS text) as \"courseId\" , CAST(owner_course_user_id AS text) as \"ownerCourseUserId\" , is_read_by_owner_course as \"isReadByOwnerCourse\","
                                                                                                                                                                                                                                                             			"  owner_course_answer_comment as \"ownerCourseAnswerComment\",  CAST(owner_course_answer_comment_creation_date AS text)  as \"ownerCourseAnswerCommentCreationDate\", CAST(creation_date AS text)   as \"creationDate\", CAST(update_date AS text)   as \"updateDate\", "
                                                                                                                                                                                                                                                             			"   is_banned as \"isBanned\" , ban_description as \"banDescription\", CAST(ban_date AS text) as \"banDate\"!!> FROM feedback.feedback WHERE commentator_user_id=uuid(:userId) order by creation_date desc LIMIT :limit OFFSET :offset;",
			PREPARE(true), PARAM(oatpp::String, userId),
			PARAM(oatpp::UInt32, offset),
			PARAM(oatpp::UInt32, limit))

		QUERY(getFeedbackByCourseId,
			"SELECT <!! id,  description, CAST(commentator_user_id AS text) as \"commentatorUserId\"  , commentator_login as \"commentatorLogin\", show_commentator_login as \"showCommentatorLogin\", CAST(course_id AS text) as \"courseId\" , CAST(owner_course_user_id AS text) as \"ownerCourseUserId\" , is_read_by_owner_course as \"isReadByOwnerCourse\","
                                                                                                                                                                                                                                                             			"  owner_course_answer_comment as \"ownerCourseAnswerComment\",  CAST(owner_course_answer_comment_creation_date AS text)  as \"ownerCourseAnswerCommentCreationDate\", CAST(creation_date AS text)   as \"creationDate\", CAST(update_date AS text)   as \"updateDate\", "
                                                                                                                                                                                                                                                             			"   is_banned as \"isBanned\" , ban_description as \"banDescription\", CAST(ban_date AS text) as \"banDate\"!!> FROM feedback.feedback where course_id=uuid(:courseId) and is_banned=false and is_read_by_owner_course=true order by creation_date desc LIMIT :limit OFFSET :offset;",
			PREPARE(true), PARAM(oatpp::String, courseId),
			PARAM(oatpp::UInt32, offset),
			PARAM(oatpp::UInt32, limit))

		QUERY(getFeedbackByCourseOwner,
			"SELECT <!! id,  description, CAST(commentator_user_id AS text) as \"commentatorUserId\"  , commentator_login as \"commentatorLogin\", show_commentator_login as \"showCommentatorLogin\", CAST(course_id AS text) as \"courseId\" , CAST(owner_course_user_id AS text) as \"ownerCourseUserId\" , is_read_by_owner_course as \"isReadByOwnerCourse\","
                                                                                                                                                                                                                                                             			"  owner_course_answer_comment as \"ownerCourseAnswerComment\",  CAST(owner_course_answer_comment_creation_date AS text)  as \"ownerCourseAnswerCommentCreationDate\", CAST(creation_date AS text)   as \"creationDate\", CAST(update_date AS text)   as \"updateDate\", "
                                                                                                                                                                                                                                                             			"   is_banned as \"isBanned\" , ban_description as \"banDescription\", CAST(ban_date AS text) as \"banDate\"!!> FROM feedback.feedback where owner_course_user_id=uuid(:ownerCourseUserId) order by creation_date desc LIMIT :limit OFFSET :offset;",
			PREPARE(true), PARAM(oatpp::String, ownerCourseUserId),
			PARAM(oatpp::UInt32, offset),
			PARAM(oatpp::UInt32, limit))

		QUERY(updateAnswerByCourseOwner,
			"UPDATE feedback.feedback "
			"SET owner_course_answer_comment =:feedback.ownerCourseAnswerComment, "
			"owner_course_answer_comment_creation_date = CURRENT_TIMESTAMP, "
			"is_read_by_owner_course=:feedback.isReadByOwnerCourse "
			"WHERE id=:feedback.id;",
			PREPARE(true), PARAM(oatpp::Object<FeedbackDto>, feedback))

		QUERY(banFeedback,
			"UPDATE feedback.feedback "
			"SET is_banned = true, "
			"ban_description =:feedback.banDescription, "
			"ban_date = CURRENT_TIMESTAMP "
			"WHERE id = :feedback.id;",
			PREPARE(true), PARAM(oatpp::Object<FeedbackDto>, feedback))

		QUERY(unbanFeedback,
			"UPDATE  feedback.feedback "
			"SET is_banned = false, "
			"ban_description = null, "
			"ban_date = null "
			"WHERE id=:feedbackId;",
			PREPARE(true), PARAM(oatpp::Int32, feedbackId))


		QUERY(deleteFeedback,
			"DELETE FROM  feedback.feedback WHERE id=:feedbackId;",
			PREPARE(true), PARAM(oatpp::Int32, feedbackId))

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //CRUD_FEEDBACKDB_HPP
