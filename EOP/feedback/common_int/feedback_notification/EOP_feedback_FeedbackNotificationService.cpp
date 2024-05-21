#include <common_int/feedback_notification/EOP_feedback_FeedbackNotificationService.h>
#include <common_int/feedback_notification/EOP_feedback_FeedbackNotificationService.hpp>


oatpp::Object<FeedbackNotificationDto> FeedbackServiceMapper::mapToOatppFeedbackNotification(const FeedbackNotification* dto) {
	oatpp::Object<FeedbackNotificationDto> feedbackNotificationDto;

	feedbackNotificationDto->id = dto->id;
	feedbackNotificationDto->feedbackId = dto->feedbackId;
	feedbackNotificationDto->userId = dto->userId;
	feedbackNotificationDto->description = dto->description;
	feedbackNotificationDto->notificationStatus = dto->notificationStatus;
	feedbackNotificationDto->creationDate = dto->creationDate;

	return feedbackNotificationDto;
}

void FeedbackServiceMapper::fromDtoToFeedbackNotification(const oatpp::Object<FeedbackNotificationDto>& dto, FeedbackNotification* feedbackNotification) {
	feedbackNotification->id = dto->id;
	feedbackNotification->feedbackId = dto->feedbackId;
	feedbackNotification->userId = (char*)dto->userId->c_str();
	feedbackNotification->description = (char*)dto->description->c_str();
	feedbackNotification->notificationStatus = dto->notificationStatus;
	feedbackNotification->creationDate = (char*)dto->creationDate->c_str();
}

void  createNotificationFeedback(FeedbackNotification* notification, FeedbackNotification* newNotification) {
	FeedbackNotificationService feedbackNotificationService;
	auto mappedObject = FeedbackServiceMapper::mapToOatppFeedbackNotification(notification);
	auto notificationOatpp = feedbackNotificationService.createNotificationFeedback(mappedObject);
	FeedbackServiceMapper::fromDtoToFeedbackNotification(notificationOatpp, newNotification);
}

void  getNotificationById(int id, FeedbackNotification* newNotification) {
	FeedbackNotificationService feedbackNotificationService;
	auto notificationOatpp = feedbackNotificationService.getNotificationById(id);
	FeedbackServiceMapper::fromDtoToFeedbackNotification(notificationOatpp, newNotification);
}

void  readNotificationFeedback(int id, FeedbackNotification* newNotification) {
	FeedbackNotificationService feedbackNotificationService;
	auto notificationOatpp = feedbackNotificationService.readNotificationFeedback(id);
	FeedbackServiceMapper::fromDtoToFeedbackNotification(notificationOatpp, newNotification);
}

void  getNotificationsForUserId(char* userId, FeedbackNotification* notifications) {
	FeedbackNotificationService feedbackNotificationService;
	auto feedbackOatpp = feedbackNotificationService.getNotificationsForUserId(userId);
	std::vector<FeedbackNotification> vect;
	for (int i = 0; i < feedbackOatpp->size(); i++) {
		FeedbackNotification feedback;
		FeedbackServiceMapper::fromDtoToFeedbackNotification(feedbackOatpp[i], &feedback);
		vect.push_back(feedback);
	}
	notifications = &vect[0];
}

void  deleteReadNotifications() {
	FeedbackNotificationService feedbackNotificationService;
	feedbackNotificationService.deleteReadNotifications();
}

