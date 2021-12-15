# Setup Raspberry pi

- Step- 1 > sudo snap install rpi-imager

    - Download the lite version with 0.5 GB > In my case

- Step- 2 > Create "wpa_wpa_supplicant.conf" file in boot folder and write the detail of your hotspot as follows:

            country=IN
            update_config=1
            ctrl_interface=/var/run/wpa_supplicant
            network={
                    scan_ssid=1
                    ssid="MyNetworkSSID"
                    psk="Pa55w0rd1234"
                    }

- Step- 3 > Create "SSH" file name.

## NOW YOU ARE READY WITH YOUR SETUP AND PUT THAT MICRO SD CARD IN YOUR BRAD NEW RASPBERRY PI.

- ssh pi@ipaddress_of_raspberry_pi : To access shell of raspberry pi in linux terminal and use "exit" to exit from raspberry_pi.