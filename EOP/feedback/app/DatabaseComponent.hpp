
#ifndef EOP_FEEDBACK_DATABASECOMPONENT_HPP
#define EOP_FEEDBACK_DATABASECOMPONENT_HPP

#include <dto/ConfigDto.hpp>
#include <db/EOP_feedback_FeedbackDb.hpp>
#include <db/EOP_feedback_FeedbackNotificationDb.hpp>


class DatabaseComponent {
public:

  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::postgresql::Connection>>, dbConnectionProvider)([] {

      /* Create database-specific ConnectionProvider */
       OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

           /* Create database-specific ConnectionProvider */
       auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->dbConnectionString);

      /* Create database-specific ConnectionPool */
      return oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
          10 /* max-connections */,
          std::chrono::seconds(5) /* connection TTL */);

    }());

/**
   * Create database client
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<FeedbackNotificatonDb>, feedbackNotificationDb)([] {

      /* Get database ConnectionProvider component */
      OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::postgresql::Connection>>, connectionProvider);

      /* Create database-specific Executor */
      auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionProvider);

      /* Create MyClient database client */
      return std::make_shared<FeedbackNotificatonDb>(executor);

      }());


   /**
    * Create database client
    */
   OATPP_CREATE_COMPONENT(std::shared_ptr<FeedbackDb>, feedbackDb)([] {

       /* Get database ConnectionProvider component */
       OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::postgresql::Connection>>, connectionProvider);

       /* Create database-specific Executor */
       auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionProvider);

       /* Create MyClient database client */
       return std::make_shared<FeedbackDb>(executor);

       }());



};

#endif //EOP_FEEDBACK_DATABASECOMPONENT_HPP
