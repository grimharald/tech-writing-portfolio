=========================
Pi Zero 2 W Headless Setup
=========================

A `Pi Zero 2 W <https://www.raspberrypi.com/products/raspberry-pi-zero-2-w/>`_ is your pocket sized little brother of the `Raspberry Pi <https://www.raspberrypi.com/>`+.

An even smaller Single board computer, it can be used for a lot a fun little projects such as:

* A  small form factor `WiFi extender <https://hackaday.io/project/171296-truly-wifi-extender>`_. 
* A mini `ad-blocker using Pi-hole <https://pi-hole.net/>`_.
* A fun `video looper <https://alexasteinbruck.medium.com/how-to-configure-your-raspberry-pi-zero-to-play-videos-in-a-loop-cheap-and-flexible-solution-for-42f7744ed5c5>`_.
* `Many many others <https://hackaday.io/projects?page=1&tag=raspberry%20pi%20zero>`_.

Due to its small form factor, and comparatively weak HDMI signal, it's practical, even desirable, to set up a pi zero without a monitor using its headless features. 
This document serves as a guide to precisely that process. 

Step 1. Acquiring your Operating System
=======================================

Generally, Raspberry Pi products run their OS from the micro SD card kept in the slot. 
So, before starting your Pi Zero up, you need to flash the OS to an SD card.

This process uses the Raspberry Pi OS, for the sake of simplicity:

1.  Go to the `Pi software page <https://www.raspberrypi.com/software/>`_ and download and install the Raspberry Pi imager: 

.. image:: images/pi-image-download.png

2.  Open it to begin the image flashing process:

.. image:: images/pi-imager.png

3. Click `Choose Device` and select `Raspberry Pi Zero 2 W`

.. image:: images/select-image-device.png

4. Click `Operating System` and select the recommended OS suggested by the imager.

.. image:: images/select-os-imager.png

5. Select next to open the `Use OS customisation?` prompt, and select `Edit Settings`.

.. image:: images/imager-os-customisation.png
    
6. Check the `Set username and password`, `Configure wireless LAN`, and `Set locale settings` boxes, and input the correct details.
   * Under `Configure wireless LAN` input the name of the wireless network under `SSID` and the password for that network.
   * This will be necessary for the headless setup process.

.. image:: images/os-edit.png 

7. Click `Save` on the customisation page, and then `Yes` on customisation prompt.

8. Confirm that you want the SD card to be written to and formatted, and wait for the process to finish.

9. Remove the SD card when prompted.

Step 2. Installing Your OS
==========================