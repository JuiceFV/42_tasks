#!/bin/bash
STR=$(find . -type f -name '*.sh' -exec basename {} ';')
echo ${STR//.sh/} | tr " " "\n"
