#!/bin/sh

run()
{
    "$@"
    if test $? -ne 0; then
	echo "Failed $@"
	exit 1
    fi
}

run ${AUTORECONF:-autoreconf} --verbose --force --install
