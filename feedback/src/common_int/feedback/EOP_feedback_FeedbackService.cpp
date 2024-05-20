#include <common_int/feedback/EOP_feedback_FeedbackService.h>
#include <common_int/feedback/EOP_feedback_FeedbackService.hpp>
#include <iostream>

oatpp::Object<FeedbackDto> FeedbackServiceMapper::mapToOatppFeedback(const Feedback* dto) {
	oatpp::Object<FeedbackDto> feedbackDto;

	feedbackDto->id = dto->id;
	feedbackDto->commentatorUserId = dto->commentatorUserId;
	feedbackDto->commentatorLogin = dto->commentatorLogin;
	feedbackDto->showCommentatorLogin = dto->showCommentatorLogin;
	feedbackDto->courseId = dto->courseId;
	feedbackDto->ownerCourseUserId = dto->ownerCourseUserId;
	feedbackDto->isReadByOwnerCourse = dto->isReadByOwnerCourse;
	feedbackDto->ownerCourseAnswerComment = dto->ownerCourseAnswerComment;
	feedbackDto->ownerCourseAnswerCommentCreationDate = dto->ownerCourseAnswerCommentCreationDate;
	feedbackDto->description = dto->description;
	feedbackDto->creationDate = dto->creationDate;
	feedbackDto->updateDate = dto->updateDate;
	feedbackDto->isBanned = dto->isBanned;
	feedbackDto->banDescription = dto->banDescription;
	feedbackDto->banDate = dto->banDate;
	return feedbackDto;
}

void FeedbackServiceMapper::fromDtoToFeedback(const oatpp::Object<FeedbackDto>& dto, Feedback* feedback) {
	feedback->id = dto->id;
	feedback->commentatorUserId = (char*)dto->commentatorUserId->c_str();
	feedback->commentatorLogin = (char*)dto->commentatorLogin->c_str();
	feedback->showCommentatorLogin = dto->showCommentatorLogin ? 1 : 0;
	feedback->courseId = (char*)dto->courseId->c_str();
	feedback->ownerCourseUserId = (char*)dto->ownerCourseUserId->c_str();
	feedback->isReadByOwnerCourse = dto->isReadByOwnerCourse ? 1 : 0;
	feedback->ownerCourseAnswerComment = (char*)dto->ownerCourseAnswerComment->c_str();
	feedback->ownerCourseAnswerCommentCreationDate = (char*)dto->ownerCourseAnswerCommentCreationDate->c_str();
	feedback->description = (char*)dto->description->c_str();
	feedback->creationDate = (char*)dto->creationDate->c_str();
	feedback->updateDate = (char*)dto->updateDate->c_str();
	feedback->isBanned = dto->isBanned ? 1 : 0;
	feedback->banDescription = (char*)dto->banDescription->c_str();
	feedback->banDate = (char*)dto->banDate->c_str();
}

void  createFeedback(Feedback* feedback, Feedback* newFeedback)
{
	FeedbackService feedbackService;
	auto mappedObject = FeedbackServiceMapper::mapToOatppFeedback(feedback);
	auto feedbackOatpp = feedbackService.createFeedback(mappedObject);
	FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void  updateFeedback(Feedback* feedback, Feedback* newFeedback)
{
	FeedbackService feedbackService;
	auto mappedObject = FeedbackServiceMapper::mapToOatppFeedback(feedback);
	auto feedbackOatpp = feedbackService.updateFeedback(mappedObject);
	FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void  changeFeedbackLoginVisibility(Feedback* feedback, Feedback* newFeedback)
{
	FeedbackService feedbackService;
	auto mappedObject = FeedbackServiceMapper::mapToOatppFeedback(feedback);
	auto feedbackOatpp = feedbackService.changeFeedbackLoginVisibility(mappedObject);
	FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void  getFeedbackById(int feedbackId, Feedback* feedback)
{
	FeedbackService feedbackService;
	auto feedbackOatpp = feedbackService.getFeedbackById(feedbackId);
	FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp, feedback);
}

void  getFeedbacks(int offset, int limit, Feedback* feedbacks)
{
	FeedbackService feedbackService;
	auto feedbackOatpp = feedbackService.getFeedbacks(offset, limit);
	std::vector<Feedback> vect;
	for (int i = 0; i < feedbackOatpp->items->size(); i++) {
		Feedback feedback;
		FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp->items[i], &feedback);
		vect.push_back(feedback);
	}
	feedbacks = &vect[0];
}

void  getFeedbackByUserId(char* userId, int offset, int limit, Feedback* feedbacks)
{
	FeedbackService feedbackService;
	auto feedbackOatpp = feedbackService.getFeedbackByUserId(userId, offset, limit);
	std::vector<Feedback> vect;
	for (int i = 0; i < feedbackOatpp->items->size(); i++) {
		Feedback feedback;
		FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp->items[i], &feedback);
		vect.push_back(feedback);
	}
	feedbacks = &vect[0];
}

void  getFeedbackByCourseId(char* courseId, int offset, int limit, Feedback* feedbacks)
{
	FeedbackService feedbackService;
	auto feedbackOatpp = feedbackService.getFeedbackByCourseId(courseId, offset, limit);
	std::vector<Feedback> vect;
	for (int i = 0; i < feedbackOatpp->items->size(); i++) {
		Feedback feedback;
		FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp->items[i], &feedback);
		vect.push_back(feedback);
	}
	feedbacks = &vect[0];
}

void  getFeedbackByCourseOwner(char* ownerCourseUserId, int offset, int limit, Feedback* feedbacks)
{
	FeedbackService feedbackService;
	auto feedbackOatpp = feedbackService.getFeedbackByCourseOwner(ownerCourseUserId, offset, limit);
	std::vector<Feedback> vect;
	for (int i = 0; i < feedbackOatpp->items->size(); i++) {
		Feedback feedback;
		FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp->items[i], &feedback);
		vect.push_back(feedback);
	}
	feedbacks = &vect[0];
}

void  updateAnswerByCourseOwner(Feedback* feedback, Feedback* newFeedback)
{
	FeedbackService feedbackService;
	auto mappedObject = FeedbackServiceMapper::mapToOatppFeedback(feedback);
	auto feedbackOatpp = feedbackService.updateAnswerByCourseOwner(mappedObject);
	FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void  banFeedback(Feedback* feedback, Feedback* newFeedback)
{
	FeedbackService feedbackService;
	auto mappedObject = FeedbackServiceMapper::mapToOatppFeedback(feedback);
	auto feedbackOatpp = feedbackService.banFeedback(mappedObject);
	FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void  unbanFeedback(int feedbackId, Feedback* newFeedback)
{
	FeedbackService feedbackService;
	auto feedbackOatpp = feedbackService.unbanFeedback(feedbackId);
	FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void  deleteFeedback(int feedbackId)
{
	FeedbackService feedbackService;
	auto feedbackOatpp = feedbackService.deleteFeedback(feedbackId);
}

