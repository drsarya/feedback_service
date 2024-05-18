# Сервис обратной связи для курса

Предоставляет АПИ по созданию обратной связи
 
## Overview

This project is using the following oatpp modules:

- [oatpp](https://github.com/oatpp/oatpp) 
- [oatpp-swagger](https://github.com/oatpp/oatpp-swagger)
- [oatpp-postgresql](https://github.com/oatpp/oatpp-postgresql)

### Project layout

```
|- CMakeLists.txt                        // projects CMakeLists.txt
|- src/
|    |
|    |- controller/                      // Folder containing Controller where all endpoints are declared
|    |- db/                              // Folder containing the database client
|    |- dto/                             // DTOs are declared here
|    |- service/                         // Service business logic classes (UserService)
|    |- ServiceComponent.hpp             // Service configuration (port, ObjectMapper, Database)
|    |- SwaggerComponent.hpp             // Configuration for swagger-ui
|    |- AppComponent.hpp                 // Service configuration is loaded here
|    |- DatabaseComponent.hpp            // Database config
|    |- App.cpp                          // main() is here
|    
|- test/                                 // test folder
|- utility/install-oatpp-modules.sh      // utility script to install required oatpp-modules.
|- resources/config.json                 // configuration file with configuration profiles
|- Dockerfile                            // Dockerfile
|- docker-compose.yaml                   // Docker-compose with this service and postgresql
```

---

## Build and Run

### Using CMake

**Requires** 

- This example also requires the PostgreSQL package installed.
   - On Alpine `$ apk add postgresql-dev`
   - On Ubuntu `$ apt-get install postgresql-server-dev-all`
   - On Windows : `set(PostgreSQL_INCLUDE_DIR "E:\\program\\Postgresql\\include")`  in **utility/tmp/oatpp-postgresql/CMakeList.txt**
   
   For more info see [oatpp-postgresql/README.md](https://github.com/oatpp/oatpp-postgresql/blob/master/README.md)
- `oatpp`, `oatpp-swagger` and `oatpp-postgresql` modules installed. You may run `utility/install-oatpp-modules.sh` 
script to install required oatpp modules.   

```
$ mkdir build && cd build
$ cmake ..
$ make 
$ ./EOP_feedback-exe  # - run application.
```

*PostgreSQL is expected running as for `dev` config profile*

### In Docker

#### Dockerfile

```
$ docker build -t eop_feedback .
$ docker run -p 8000:8000 -e CONFIG_PROFILE='dev' -t eop_feedback
```

#### docker-compose

```
$ docker-compose up
```

*docker-compose will run service with `local-docker` config profile*

### After run

Go to [http://localhost:8000/swagger/ui](http://localhost:8000/swagger/ui) to try endpoints.

