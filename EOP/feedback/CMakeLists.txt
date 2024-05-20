cmake_minimum_required(VERSION 3.1)

set(project_name eop_feedback)

project(${project_name})

set(CMAKE_CXX_STANDARD 11)

add_library(${project_name}-lib

    src/service/EOP_feedback_FeedbackNotificationService.cpp
    src/service/EOP_feedback_FeedbackService.cpp
    src/common_int/feedback/EOP_feedback_FeedbackService.c
    src/common_int/feedback/EOP_feedback_FeedbackService.cpp
    src/common_int/feedback_notification/EOP_feedback_FeedbackNotificationService.c
    src/common_int/feedback_notification/EOP_feedback_FeedbackNotificationService.cpp
    src/ErrorHandler.cpp  
    src/init.cpp )

target_include_directories(${project_name}-lib PUBLIC src

    src/init.h
    src/init.hpp
    src/controller/EOP_feedback_FeedbackController.hpp
    src/controller/EOP_feedback_FeedbackNotificationController.hpp
    src/db/EOP_feedback_FeedbackDb.hpp
    src/db/EOP_feedback_FeedbackNotificationDb.hpp
    src/dto/EOP_feedback_FeedbackDto.hpp
    src/dto/EOP_feedback_FeedbackNotificationDto.hpp
    src/service/EOP_feedback_FeedbackNotificationService.hpp
    src/service/EOP_feedback_FeedbackService.hpp
    src/common_int/feedback/EOP_feedback_FeedbackService.hpp
    src/common_int/feedback/EOP_feedback_FeedbackService.h
    src/common_int/feedback_notification/EOP_feedback_FeedbackNotificationService.h
    src/common_int/feedback_notification/EOP_feedback_FeedbackNotificationService.hpp
    src/dto/ConfigDto.hpp
    src/dto/PageDto.hpp
    src/dto/StatusDto.hpp
    src/AppComponent.hpp
    src/DatabaseComponent.hpp
    src/ErrorHandler.hpp
    src/ServiceComponent.hpp
    src/SwaggerComponent.hpp
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
        "src/App.c"  )
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

 
