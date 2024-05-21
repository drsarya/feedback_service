
#ifndef CRUD_PUBLIC_FEEDBACKNOTIFICATIONSERVICE_HPP
#define CRUD_PUBLIC_FEEDBACKNOTIFICATIONSERVICE_HPP

#include <service/EOP_feedback_FeedbackNotificationService.hpp>

#include "oatpp/core/macro/component.hpp"

class FeedbackServiceMapper {
public:
	static oatpp::Object<FeedbackNotificationDto> mapToOatppFeedbackNotification(const FeedbackNotification* dto);
	static void fromDtoToFeedbackNotification(const oatpp::Object<FeedbackNotificationDto>& dto, FeedbackNotification* feedbackNotification);
};

#endif //CRUD_PUBLIC_FEEDBACKSERVICE_HPP
