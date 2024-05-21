FROM alpine:latest
RUN apk update && apk upgrade
RUN apk add postgresql-dev
RUN apk add g++
RUN apk add git
RUN apk add make
RUN apk add cmake

ADD EOP/feedback /service

WORKDIR /service/utility

RUN ./install-oatpp-modules.sh Release

WORKDIR /service/build

RUN cmake ..
RUN make

EXPOSE 8000 8000

ENTRYPOINT ["./eop_feedback-exe"]