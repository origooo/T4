# Echo aliases
alias echoalias='echo -e ". \t\t\t\t[print working directory]\n.. \t\t\t\t[Up one level]\n... \t\t\t\t[Up two levels]\n.... \t\t\t\t[Up three levels]\ncwd \t\t\t\t[Print and copy working directory]\ngowd \t\t\t\t[Paste copied working directory]\n_s \t\t\t\t[git status]\n_pl \t\t\t\t[git pull ]\n_plom \t\t\t\t[git pull origin master]\n_a \t\t\t\t[git add]\n_c \t\t\t\t[git commit -m]\n_ps \t\t\t\t[git push]\n_psom \t\t\t\t[git push origin master]\n_co \t\t\t\t[git checkout]\nmsveditautorun \t\t\t[Edit MSV autorun]\nmsveditconf \t\t\t[Edit MSV Vehicle configuration]\nmsveditdriver \t\t\t[Edit Driver.cpp]\nmsveditlanedetector \t\t[Edit LaneDetector.cpp]\nmsvopendriver \t\t\t[Open folder containing Driver.cpp]\nmsvopenlanedetector \t\t[Open folder contaning LaneDetector.cpp]\nmsvautorun \t\t\t[Run MSV autorun]\nmsvrunsupercomponent \t\t[Run MSV supercomponent]\nmsvrundriver \t\t\t[Run MSV driver]\nmsvrunlanedetector \t\t[Run MSV lanedetector]\nmsvmakedriver \t\t\t[Make Driver.cpp]\nmsvmakelanedetector \t\t[Make LaneDetector.cpp]\n"'

#------------------------------------------------------------------------------
# Folder commands
#------------------------------------------------------------------------------
alias .='pwd'
alias cwd='pwd | xclip -sel clip'
alias gowd='cd | xclip -out '
alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.." 

alias ls="ls -G --color=auto"		# list
alias la="ls -Ga --color=auto"		# list all, includes dot files
alias ll="ls -Gl --color=auto"		# long list, excludes dot files
alias lla="ls -Gla --color=auto"	# long list all, includes dot files

#------------------------------------------------------------------------------
# GIT commands
#------------------------------------------------------------------------------
alias _s='git status'
alias _pl='git pull'
alias _plom='git pull origin master'
alias _a='git add'
alias _c='git commit -m'
alias _ps='git push'
alias _psom='git push origin master'
alias _co='git checkout'

#------------------------------------------------------------------------------
# MSV commands
#------------------------------------------------------------------------------
PROJECT_ROOT="/home/msv/Desktop/Project"
SYSTEM_ROOT="/opt/msv"
SCRIPT_ROOT="/home/msv/Desktop/GITs/EmbeddedGIT/Patrik/BASH scripts"

# Edit files
alias msveditautorun='subl "${SCRIPT_ROOT}/autorunMSV.sh"'
alias msveditconf='subl "${SYSTEM_ROOT}/bin/configuration"'
alias msveditdriver='subl "${PROJECT_ROOT}/sources/OpenDaVINCI-msv/apps/2014/DIT-168/project-template/driver/src/Driver.cpp"'
alias msveditlanedetector='subl "${PROJECT_ROOT}/sources/OpenDaVINCI-msv/apps/2014/DIT-168/project-template/lanedetector/src/LaneDetector.cpp"'

# Open folders
alias msvopendriver='nautilus "${PROJECT_ROOT}/sources/OpenDaVINCI-msv/apps/2014/DIT-168/project-template/driver/src"'
alias msvopenlanedetector='nautilus "${PROJECT_ROOT}/sources/OpenDaVINCI-msv/apps/2014/DIT-168/project-template/lanedetector/src"'

# Run components
alias msvautorun='cd "${SCRIPT_ROOT}" && ./autorunMSV.sh && cd -'
alias msvrunsupercomponent='cd "${SYSTEM_ROOT}/bin" && ./supercomponent --cid=111 --freq=10 && cd -'
alias msvrundriver='cd "${SCRIPT_ROOT}" && ./rundriver.sh && cd -'
alias msvrunlanedetector='cd "${SCRIPT_ROOT}" && ./runlanedetector.sh && cd -'

# Make components
alias msvmakedriver='cd "${PROJECT_ROOT}/sources/OpenDaVINCI-msv/build/apps/2014/DIT-168/project-template/driver" && make install driver && cd -'
alias msvmakelanedetector='cd "${PROJECT_ROOT}/sources/OpenDaVINCI-msv/build/apps/2014/DIT-168/project-template/lanedetector" && make install lanedetector && cd -'