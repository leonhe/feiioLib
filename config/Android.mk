LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := feiio_static
LOCAL_MODULE_FILENAME := libfeiio

LOCAL_SRC_FILES := \
ConfigFile.cpp \
ConfigManger.cpp \



LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH) \
$(LOCAL_PATH)/. \
$(LOCAL_PATH)/.. \

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
$(LOCAL_PATH)/. \

#include $(BUILD_STATIC_LIBRARY)
include $(BUILD_SHARED_LIBRARY)
