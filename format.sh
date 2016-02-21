#!/usr/bin/env sh
find . -type f -regex ".*\.\(cpp\|h\)" | xargs ./clang-format -i -style=file
