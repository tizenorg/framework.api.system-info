/*
 * Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vconf.h>
#include <dlog.h>

#include <system_info.h>
#include <system_info_private.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif

#define LOG_TAG "TIZEN_N_SYSTEM_INFO"

#define SYSTEM_INFO_MAX -1

typedef struct {
	system_info_key_e key;
	system_info_data_type_e data_type;
	system_info_get_value_cb get_value_cb;
} system_info_s;

typedef system_info_s * system_info_h;

system_info_s system_info_table[] = {

{
	 /**< The model of the device */
	SYSTEM_INFO_KEY_MODEL,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_model
},

{
	 /**< The version of the Tizen supported by the platform */
	SYSTEM_INFO_KEY_TIZEN_VERSION,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_tizen_version
},

{
	/**< Indicates whether the device supports Bluetooth */
	SYSTEM_INFO_KEY_BLUETOOTH_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_bluetooth_supported
},

{
	/**< The number of cameras in the device */
	SYSTEM_INFO_KEY_CAMERA_COUNT,
	SYSTEM_INFO_DATA_TYPE_INT,
	system_info_get_camera_count
},

{
	/**< Indicates whether the device supports FM radio */
	SYSTEM_INFO_KEY_FMRADIO_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_fmradio_supported
},

{
	/**< Indicates whether the device supports GPS */
	SYSTEM_INFO_KEY_GPS_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_gps_supported
},

{
	/**< The type of the keyboard */
	SYSTEM_INFO_KEY_KEYBOARD_TYPE,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_keyboard_type
},

{
	/**< The maximum number of concurrent touch points supported
	in the device */
	SYSTEM_INFO_KEY_MULTI_POINT_TOUCH_COUNT,
	SYSTEM_INFO_DATA_TYPE_INT,
	system_info_get_multi_point_touch_count
},

{
	/**< The supported network type */
	SYSTEM_INFO_KEY_NETWORK_TYPE,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_network_type
},

{
	/**< Indicates whether the device supports NFC */
	SYSTEM_INFO_KEY_NFC_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_nfc_supported
},

{
	/**< The supported version of the OpenGL ES */
	SYSTEM_INFO_KEY_OPENGLES_VERSION,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_opengles_version
},

{
	/**< The number of bits per pixel */
	SYSTEM_INFO_KEY_SCREEN_BITS_PER_PIXEL,
	SYSTEM_INFO_DATA_TYPE_INT,
	system_info_get_screen_bits_per_pixel
},

{
	/**< The height of the screen in pixels */
	SYSTEM_INFO_KEY_SCREEN_HEIGHT,
	SYSTEM_INFO_DATA_TYPE_INT,
	system_info_get_screen_height
},

{
	/**< The width of the screen in pixels */
	SYSTEM_INFO_KEY_SCREEN_WIDTH,
	SYSTEM_INFO_DATA_TYPE_INT,
	system_info_get_screen_width
},

{
	/**< Indicates whether the device supports TV-out */
	SYSTEM_INFO_KEY_TVOUT_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_tvout_supported
},

{
	 /**< Indicates whether the device supports Wi-Fi */
	SYSTEM_INFO_KEY_WIFI_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_wifi_supported
},

{
	 /**< The unique ID to identify GSM, and UMTS mobile devices */
	SYSTEM_INFO_KEY_MOBILE_DEVICE_ID,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_mobile_device_id
},

{
	/**< The sales code of the CSC */
	SYSTEM_INFO_KEY_CSC_SALES_CODE,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_csc_sales_code
},

{
	/**< The Name of the Platform */
	SYSTEM_INFO_KEY_PLATFORM_NAME,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_platform_name
},

{
	/**< The Name of the Tizen version */
	SYSTEM_INFO_KEY_TIZEN_VERSION_NAME,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_tizen_version_name
},

{
	/**< Indicates whether the device supports HAPTIC */
	SYSTEM_INFO_KEY_HAPTIC_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_haptic_supproted
},

{
	/**< Indicates whether the device supports HAPTIC */
	SYSTEM_INFO_KEY_WIFI_DIRECT_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_wifi_direct_supported
},

{
	/**< The height of the screen DPI */
	SYSTEM_INFO_KEY_SCREEN_DPI,
	SYSTEM_INFO_DATA_TYPE_INT,
	system_info_get_screen_DPI
},

{
	/**< The Device unique ID to identify */
	SYSTEM_INFO_KEY_DEVICE_UUID,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_device_uuid
},

{
	/**< Indicates whether the device supports GPS */
	SYSTEM_INFO_KEY_CPS_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_cps_supported
},

{
	/**< Indicates whether the device supports GPS */
	SYSTEM_INFO_KEY_WPS_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_wps_supported
},

{
	/**< Indicates whether the device supports USB host */
	SYSTEM_INFO_KEY_USB_HOST_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_usb_host_supported
},

{
	/**< Indicates whether the device supports USB accessory */
	SYSTEM_INFO_KEY_USB_ACCESSORY_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_usb_accessory_supported
},

{
	/**< The CORE CPU architecture of model */
	SYSTEM_INFO_KEY_CORE_CPU_ARCH,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_core_cpu_arch
},

{
	/**< The CORE FPU architecture of model */
	SYSTEM_INFO_KEY_CORE_FPU_ARCH,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_core_fpu_arch
},

{
	/**< Indicates whether the device supports front camera */
	SYSTEM_INFO_KEY_FRONT_CAMERA_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_front_camera_supported
},

{
	/**< Indicates whether the device supports front camera auto focus */
	SYSTEM_INFO_KEY_FRONT_CAMERA_AF_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_front_camera_af_supported
},

{
	/**< Indicates whether the device supports front camera flash */
	SYSTEM_INFO_KEY_FRONT_CAMERA_FLASH_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_front_camera_flash_supported
},

{
	/**< Indicates whether the device supports back camera */
	SYSTEM_INFO_KEY_BACK_CAMERA_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_back_camera_supported
},

{
	/**< Indicates whether the device supports back camera auto focus */
	SYSTEM_INFO_KEY_BACK_CAMERA_AF_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_back_camera_af_supported
},

{
	/**< Indicates whether the device supports back camera flash */
	SYSTEM_INFO_KEY_BACK_CAMERA_FLASH_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_back_camera_flash_supported
},

{
	/**< Indicates whether the device supports HDMI */
	SYSTEM_INFO_KEY_HDMI_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_hdmi_supported
},

{
	/**< Indicates whether the device supports RCA */
	SYSTEM_INFO_KEY_RCA_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_rca_supported
},

{
	/**< Indicates whether the device supports SIP VOIP */
	SYSTEM_INFO_KEY_SIP_VOIP_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_sip_voip_supported
},

{
	/**< Indicates whether the device supports Microphone */
	SYSTEM_INFO_KEY_MICROPHONE_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_microphone_supported
},

{
	/**< Indicates whether the device supports stt */
	SYSTEM_INFO_KEY_SPEECH_RECOGNITION_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_speech_recognition_supported
},

{
	/**< Indicates whether the device supports barometer sensor */
	SYSTEM_INFO_KEY_BAROMETER_SENSOR_SUPPORTED,
	SYSTEM_INFO_DATA_TYPE_BOOL,
	system_info_get_barometer_sensor_supported
},

{
	/**< The supported texture format of the OpenGL ES */
	SYSTEM_INFO_KEY_OPENGLES_TEXTURE_FORMAT,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_opengles_texture_format
},

{
	/**< The CORE CPU frequency of model */
	SYSTEM_INFO_KEY_CORE_CPU_FREQ,
	SYSTEM_INFO_DATA_TYPE_DOUBLE,
	system_info_get_core_cpu_freq
},

{
	/**< The height of the physical screen size in millimeters */
	SYSTEM_INFO_KEY_PHYSICAL_SCREEN_HEIGHT,
	SYSTEM_INFO_DATA_TYPE_INT,
	system_info_get_physical_screen_height
},

{
	/**< The width of the physical screen size in millimeters */
	SYSTEM_INFO_KEY_PHYSICAL_SCREEN_WIDTH,
	SYSTEM_INFO_DATA_TYPE_INT,
	system_info_get_physical_screen_width
},

{
	/**< The build string of the platform binary */
	SYSTEM_INFO_KEY_BUILD_STRING,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_build_string
},

{
	/**< The build date of the platform binary */
	SYSTEM_INFO_KEY_BUILD_DATE,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_build_date
},

{
	/**< The build time of the platform binary */
	SYSTEM_INFO_KEY_BUILD_TIME,
	SYSTEM_INFO_DATA_TYPE_STRING,
	system_info_get_build_time
},

{
	SYSTEM_INFO_MAX, -1, NULL
}

};

static system_info_mode_type_e system_info_system_info_model_type;
static int system_info_initialized;

int system_info_get_system_info_initialized()
{
	return system_info_initialized;
}

void system_info_set_system_info_initialized(int value)
{
	system_info_initialized = value;
}

system_info_mode_type_e system_info_get_system_info_model_type()
{
	return system_info_system_info_model_type;
}

int system_info_init(void)
{
	FILE *fp;
	char str[MAXBUFSIZE];
	extern char *strcasestr(const char *s, const char *find);

	fp = popen("uname -m", "r");
	if (NULL == fp) {
		LOGE("[%s] cannot execute uname command!!!", __func__);
		return SYSTEM_INFO_ERROR_IO_ERROR;
	} else {
		while (fgets(str, MAXBUFSIZE, fp)) {
			if (strcasestr(str, "emulated")) {
				system_info_system_info_model_type = SYSTEM_INFO_MODEL_TYPE_EMULATOR;
				system_info_set_system_info_initialized(1);
				pclose(fp);
				return SYSTEM_INFO_ERROR_NONE;

			}
		}

		system_info_system_info_model_type = SYSTEM_INFO_MODEL_TYPE_TARGET;
		system_info_set_system_info_initialized(1);
		pclose(fp);
		return SYSTEM_INFO_ERROR_NONE;
	}
}

static int system_info_get(system_info_key_e key, system_info_h *system_info)
{
	int index = 0;
	int ret_val;

	if (0 == system_info_get_system_info_initialized()) {
		ret_val = system_info_init();
		if (ret_val) {
			LOGE("[%s] system information initialize fail!!!", __func__);
			return ret_val;
		}
	}

	while (system_info_table[index].key != SYSTEM_INFO_MAX) {
		if (system_info_table[index].key == key) {
			*system_info = &system_info_table[index];
			return 0;
		}

		index++;
	}

	return -1;
}

int system_info_get_value(system_info_key_e key, system_info_data_type_e data_type, void **value)
{
	system_info_h system_info;
	system_info_get_value_cb system_info_getter;

	if (value == NULL) {
		LOGE("[%s] INVALID_PARAMETER(0x%08x) : invalid output param", __func__, SYSTEM_INFO_ERROR_INVALID_PARAMETER);
		return SYSTEM_INFO_ERROR_INVALID_PARAMETER;
	}

	if (system_info_get(key, &system_info)) {
		LOGE("[%s] INVALID_PARAMETER(0x%08x) : invalid key", __func__, SYSTEM_INFO_ERROR_INVALID_PARAMETER);
		return SYSTEM_INFO_ERROR_INVALID_PARAMETER;
	}

	if (system_info->data_type != data_type) {
		LOGE("[%s] INVALID_PARAMETER(0x%08x) : invalid data type", __func__, SYSTEM_INFO_ERROR_INVALID_PARAMETER);
		return SYSTEM_INFO_ERROR_INVALID_PARAMETER;
	}

	system_info_getter = system_info->get_value_cb;

	if (system_info_getter == NULL) {
		LOGE("[%s] IO_ERROR(0x%08x) : failed to call getter for the system information", __func__, SYSTEM_INFO_ERROR_IO_ERROR);
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	return system_info_getter(key, system_info->data_type, value);
}

int system_info_get_value_int(system_info_key_e key, int *value)
{
	return system_info_get_value(key, SYSTEM_INFO_DATA_TYPE_INT, (void **)value);
}

int system_info_get_value_bool(system_info_key_e key, bool *value)
{
	return system_info_get_value(key, SYSTEM_INFO_DATA_TYPE_BOOL, (void **)value);
}

int system_info_get_value_double(system_info_key_e key, double *value)
{
	return system_info_get_value(key, SYSTEM_INFO_DATA_TYPE_DOUBLE, (void **)value);
}

int system_info_get_value_string(system_info_key_e key, char **value)
{
	return system_info_get_value(key, SYSTEM_INFO_DATA_TYPE_STRING, (void **)value);
}
