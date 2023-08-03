# DITA-XML CV

This folder contains a DITA-XML CV, presented for technical demonstration. 

It includes:
- The DITA map and content files; `huwCV.ditmap` and `profile.dite`.
- The pdf in the `out` folder.   
- All the required files to generate. 

To Generate: 

- Install DITA Open Toolkit, using the guide [here](https://www.dita-ot.org/dev/topics/installing-client).
- Download these files, apart from `out`. Alternatively, clone this whole repository.
- Open a terminal and use `cd` command to navigate to the destination for the downloaded or cloned files. 
- In the location type `dita -input=huwCV.ditmap -format=pdf`
- Open `out` folder to find generated pdf. 
- Open pdf to view generated CV. 

**NOTE: This guide will generate the CV in a book like format with a title page and contents. This is due to it using the default DITA-OT output** 