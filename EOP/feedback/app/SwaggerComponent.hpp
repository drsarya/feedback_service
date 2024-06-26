
#ifndef EOP_FEEDBACK_SWAGGERCOMPONENT_HPP
#define EOP_FEEDBACK_SWAGGERCOMPONENT_HPP

#include <dto/ConfigDto.hpp>

#include <oatpp-swagger/Model.hpp>
#include <oatpp-swagger/Resources.hpp>
#include <oatpp/core/utils/ConversionUtils.hpp>
#include <oatpp/core/macro/component.hpp>

class SwaggerComponent {
public:
  
  /**
   *  General API docs info
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)([] {
    OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component
    
    oatpp::swagger::DocumentInfo::Builder builder;
    
    builder
    .setTitle("Feedback service")
    .setVersion("1.0")
    .setContactUrl("https://oatpp.io/")
    .addServer("http://localhost:" + oatpp::utils::conversion::int32ToStr(config->port), "server on localhost");
    
    return builder.build();
    
  }());
  
  
  /**
   *  Swagger-Ui Resources (<oatpp-examples>/lib/oatpp-swagger/res)
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
    return oatpp::swagger::Resources::loadResources(OATPP_SWAGGER_RES_PATH);
  }());
  
};

#endif /* EOP_FEEDBACK_SWAGGERCOMPONENT_HPP */
