#!/bin/bash

APP_NAME=`basename $0 | cut -d'.' -f1`
if [ "$#" -gt 0 ]; then
    APP_CMD="${APP_NAME} $*"
else
    APP_CMD="${APP_NAME}"
fi
PID_FILE="${APP_NAME}_$(basename "$1").pid"
LOG_FILE="${APP_NAME}_$(basename "$1").log"

log() {
    echo "[$(date +'%Y-%m-%d %H:%M:%S')] [${APP_CMD}] $1" >> "${LOG_FILE}"
}

status_process() {
    num=`ps aux | grep -w "${APP_CMD}" | grep -v grep | grep -v "${APP_NAME}.sh" | wc -l`
    if [ "${num}" -eq "0" ]; then
        return 1
    else
        return 0
    fi
}

start_process() {
    nohup ./${APP_CMD} &
    echo $! > "${PID_FILE}"
}

stop_process() {
    while true ; do
        if status_process; then
            if [ -f "${PID_FILE}" ]; then
                kill "$(cat "${PID_FILE}")"
                log "kill $(cat "${PID_FILE}")"
            else
                log "no pid file"
                break
            fi
        else
            break
        fi
        sleep 3s
    done
    rm -f "${PID_FILE}"
    log "========= END ========="
}

log "========= BEGIN ========="
log "APP_NAME: ${APP_NAME}"
log "APP_CMD: ${APP_CMD}"
log "PID_FILE: ${PID_FILE}"
log "LOG_FILE: ${LOG_FILE}"

trap 'stop_process; exit' SIGINT SIGTERM

while true ; do
    if ! status_process; then
        log "i protect ${APP_NAME}"
        start_process
    fi
    sleep 10s
done
