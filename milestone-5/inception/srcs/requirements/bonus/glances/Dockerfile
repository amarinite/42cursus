FROM alpine:3.22

RUN apk update && apk upgrade && \
    apk add --no-cache \
    python3 \
    py3-pip \
    py3-psutil \
    py3-dateutil \
    py3-setuptools && \
    pip install glances docker fastapi uvicorn --break-system-packages

EXPOSE 61208

ENTRYPOINT ["glances", "-w", "-p", "61208"]
