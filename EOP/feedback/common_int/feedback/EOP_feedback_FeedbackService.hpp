
#ifndef CRUD_PUBLIC_FEEDBACKSERVICE_HPP
#define CRUD_PUBLIC_FEEDBACKSERVICE_HPP

#include <dto/EOP_feedback_FeedbackDto.hpp>
#include <service/EOP_feedback_FeedbackService.hpp>

#include <oatpp/core/macro/component.hpp>

class FeedbackServiceMapper {

public:

	static	oatpp::Object<FeedbackDto> mapToOatppFeedback(const Feedback* dto);
	static void fromDtoToFeedback(const oatpp::Object<FeedbackDto>& dto, Feedback* feedback);

};

#endif //CRUD_PUBLIC_FEEDBACKSERVICE_HPP

