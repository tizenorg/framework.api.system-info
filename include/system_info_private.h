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


#ifndef __TIZEN_SYSTEM_SYSTEM_INFO_PRIVATE_H__
#define __TIZEN_SYSTEM_SYSTEM_INFO_PRIVATE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define INFO_FILE_PATH "/etc/info.ini"
#define CPU_INFO_FILE_PATH "/proc/cpuinfo"
#define CPU_INFO_MAX_FREQ_PATH "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq"
#define CMDLINE_PATH "/proc/cmdline"
#define MAXBUFSIZE 512

typedef enum {
	SYSTEM_INFO_DATA_TYPE_STRING,
	SYSTEM_INFO_DATA_TYPE_INT,
	SYSTEM_INFO_DATA_TYPE_DOUBLE,
	SYSTEM_INFO_DATA_TYPE_BOOL
} system_info_data_type_e;

/**
 * @brief Enumeration of Mode type
 */
typedef enum {
	SYSTEM_INFO_MODEL_TYPE_EMULATOR,
	SYSTEM_INFO_MODEL_TYPE_TARGET
} system_info_mode_type_e;

typedef int (*system_info_get_value_cb) (system_info_key_e key, system_info_data_type_e data_type, void **value);

int system_info_init(void);
int system_info_get_system_info_initialized(void);
void system_info_set_system_info_initialized(int value);
system_info_mode_type_e system_info_get_system_info_model_type();

int system_info_vconf_get_value_int(const char *vconf_key, int *value);
int system_info_vconf_get_value_bool(const char *vconf_key, bool *value);
int system_info_vconf_get_value_double(const char *vconf_key, double *value);
int system_info_vconf_get_value_string(const char *vconf_key, char **value);

int system_info_get_model(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_tizen_version(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_platform_name(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_tizen_version_name(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_core_cpu_arch(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_core_fpu_arch(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_core_cpu_freq(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_opengles_texture_format(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_bluetooth_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_camera_count(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_fmradio_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_gps_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_cps_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_wps_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_keyboard_type(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_usb_host_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_usb_accessory_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_multi_point_touch_count(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_network_type(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_mobile_device_id(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_nfc_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_front_camera_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_front_camera_af_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_front_camera_flash_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_back_camera_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_back_camera_af_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_back_camera_flash_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_opengles_version(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_screen_bits_per_pixel(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_screen_height(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_screen_width(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_screen_DPI(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_hdmi_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_rca_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_physical_screen_height(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_physical_screen_width(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_tvout_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_wifi_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_wifi_direct_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_haptic_supproted(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_mobile_device_id(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_csc_sales_code(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_device_uuid(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_sip_voip_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_microphone_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_speech_recognition_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_barometer_sensor_supported(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_build_string(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_build_date(system_info_key_e key, system_info_data_type_e data_type, void **value);
int system_info_get_build_time(system_info_key_e key, system_info_data_type_e data_type, void **value);

#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_SYSTEM_SYSTEM_INFO_PRIVATE_H__ */
