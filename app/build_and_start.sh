#!/bin/sh

SCRIPT_DIR=$(dirname $(readlink -f $0))

echo $SCRIPT_DIR

build () {
    (cd ${SCRIPT_DIR}; mkdir -p build)
    (cd ${SCRIPT_DIR}/build; cmake .. && cmake --build .)
}

run() {
    ${SCRIPT_DIR}/build/src/${PROJECT_NAME}
    #dirname $(readlink -f $0)
}

build
run
