cmake_minimum_required(VERSION 3.1)

project(Sunset3D)

find_package(OpenGL REQUIRED)

add_executable(Sunset3D
    source/CGLBox.cpp
    source/CGLMaterial.cpp
    source/CGLMesh.cpp
    source/CGLModel.cpp
    source/CGLObject.cpp
    source/CGLScene.cpp
    source/CPanel.cpp
    source/CGLCamera.cpp
    source/CGLLight.cpp
    source/CGLWindow.cpp
    source/CMainFrame.cpp
    source/CWin.cpp
    source/WinMain.cpp
    source/CGLBox.h
    source/CGLMaterial.h
    source/CGLMesh.h
    source/CGLModel.h
    source/CGLObject.h
    source/CGLScene.h
    source/CPanel.h
    source/CGLCamera.h
    source/CGLLight.h
    source/CGLWindow.h
    source/CMainFrame.h
    source/CWin.h
    resource/resource.h
    resource/resource.rc
    resource/sunset.ico
    source/inc/fileformat.h
    source/inc/mathlib.c
    source/inc/mathlib.h
    source/inc/ms3dspec.h
    source/controls/CButton.cpp
    source/controls/CButton.h
    source/controls/CCheck.cpp
    source/controls/CCheck.h
    source/controls/CCombo.cpp
    source/controls/CCombo.h
    source/controls/CCommonDialogs.cpp
    source/controls/CCommonDialogs.h
    source/controls/CControl.cpp
    source/controls/CControl.h
    source/controls/CEdit.cpp
    source/controls/CEdit.h
    source/controls/CFileView.cpp
    source/controls/CFileView.h
    source/controls/CFolderView.cpp
    source/controls/CFolderView.h
    source/controls/CFrame.cpp
    source/controls/CFrame.h
    source/controls/CLabel.cpp
    source/controls/CLabel.h
    source/controls/CList.cpp
    source/controls/CList.h
    source/controls/CReportView.cpp
    source/controls/CReportView.h
    source/controls/CSlider.cpp
    source/controls/CSlider.h
    source/controls/CStatusBar.cpp
    source/controls/CStatusBar.h
    source/controls/CToolBar.cpp
    source/controls/CToolBar.h
    source/controls/CTreeView.cpp
    source/controls/CTreeView.h
    source/controls/GUI.H
    source/stb.cpp
    source/stb_image.h
    )

target_include_directories(Sunset3D
    PRIVATE resource
    )

target_link_libraries(Sunset3D
    ${OPENGL_LIBRARIES}
    winmm
    comctl32
    )

target_compile_features(Sunset3D
    PRIVATE cxx_nullptr
    )
