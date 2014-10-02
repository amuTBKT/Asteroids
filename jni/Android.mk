LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := Asteroids
LOCAL_SRC_FILES := Game.cpp 		# name of classes to include
LOCAL_LDLIBS := -lGLESv2
include $(BUILD_SHARED_LIBRARY)