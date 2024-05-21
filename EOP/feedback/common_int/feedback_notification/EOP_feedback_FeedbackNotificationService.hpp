
#ifndef EOP_FEEDBACK_PUBLIC_FEEDBACKNOTIFICATIONSERVICE_HPP
#define EOP_FEEDBACK_PUBLIC_FEEDBACKNOTIFICATIONSERVICE_HPP

#include <service/EOP_feedback_FeedbackNotificationService.hpp>

#include "oatpp/core/macro/component.hpp"

class FeedbackServiceMapper {
public:
	static oatpp::Object<FeedbackNotificationDto> mapToOatppFeedbackNotification(const FeedbackNotification* dto);
	static void fromDtoToFeedbackNotification(const oatpp::Object<FeedbackNotificationDto>& dto, FeedbackNotification* feedbackNotification);
};

#endif //EOP_FEEDBACK_PUBLIC_FEEDBACKNOTIFICATIONSERVICE_HPP
