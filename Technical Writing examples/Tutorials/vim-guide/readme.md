#  Vim - A Beginner's Guide

Vim, or vi improved, is an open-source text editor which is favoured by experienced many engineers and developers due to its minimal interface and features that allow for fast coding.

Vim has a steep learning curve, but once mastered, can serve as a quick interface for updating code from your command line terminal. 

This guide serves as a beginner's introduction to installing, navigating, and using Vim for coding. 

## Installation

Depending on your operating system, Vim may already be installed "out of the box" on your system. To test this open your terminal and input the following command:


````sh
vim --version
````

If vim is already installed, you will receive a terminal printout along these lines:

````sh
VIM - Vi IMproved <version number> (<Today date>, compiled <date compiled> <time compiled>)
Included patches: 1-2167
Compiled by <Your OS>
````
Followed by a features list, with your included features marked with `+`, and excluded features marked with a `-`.

If your system does not have vim installed, your terminal will return a message resembling `vim command not found` or `command not found "vim"`. 
In this case, follow the relevant following chapter to install vim on your system. 

# Installing Vim in Windows

In Windows, it is easiest to install Vim from an [executable file (.exe)](https://www.techtarget.com/whatis/definition/executable-file-exe-file). 
Download the relevant executable file from the [Vim downloads page](https://www.vim.org/download.php), and double-click to run it. 

The system will  probably prompt you with a permissions prompt, accept this to continue. 

Vim will now open a Windows installation wizard, beginning with a select language prompt page. 

![](images/vim-language-prompt.png =250x)

