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


#ifndef __TIZEN_SYSTEM_SYSTEM_INFO_INTERNAL_H__
#define __TIZEN_SYSTEM_SYSTEM_INFO_INTERNAL_H__

#include "system_info_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @internal
 * @addtogroup CAPI_SYSTEM_SYSTEM_INFO_INTERNAL_MODULE
 * @{
 */

/**
 * @brief Enumeration of key for system information
 */
typedef enum {
	SYSTEM_INFO_KEY_MODEL,                  /**< The model of the device */
	SYSTEM_INFO_KEY_TIZEN_VERSION,          /**< The version of the Tizen API */
	SYSTEM_INFO_KEY_PLATFORM_NAME,          /**< The name of platform */
	SYSTEM_INFO_KEY_TIZEN_VERSION_NAME,     /**< The name of tizen version  */
	SYSTEM_INFO_KEY_MANUFACTURER,           /**< The manufacturer of the device */
	SYSTEM_INFO_KEY_CORE_CPU_ARCH,          /**< The CORE CPU architecture of model */
	SYSTEM_INFO_KEY_CORE_CPU_FREQ,          /**< The CORE CPU frequency of model */
	SYSTEM_INFO_KEY_BUILD_STRING,           /**< The build string of platform binary */
	SYSTEM_INFO_KEY_BUILD_DATE,             /**< The build date of platform binary */
	SYSTEM_INFO_KEY_BUILD_TIME,             /**< The build time of platform binary */
	SYSTEM_INFO_KEY_SCREEN_HEIGHT,          /**< The height of the screen in pixels */
	SYSTEM_INFO_KEY_SCREEN_WIDTH,           /**< The width of the screen in pixels */
	SYSTEM_INFO_KEY_PHYSICAL_SCREEN_HEIGHT, /**< The physical screen height in millimeters */
	SYSTEM_INFO_KEY_PHYSICAL_SCREEN_WIDTH,  /**< The physical screen width in millimeters */
	SYSTEM_INFO_KEY_TETHERING_SUPPORTED,    /**< Indicates whether the device supports tethering */
} system_info_key_e;

/**
 * @internal
 * @brief   Gets the integer value of the system information
 * @since_tizen 2.3
 * @param[in] key The name of the system information to get
 * @param[out] value The value of the given system information
 * @return  0 on success, otherwise a negative error value.
 * @retval  #SYSTEM_INFO_ERROR_NONE Successful
 * @retval  #SYSTEM_INFO_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval  #SYSTEM_INFO_ERROR_IO_ERROR An input/output error occurred when read value from system
 */
int system_info_get_value_int(system_info_key_e key, int *value);

/**
 * @internal
 * @brief   Gets the boolean value of the system information
 * @since_tizen 2.3
 * @param[in] key The name of the system information to get
 * @param[out] value The value of the given system information
 * @return  0 on success, otherwise a negative error value.
 * @retval  #SYSTEM_INFO_ERROR_NONE Successful
 * @retval  #SYSTEM_INFO_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval  #SYSTEM_INFO_ERROR_IO_ERROR An input/output error occurred when read value from system
 */
int system_info_get_value_bool(system_info_key_e key, bool *value);

/**
 * @internal
 * @brief   Gets the double value of the system information
 * @since_tizen 2.3
 * @param[in] key The name of the system information to get
 * @param[out] value The value of the given system information
 * @return  0 on success, otherwise a negative error value.
 * @retval  #SYSTEM_INFO_ERROR_NONE Successful
 * @retval  #SYSTEM_INFO_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval  #SYSTEM_INFO_ERROR_IO_ERROR An input/output error occurred when read value from system
 */
int system_info_get_value_double(system_info_key_e key, double *value);

/**
 * @internal
 * @brief   Gets the string value of the system information
 * @since_tizen 2.3
 * @remarks The @a value must be released with @c free() by you.
 * @param[in] key The name of the system information to get
 * @param[out] value The value of the given system information
 * @return  0 on success, otherwise a negative error value.
 * @retval  #SYSTEM_INFO_ERROR_NONE Successful
 * @retval  #SYSTEM_INFO_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval  #SYSTEM_INFO_ERROR_OUT_OF_MEMORY Out of memory
 * @retval  #SYSTEM_INFO_ERROR_IO_ERROR An input/output error occurred when read value from system
 */
int system_info_get_value_string(system_info_key_e key, char **value);


/**
 * @internal
 * @brief   Gets the string value of the internal feature
 * @since_tizen 2.3
 * @remarks The @a value must be released with @c free() by you.
 * @param[in] key The name of the internal feature to get
 * @param[out] value The value of the given internal feature
 * @return  0 on success, otherwise a negative error value.
 * @retval  #SYSTEM_INFO_ERROR_NONE Successful
 * @retval  #SYSTEM_INFO_ERROR_OUT_OF_MEMORY Out of memory
 * @retval  #SYSTEM_INFO_ERROR_INVALID_PARAMETER cannot find key in config files
 * @retval  #SYSTEM_INFO_ERROR_IO_ERROR An input/output error occurred when read value from config files
 */
int system_info_get_internal_value(const char *key, char **value);


/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_SYSTEM_SYSTEM_INFO_INTERNAL_H__ */
