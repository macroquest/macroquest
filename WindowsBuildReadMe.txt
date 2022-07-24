*Windows build instructions as of July 23 2022

## How To Build

### Prererequisites
* [Visual Studio 2019/2022 Community](https://visualstudio.microsoft.com/downloads/)
* When Installing Visual Studio 2022 Also Be sure to install MSVC v142 - VS2019 c++ x86/x64 build tools as part of the installation. https://docs.macroquest.org/main/building/
* [Git for Windows](https://git-scm.com/)


[Windows Setup]
Now Download https://git-scm.com/downloads Latest Release for windows 64bit  2.xx.x 
Install .. Add select windows cmd when given the option you must have the following response in CMD or it did not install properly 
Test git in windows cmd 
In cmd prompt type: git version 
Response: git version 2.XX.X.windows.X

Download Visual Studio 2022 
Select workloads desktop development with C++ 
Select individual components add selection check > MSVC v142 - VS2019++ x64/x86 build tools (v14.29-16.11) {You can do this after install by reopening the installer}

Next create a new folder in windows with no spaces then go to the directory in cmd
Enter the following (HTTPS) 
git clone https://github.com/macroquest/macroquest.git

cd macroquest

If building for the EMU add the following line
git checkout emu

git submodule update --init

Open macroquest.sln into vs2022
Do not retarget projects 
Click cancel 

you will see solution macroquest in the solutions explorer 
then select release and win32 in the Middle of the top bar 
emu should be already selected in the bottom right next to macroquest 
Hit build .. This should take from 30-2 hours the first time as it has to download all the libraries 


Now to add plugins 
https://gitlab.com/redguides/plugins
https://docs.macroquest.org/main/submodule-quick-list/

in cmd goto ../macroquest/plugins 
then you can paste all git submodule commands into cmd it will auto download all of them 
then add the macroquestcustom.sln to the /macroquest folder and reopen with vs2022 
this will build most (at this time All plugins may not compile for emu) 
This will also take .5-2 hours to build .. mq2nav .... 
then to build meshgenerator you must change Win32 to X64 and right click build mq2nav_meshgenerator 

main plugins 
mq2nav 
mq2melee
mq2cast
mq2moveutils
mq2eqbc
mq2twist
mq2advpath

in EQ you will need to enable plugins 
/plugins mq2XXXXXXX 


Lets update Macroquest or Emu open cmd goto /macroquest : 

git pull --rebase --autostash
git pull --recurse-submodules
git submodule update 
git stash pop

then Rebuild the Solution 