#!/bin/bash

find src/ test/ -name "*.c" -o -name "*.h" | xargs clang-format -i