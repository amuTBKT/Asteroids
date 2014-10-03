LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := Asteroids

FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
#FILE_LIST += $(wildcard $(LOCAL_PATH)/**/*.cpp)
#FILE_LIST += $(wildcard $(LOCAL_PATH)/**/**/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

#LOCAL_SRC_FILES := core/Game.cpp 			# classes to include
LOCAL_LDLIBS := -lGLESv2 -llog				# link libraries to use
include $(BUILD_SHARED_LIBRARY)