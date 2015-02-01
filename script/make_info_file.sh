#! /bin/bash
# make_info_file.sh : make /etc/info.ini
#

if [ $# -lt 2 -o $# -gt "3" ]; then
	echo "Usage : make_info_file.sh [model] [build] {operator}"
        exit
fi

MODEL=$1
BUILD=$2
if [ $# == 3 ]; then
	OPERATOR=$3
else
	OPERATOR=""
fi

cat >/etc/info.ini <<EOF
[Version]
Model=$MODEL;
Build=$BUILD;
Operator=$OPERATOR;
[Build]
Date=`date +%Y.%m.%d`;
Time=`date +%H:%M:%S`;
EOF
