    #!/bin/bash

    gnome-terminal -e $PWD/RTT/runJLinkExe-nrf52
    sleep 2
    gnome-terminal -e $PWD/RTT/runJLinkRTTClient
  