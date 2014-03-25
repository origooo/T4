# ~/.bashrc


# compile driver alias
alias driver='cd ~/Desktop/Project/sources/OpenDaVINCI-msv/build/apps/2014/DIT-168/project-template/driver && make install driver && cd -'
alias sdriver='cd ~/Desktop/Project/sources/OpenDaVINCI-msv/build/apps/2014/DIT-168/project-template/driver && ./driver --cid=111 --freq=1 '

# compile laneDetector alias
alias lanedetector='cd ~/Desktop/Project/sources/OpenDaVINCI-msv/build/apps/2014/DIT-168/project-template/lanedetector && make install lanedetector && cd -'
alias slanedetector='cd ~/Desktop/Project/sources/OpenDaVINCI-msv/build/apps/2014/DIT-168/project-template/lanedetector && ./lanedetector --cid=111 --freq=10'
# Open config file in sublime
alias car_config='subl /opt/msv/bin/configuration' 

# Start all alias
alias start_all='/home/msv/Desktop/scripts/./autorunMSV.sh'