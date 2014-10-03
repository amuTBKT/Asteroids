LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := Asteroids
LOCAL_SRC_FILES := core/Game.cpp 		# classes to include
LOCAL_LDLIBS := -lGLESv2				# link libraries to use
include $(BUILD_SHARED_LIBRARY)