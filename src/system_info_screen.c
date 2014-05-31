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

#include <dlog.h>

#include <system_info.h>
#include <system_info_private.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif

#define LOG_TAG "CAPI_SYSTEM_INFO"

int system_info_get_screen_width(system_info_key_e key, system_info_data_type_e data_type, void **value)
{
	return system_info_get_platform_int("tizen.org/feature/screen.width", (int *)value);
}

int system_info_get_screen_height(system_info_key_e key, system_info_data_type_e data_type, void **value)
{
	return system_info_get_platform_int("tizen.org/feature/screen.height", (int *)value);
}

int system_info_get_physical_screen_height(system_info_key_e key, system_info_data_type_e data_type, void **value)
{
	int *height;
	char *str;

	height = (int *)value;

	if (system_info_get_bsp_info("board.display.height_mm", &str))
		return SYSTEM_INFO_ERROR_IO_ERROR;

	*height = atoi(str);

	free(str);

	return SYSTEM_INFO_ERROR_NONE;
}

int system_info_get_physical_screen_width(system_info_key_e key, system_info_data_type_e data_type, void **value)
{
	int *width;
	char *str;

	width = (int *)value;

	if (system_info_get_bsp_info("board.display.width_mm", &str))
		return SYSTEM_INFO_ERROR_IO_ERROR;

	*width = atoi(str);

	free(str);

	return SYSTEM_INFO_ERROR_NONE;
}
