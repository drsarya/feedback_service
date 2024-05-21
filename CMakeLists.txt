cmake_minimum_required(VERSION 3.1)

set(project_name eop_feedback)

project(${project_name})

set(CMAKE_CXX_STANDARD 11)

add_library(${project_name}-lib

    EOP/feedback/app/ErrorHandler.cpp
    EOP/feedback/app/init.cpp

    EOP/feedback/common_int/feedback/EOP_feedback_FeedbackService.c
    EOP/feedback/common_int/feedback/EOP_feedback_FeedbackService.cpp
    EOP/feedback/common_int/feedback_notification/EOP_feedback_FeedbackNotificationService.c
    EOP/feedback/common_int/feedback_notification/EOP_feedback_FeedbackNotificationService.cpp

    EOP/feedback/service/EOP_feedback_FeedbackNotificationService.cpp
    EOP/feedback/service/EOP_feedback_FeedbackService.cpp
    )

target_include_directories(${project_name}-lib PUBLIC EOP/feedback

    EOP/feedback/app/AppComponent.hpp
    EOP/feedback/app/DatabaseComponent.hpp
    EOP/feedback/app/ErrorHandler.hpp
    EOP/feedback/app/ServiceComponent.hpp
    EOP/feedback/app/SwaggerComponent.hpp
    EOP/feedback/app/init.h
    EOP/feedback/app/init.hpp

    EOP/feedback/common_int/feedback_notification/EOP_feedback_FeedbackNotificationService.hpp
    EOP/feedback/common_int/feedback/EOP_feedback_FeedbackService.hpp

    EOP/feedback/controller/EOP_feedback_FeedbackController.hpp
    EOP/feedback/controller/EOP_feedback_FeedbackNotificationController.hpp

    EOP/feedback/db/EOP_feedback_FeedbackDb.hpp
    EOP/feedback/db/EOP_feedback_FeedbackNotificationDb.hpp

    EOP/feedback/dto/ConfigDto.hpp
    EOP/feedback/dto/EOP_feedback_FeedbackDto.hpp
    EOP/feedback/dto/EOP_feedback_FeedbackNotificationDto.hpp
    EOP/feedback/dto/PageDto.hpp
    EOP/feedback/dto/StatusDto.hpp

    EOP/feedback/service/EOP_feedback_FeedbackNotificationService.hpp
    EOP/feedback/service/EOP_feedback_FeedbackService.hpp

    EOP/feedback/EOP_feedback_FeedbackService.h
    EOP/feedback/EOP_feedback_FeedbackNotificationService.h
)

## link libs

find_package(oatpp              1.3.0 REQUIRED)
find_package(oatpp-swagger      1.3.0 REQUIRED)
find_package(oatpp-postgresql   1.3.0 REQUIRED)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC oatpp::oatpp-swagger
        PUBLIC oatpp::oatpp-postgresql
)

add_definitions(
        # Path to swagger-ui resources #
        -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"

        # Path to config file #
        -DCONFIG_PATH="${CMAKE_CURRENT_LIST_DIR}/resources/config.json"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)

#################################################################
## add executables

add_executable(${project_name}-exe
        "EOP/feedback/main.c"  )
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

 
