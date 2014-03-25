#!/bin/bash

DIR1="/opt/msv/bin"
DIR2="/opt/msv/bin/2014/DIT-168/project-template"
CID="111"
FREQ="10"

components=("vehicle")

DELAY="1"
TAB_DELAY="10"

WINDOW_ID=$(xprop -root | grep "_NET_ACTIVE_WINDOW(WINDOW)"| awk '{print $5}')

for c in "${components[@]}"
	do
		if [ "xlanedetector" == "x${c}" ] || [ "xdriver" == "x${c}" ] ; then
				COMPONENT_PATH="${DIR2}"
			else
				COMPONENT_PATH="${DIR1}"
		fi
		wmctrl -i -a $WINDOW_ID
		xdotool key ctrl+shift+t
		xdotool sleep ${DELAY}/${TAB_DELAY}
		xdotool type "cd ${COMPONENT_PATH} && ./${c} --cid=${CID} --freq=${FREQ}"
		xdotool sleep ${DELAY}
		xdotool key Return
	done