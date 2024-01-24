=========================
Pi Zero 2 W Headless Setup
=========================

A `Pi Zero 2 W <https://www.raspberrypi.com/products/raspberry-pi-zero-2-w/>`_ is your pocket sized little brother of the `Raspberry Pi <https://www.raspberrypi.com/>`_.

An even smaller Single board computer, it can be used for a lot a fun little projects such as:

* A  small form factor `WiFi extender <https://hackaday.io/project/171296-truly-wifi-extender>`_. 
* A mini `ad-blocker using Pi-hole <https://pi-hole.net/>`_.
* A fun `video looper <https://alexasteinbruck.medium.com/how-to-configure-your-raspberry-pi-zero-to-play-videos-in-a-loop-cheap-and-flexible-solution-for-42f7744ed5c5>`_.
* `Many many others <https://hackaday.io/projects?page=1&tag=raspberry%20pi%20zero>`_.

Due to its small form factor, and comparatively weak HDMI signal, it's practical, even desirable, to set up a pi zero without a monitor using its headless features. 
This document serves as a guide to precisely that process. 

Acquiring your Operating System
===============================

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

7. Open the `Services Tab` and check `Enable SSH` and select `Use password authentication`.

.. image:: images/services-os-edit-tab.png

8. Click `Save` on the edit customisation popup, and then `Yes` on customisation prompt.

9.  Confirm that you want the SD card to be written to and formatted, and wait for the process to finish.

10.  Remove the SD card when prompted.

Installing Your OS
==================

This process is relatively simple; insert SD card into the Pi Zero W's SD card slot and plug it in to start it up. 

As it starts up, it will set up Raspberry Pi OS according to the settings defined in the OS customisation.

Connect to the Raspberry Pi Zero 2 W with SSH
=============================================

The Pi Zero will connect to the WiFi automatically due to the set up in the first chapter. 

Now, take another computer and start it up. As long as both this PC and the Pi zero are on the same WiFi, you can can access the Pi using SSH.

To use SSH, you first need to install `Putty <https://www.chiark.greenend.org.uk/~sgtatham/putty/>`_, an SSH client. 

To install on Windows, download the `installer <https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html_>`_. 
For Linux, see `these installation instructions <https://www.ssh.com/academy/ssh/putty/linux>`_, and follow `these instructions <https://www.ssh.com/academy/ssh/putty/mac>`_ for Mac.

To use Putty to set up your headless Zero 2 W: 

1. Open Putty, to bring up the start up page. 

   * At this point, Windows will probably generate a security prompt, Click `Ok` to continue.
   * Linux and MacOS may prompt you similarly.

.. image:: images/putty-open-tab.png

1. Ensure the ``SSH`` field is selected an input ``raspberrypi`` in the ``Host Name (or IP address)``. Then click ``Open``. (The port will default to ``22``).

.. image:: images/putty-open-tab.png

1. Enter the username and password defined in the first step.

.. image:: images/putty-login.png

This will open the Command line interface of your Pi Zero 2 W. Next, we need to enable VNC, to get to the UI.

Set Up VNC Access
================

First, run the following command in the Pi CLI:

   sudo raspi-config

This will open the BIOS configuration, where you can set up VNC access: 

1. Using the keyboard, highlight ``Interface Options`` and press Enter. 
2. Highlight ``VNC`` and press Enter.
3. When the ``Would you like the VNC server to be enabled?`` prompt appears, navigate to ``<Yes>`` and press Enter. 
4. Press Enter again when the ``<Ok>`` prompt appears.
5. You will be redirected to the BIOS configuration page, highlight `Finish` at the bottom and press Enter.

This has set the Pi up to allow VNC access, but you need to install a VNC viewer on the PC you want to access the Pi from, such as `Tiger VNC <https://tigervnc.org/>`_.
Download it `here <https://github.com/TigerVNC/tigervnc/releases>`_, or install it from your command line using your package manager in Linux.

Now, follow these steps:

1. Open TigerVNC, and the prompt will appear.

.. image:: images/vnc-open.png

2. Input the server name, mostly likely ``raspberrypi.local``, then click ``Connect``.

   * Click `Yes` if a certificate prompt appears.

.. image:: images/vnc-input.png

3. Input your username and password, set up in the first chapter.

4. The Pi OS will open in your TigerVNC window. 

.. image:: images/pi-os-splash.jpg

You can now access your headless using TigerVNC, and use your Pi remotely from the PC used to set this up. 
You can also install TigerVNC on other PCs and access the Pi using the same credentials.