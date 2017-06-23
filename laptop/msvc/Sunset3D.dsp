# Microsoft Developer Studio Project File - Name="Sunset3D" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Sunset3D - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Sunset3D.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Sunset3D.mak" CFG="Sunset3D - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Sunset3D - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Sunset3D - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Sunset3D - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Sunset3D - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../resource" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib glu32.lib glaux.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../bin/Sunset3D.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Sunset3D - Win32 Release"
# Name "Sunset3D - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\source\CGLBox.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CGLCamera.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CGLLight.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CGLMaterial.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CGLMesh.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CGLObject.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CGLScene.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CGLWindow.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CMainFrame.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CWin.cpp
# End Source File
# Begin Source File

SOURCE=..\source\WinMain.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\source\CGLBox.h
# End Source File
# Begin Source File

SOURCE=..\source\CGLCamera.h
# End Source File
# Begin Source File

SOURCE=..\source\CGLLight.h
# End Source File
# Begin Source File

SOURCE=..\source\CGLMaterial.h
# End Source File
# Begin Source File

SOURCE=..\source\CGLMesh.h
# End Source File
# Begin Source File

SOURCE=..\source\CGLObject.h
# End Source File
# Begin Source File

SOURCE=..\source\CGLScene.h
# End Source File
# Begin Source File

SOURCE=..\source\CGLWindow.h
# End Source File
# Begin Source File

SOURCE=..\source\CMainFrame.h
# End Source File
# Begin Source File

SOURCE=..\source\CWin.h
# End Source File
# Begin Source File

SOURCE=..\source\fileformat.h
# End Source File
# Begin Source File

SOURCE=..\resource\resource.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\resource\icon1.ico
# End Source File
# Begin Source File

SOURCE=..\resource\resource.rc
# End Source File
# Begin Source File

SOURCE=..\resource\sunset.ico
# End Source File
# End Group
# Begin Group "inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\inc\mathlib.c
# End Source File
# Begin Source File

SOURCE=..\source\inc\mathlib.h
# End Source File
# End Group
# End Target
# End Project