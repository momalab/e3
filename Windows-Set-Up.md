# Windows Set Up Guideline

Setting up the environment variables is the key to using E<sup>3</sup> in Windows environment. E<sup>3</sup> is supported in various command line tools (i.e. Command Prompt, Powershell, Cygwin). You also need Microsoft compiler to build C/C++ programs.

This installation guideline consists of three parts: 
- [setting up environment variables](#Setting-Up-Environment-Variables)
- [setting up Microsoft compiler](#Setting-Up-Microsoft-Compiler-(cl))
- [setting up Cygwin](#Setting-Up-Cygwin)

## Setting Up Environment Variables
Make sure you have downloaded and installed required tools: **git, make, bash**, and **Microsoft compiler**. After that, you can easily set up, edit, and add the environment variables:

1. Open Control Panel > System > Advanced system settings
2. In the System Properties dialog, click Advanced > Environment Variables...
3. You can either edit User variables or System variables. If you only need the commands for your own user account, then edit the user variable. If you need it to work across the computer system regardless of which user is logged in, then edit the system variable.
4. Click on **PATH** and then on Edit and add the directory. For example, add 'C:\msysgit\bin'.
5. Add **INCLUDE** and **LIB** variables as well. If you do not have them already, click on New and add them.

PATH variable is usually linked to /bin/ directory, INCLUDE to /include/ directory, and LIB to /lib/ directory. For example, if your msysgit directory contains the necessary tools,

**Add to PATH:**  
C:\msysgit\bin

**Add to INCLUDE:**  
C:\msysgit\incude

**Add to LIB:**  
C:\msysgit\lib

## Setting Up Microsoft Compiler (cl)
### Visual Studio 2017
E<sup>3</sup> uses the Visual Studio 2017. When installing the software, make sure you have included following packages/components:

Workloads:
- **Desktop development with C++**

Individaul components:
- **Windows Universal CRT SDK**
- **Windows 10 SDK (10.0.10240.0)**

If you already have the Visual Studio 2017 installed, you can add additional packages by 'Modify'ing from the 'Visual Studio Installer' application. Installing or modifying Visual Studio 2017 might take a few minutes.

### Setting Up Environment Variables for Microsoft Compiler
While the compilers can be used from Cygwin, you need to set the environment variables manually. You can do so in 'Edit the system environment variables', which can be found in Start Search. Detailed instructions are given [here](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/).

Assuming the compiler is installed in the default location, this should work for the Visual Studio 2017 and the Windows SDK 10.0.10240.0 in Windows 10:

**Add to PATH:**  
C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.16.27023\bin\Hostx86\x86  
C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Bin  
C:\Program Files (x86)\Windows Kits\10\bin\x86\ucrt  

**Add to INCLUDE:**  
C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.16.27023\include  
C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include  
C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt  

**Add to LIB:**  
C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.16.27023\lib\x86  
C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib  
C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt\x86  

Now when you type 'cl' in Cygwin window, following message should appear:
```
Microsoft (R) C/C++ Optimizing Compiler Version 19.16.27032.1 for x86
Copyrights (C) Microsoft Corporation. All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
```

## Setting Up Cygwin
Cygwin is a collection of GNU and Open Source tools that provide a Linux-like environment for Windows: using it you can install and use llvm (which includes the GCC compilers), Clang (which includes Clang compilers), GDB (a debugger used by both compilers), and make/cmake (tools that which we use to specify how to build -compile and link- C++ programs). Cygwin and its toolset occupy about 2.5 GB on disk. Detailed instructions on installing packages for Cygwin can be found [here](https://www.ics.uci.edu/~pattis/common/handouts/cygwinclion/cygwin.html).

1. Download Cygwin [here](https://www.ics.uci.edu/~pattis/common/handouts/cygwinclion/cygwin.html).
2. Run the downloaded file
3. Follow the setup program
4. In the 'Select Packages' window, you will select additional packages to install.
In the **View** pull-down list, select **Category**. Enter the tool names and select **Install** in the **New** pull-down list for **Devel** package.  
Here, you will select **git**, **cl**, and **make** packages.

Installing Cygwin might take a few minutes.

## Check if Tools are available

Make sure that the following commands run in your Windows console shell:
```bash
$ cl
Microsoft (R) C/C++ Optimizing Compiler Version [version number] for [architecture type]
Copyright (C) Microsoft Corporation.  All rights reserved.
usage: cl [ option... ] filename... [ /link linkoption... ]
```
```bash
$ sh --help
GNU bash, version [version number (>=3.1.23)]
```
```bash
$ make -v
GNU Make version [version number (>=3.79.1)]
```

If you have succesfully installed and set up the tools above, you are ready to use E<sup>3</sup> in Windows!
