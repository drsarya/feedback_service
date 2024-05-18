FROM lganzzzo/alpine-cmake:latest

RUN apk add postgresql-dev

RUN apk update && apk upgrade

RUN apk add g++

RUN apk add git
RUN apk add make
RUN apk add cmake

COPY  . /service

WORKDIR /service/utility

RUN ls /service/utility/tmp
RUN /service/utility/install-oatpp-modules.sh

WORKDIR /service/build

RUN cmake ..
RUN cmake --build .

EXPOSE 8000 8000

ENTRYPOINT ["./eop_feedback-exe"]
