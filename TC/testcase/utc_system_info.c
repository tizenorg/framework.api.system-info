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


#include <tet_api.h>
#include <system_info.h>


static void startup(void);
static void cleanup(void);

void (*tet_startup)(void) = startup;
void (*tet_cleanup)(void) = cleanup;


#define API_NAME_SYSINFO_ACCESSIBLE "system_info_type_accessible"
#define API_NAME_SYSINFO_GOOD_VALUE "system_info_good_value"
#define API_NAME_SYSINFO_SUPPORT_CHECK(key) "system_info_support_check_"#key

/* this is the sting with 2^15 elements, really huge */
#define HUGE_STRING_LEN 65536

/****************************************************************/
/* check if all defined types for results are accessible */
static void utc_system_info_get_int_p(void);
static void utc_system_info_get_int_n(void);
static void utc_system_info_get_bool_p(void);
static void utc_system_info_get_bool_n(void);
static void utc_system_info_get_string_p(void);
static void utc_system_info_get_string_n(void);
static void utc_system_info_get_double_p(void);
static void utc_system_info_get_double_n(void);
static void utc_system_info_get_platform_bool(void);
static void utc_system_info_get_platform_int(void);
static void utc_system_info_get_platform_double(void);
static void utc_system_info_get_platform_string(void);
static void utc_system_info_get_custom_bool(void);
static void utc_system_info_get_custom_int(void);
static void utc_system_info_get_custom_double(void);
static void utc_system_info_get_custom_string(void);
static void utc_system_info_get_internal_value(void);

/****************************************************************/
/* check if all particular informations have reasonable values */
static void utc_system_info_model_p(void);
static void utc_system_info_tizen_ver_p(void);
static void utc_system_info_h_res_p(void);
static void utc_system_info_w_res_p(void);
static void utc_system_info_platform_name_p(void);
static void utc_system_info_platform_ver_p(void);
static void utc_system_info_screen_DPI_p(void);
static void utc_system_info_core_cpu_arch_p(void);
static void utc_system_info_core_freq_p(void);
static void utc_system_info_physical_screen_height_p(void);
static void utc_system_info_physical_screen_width_p(void);
static void utc_system_info_build_string_p(void);
static void utc_system_info_build_date_p(void);
static void utc_system_info_build_time_p(void);
static void utc_system_info_manufacturer_p(void);
static void utc_system_info_tethering_support_key_p(void);

struct tet_testlist tet_testlist[] = {
	{utc_system_info_get_int_p, 1},
	{utc_system_info_get_int_n, 1},
	{utc_system_info_get_bool_p, 1},
	{utc_system_info_get_bool_n, 1},
	{utc_system_info_get_string_p, 1},
	{utc_system_info_get_string_n, 1},
	{utc_system_info_get_double_p, 1},
	{utc_system_info_get_double_n, 1},
	{utc_system_info_model_p, 1},
	{utc_system_info_tizen_ver_p, 1},
	{utc_system_info_h_res_p, 1},
	{utc_system_info_w_res_p, 1},
	{utc_system_info_platform_name_p, 1},
	{utc_system_info_platform_ver_p, 1},
	{utc_system_info_screen_DPI_p, 1},
	{utc_system_info_core_cpu_arch_p, 1},
	{utc_system_info_core_freq_p, 1},
	{utc_system_info_physical_screen_height_p, 1},
	{utc_system_info_physical_screen_width_p, 1},
	{utc_system_info_build_string_p, 1},
	{utc_system_info_build_date_p, 1},
	{utc_system_info_build_time_p, 1},
	{utc_system_info_manufacturer_p, 1},
	{utc_system_info_tethering_support_key_p, 1},
	{utc_system_info_get_platform_bool, 1},
	{utc_system_info_get_platform_int, 1},
	{utc_system_info_get_platform_double, 1},
	{utc_system_info_get_platform_string, 1},
	{utc_system_info_get_custom_bool, 1},
	{utc_system_info_get_custom_int, 1},
	{utc_system_info_get_custom_double, 1},
	{utc_system_info_get_custom_string, 1},
	{utc_system_info_get_internal_value, 1},
	{NULL, 0},
};

static void startup(void)
{

}

static void cleanup(void)
{
	/* end of TC */
}

/****************************************************************/
/* check if all defined types for results are accessible */
static void utc_system_info_get_int_p(void)
{
	int value;

	int retcode = system_info_get_value_int(SYSTEM_INFO_KEY_CAMERA_COUNT, &value);

	if (retcode == SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_ACCESSIBLE, "passed");
	else
		dts_fail(API_NAME_SYSINFO_ACCESSIBLE, "failed");
}

static void utc_system_info_get_int_n(void)
{
	int retcode = system_info_get_value_int(SYSTEM_INFO_KEY_CAMERA_COUNT, NULL);

	if (retcode != SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_ACCESSIBLE, "passed");
	else
		dts_fail(API_NAME_SYSINFO_ACCESSIBLE, "failed");
}

static void utc_system_info_get_bool_p(void)
{
	bool value;

	int retcode = system_info_get_value_bool(SYSTEM_INFO_KEY_BLUETOOTH_SUPPORTED, &value);

	if (retcode == SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_ACCESSIBLE, "passed");
	else
		dts_fail(API_NAME_SYSINFO_ACCESSIBLE, "failed");
}

static void utc_system_info_get_bool_n(void)
{
	int retcode = system_info_get_value_bool(SYSTEM_INFO_KEY_BLUETOOTH_SUPPORTED, NULL);

	if (retcode != SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_ACCESSIBLE, "passed");
	else
		dts_fail(API_NAME_SYSINFO_ACCESSIBLE, "failed");
}

static void utc_system_info_get_string_p(void)
{
	char *value = NULL;

	int retcode = system_info_get_value_string(SYSTEM_INFO_KEY_MODEL, &value);

	if (value) {
		free(value);
	}

	if (retcode == SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_ACCESSIBLE, "passed");
	else
		dts_fail(API_NAME_SYSINFO_ACCESSIBLE, "failed");
}

static void utc_system_info_get_string_n(void)
{
	int retcode = system_info_get_value_string(SYSTEM_INFO_KEY_MODEL, NULL);

	if (retcode != SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_ACCESSIBLE, "passed");
	else
		dts_fail(API_NAME_SYSINFO_ACCESSIBLE, "failed");
}


static void utc_system_info_get_double_p(void)
{
	double value;

	int retcode = system_info_get_value_double(SYSTEM_INFO_KEY_CORE_CPU_FREQ, &value);

	if (retcode == SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_ACCESSIBLE, "passed");
	else
		dts_fail(API_NAME_SYSINFO_ACCESSIBLE, "failed");
}

static void utc_system_info_get_double_n(void)
{
	int retcode = system_info_get_value_double(SYSTEM_INFO_KEY_CORE_CPU_FREQ, NULL);

	if (retcode != SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_ACCESSIBLE, "passed");
	else
		dts_fail(API_NAME_SYSINFO_ACCESSIBLE, "failed");
}

/****************************************************************/
/* check if all particular informations have reasonable values */

static void utc_system_info_model_p(void)
{
	char *string = NULL;
	int string_len = 0;
	int result = 0;

	system_info_get_value_string(SYSTEM_INFO_KEY_MODEL, &string);

	if (string) {
		string_len = strlen(string);
		free(string);
	}

	result = (string_len < HUGE_STRING_LEN)  &&  (string_len > 0);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_tizen_ver_p(void)
{
	char *string = NULL;
	int string_len = 0;
	int result = 0;

	system_info_get_value_string(SYSTEM_INFO_KEY_TIZEN_VERSION, &string);

	if (string) {
		string_len = strlen(string);
		free(string);
	}

	result = (string_len < HUGE_STRING_LEN)  &&  (string_len > 0);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_h_res_p(void)
{
	int h = -1;
	int result = 0;

	system_info_get_value_int(SYSTEM_INFO_KEY_SCREEN_HEIGHT, &h);

	result = (h > 0)  &&  (h < 10000);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_w_res_p(void)
{
	int w = -1;
	int result = 0;

	system_info_get_value_int(SYSTEM_INFO_KEY_SCREEN_WIDTH, &w);

	result = (w > 0)  &&  (w < 10000);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_platform_name_p(void)
{
	char *string = NULL;
	int string_len = 0;
	int result = 0;

	system_info_get_value_string(SYSTEM_INFO_KEY_PLATFORM_NAME, &string);

	if (string) {
		string_len = strlen(string);
		free(string);
	}

	result = (string_len < HUGE_STRING_LEN)  &&  (string_len > 0);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_platform_ver_p(void)
{
	char *string = NULL;
	int string_len = 0;
	int result = 0;

	system_info_get_value_string(SYSTEM_INFO_KEY_TIZEN_VERSION_NAME, &string);

	if (string) {
		string_len = strlen(string);
		free(string);
	}

	result = (string_len < HUGE_STRING_LEN)  &&  (string_len > 0);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_screen_DPI_p(void)
{
	int w = -1;
	int result = 0;

	system_info_get_value_int(SYSTEM_INFO_KEY_SCREEN_DPI, &w);

	result = (w > 0)  &&  (w < 10000);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_core_cpu_arch_p(void)
{
	char *string = NULL;

	int result = system_info_get_value_string(SYSTEM_INFO_KEY_CORE_CPU_ARCH, &string);

	if (string) {
		free(string);
	}

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 0);
}

static void utc_system_info_core_freq_p(void)
{
	double w = 0;
	int result = 0;

	system_info_get_value_double(SYSTEM_INFO_KEY_CORE_CPU_FREQ, &w);

	result = (w > 0)  &&  (w < 10000);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_physical_screen_height_p(void)
{
	int w = -1;
	int result = 0;

	system_info_get_value_int(SYSTEM_INFO_KEY_PHYSICAL_SCREEN_HEIGHT, &w);

	result = (w > 0)  &&  (w < 10000);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_physical_screen_width_p(void)
{
	int w = -1;
	int result = 0;

	system_info_get_value_int(SYSTEM_INFO_KEY_PHYSICAL_SCREEN_WIDTH, &w);

	result = (w > 0)  &&  (w < 10000);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_build_string_p(void)
{
	char *string = NULL;
	int string_len = 0;
	int result = 0;

	system_info_get_value_string(SYSTEM_INFO_KEY_BUILD_STRING, &string);

	if (string) {
		string_len = strlen(string);
		free(string);
	}

	result = (string_len < HUGE_STRING_LEN)  &&  (string_len > 0);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_build_date_p(void)
{
	char *string = NULL;
	int string_len = 0;
	int result = 0;

	system_info_get_value_string(SYSTEM_INFO_KEY_BUILD_DATE, &string);

	if (string) {
		string_len = strlen(string);
		free(string);
	}

	result = (string_len < HUGE_STRING_LEN)  &&  (string_len > 0);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_build_time_p(void)
{
	char *string = NULL;
	int string_len = 0;
	int result = 0;

	system_info_get_value_string(SYSTEM_INFO_KEY_BUILD_TIME, &string);

	if (string) {
		string_len = strlen(string);
		free(string);
	}

	result = (string_len < HUGE_STRING_LEN)  &&  (string_len > 0);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_manufacturer_p(void)
{
	char *string = NULL;
	int string_len = 0;
	int result = 0;

	system_info_get_value_string(SYSTEM_INFO_KEY_MANUFACTURER, &string);

	if (string) {
		string_len = strlen(string);
		free(string);
	}

	result = (string_len < HUGE_STRING_LEN)  &&  (string_len > 0);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_tethering_support_key_p(void)
{
	bool supported;
	int retcode = -1;
	int i;

	retcode = system_info_get_value_bool(SYSTEM_INFO_KEY_TETHERING_SUPPORTED, &supported);

	if (retcode == SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_SUPPORT_CHECK(i), "passed");
	else
		dts_fail(API_NAME_SYSINFO_SUPPORT_CHECK(i), "failed");
}

static void utc_system_info_get_platform_bool(void)
{
	bool supported;
	int retcode = -1;

	retcode = system_info_get_platform_bool("tizen.org/feature/fmradio", &supported);

	if (retcode == SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_SUPPORT_CHECK(i), "passed");
	else
		dts_fail(API_NAME_SYSINFO_SUPPORT_CHECK(i), "failed");
}

static void utc_system_info_get_platform_int(void)
{
	int value = -1;
	int result = 0;

	system_info_get_value_int("tizen.org/feature/screen.bpp", &value);

	result = (value > 0)  &&  (value < 10000);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_get_platform_double(void)
{
	double value;
	int retcode = -1;

	retcode = system_info_get_platform_double("tizen.org/feature/double", &value);

	if (retcode == SYSTEM_INFO_ERROR_IO_ERROR)
		dts_pass(API_NAME_SYSINFO_SUPPORT_CHECK(i), "passed");
	else
		dts_fail(API_NAME_SYSINFO_SUPPORT_CHECK(i), "failed");
}

static void utc_system_info_get_platform_string(void)
{
	char *string = NULL;
	int string_len = 0;
	int result = 0;

	system_info_get_platform_string("tizen.org/system/platform.name", &string);

	if (string) {
		string_len = strlen(string);
		free(string);
	}

	result = (string_len < HUGE_STRING_LEN)  &&  (string_len > 0);

	dts_check_eq(API_NAME_SYSINFO_GOOD_VALUE, result, 1);
}

static void utc_system_info_get_custom_bool(void)
{
	bool value;
	int retcode = -1;

	retcode = system_info_get_custom_bool("tizen.org/feature/double", &value);

	if (retcode == SYSTEM_INFO_ERROR_IO_ERROR)
		dts_pass(API_NAME_SYSINFO_SUPPORT_CHECK(i), "passed");
	else
		dts_fail(API_NAME_SYSINFO_SUPPORT_CHECK(i), "failed");
}

static void utc_system_info_get_custom_int(void)
{
	int value;
	int retcode = -1;

	retcode = system_info_get_custom_int("tizen.org/feature/double", &value);

	if (retcode == SYSTEM_INFO_ERROR_IO_ERROR)
		dts_pass(API_NAME_SYSINFO_SUPPORT_CHECK(i), "passed");
	else
		dts_fail(API_NAME_SYSINFO_SUPPORT_CHECK(i), "failed");
}

static void utc_system_info_get_custom_double(void)
{
	int value;
	int retcode = -1;

	retcode = system_info_get_custom_double("tizen.org/feature/double", &value);

	if (retcode == SYSTEM_INFO_ERROR_IO_ERROR)
		dts_pass(API_NAME_SYSINFO_SUPPORT_CHECK(i), "passed");
	else
		dts_fail(API_NAME_SYSINFO_SUPPORT_CHECK(i), "failed");
}

static void utc_system_info_get_custom_string(void)
{
	char *value = NULL;
	int retcode = -1;

	retcode = system_info_get_custom_string("tizen.org/feature/double", &value);

	if (value)
		free(value);

	if (retcode == SYSTEM_INFO_ERROR_IO_ERROR)
		dts_pass(API_NAME_SYSINFO_SUPPORT_CHECK(i), "passed");
	else
		dts_fail(API_NAME_SYSINFO_SUPPORT_CHECK(i), "failed");
}

static void utc_system_info_get_internal_value(void)
{
	char *value = NULL;
	int retcode = -1;

	retcode = system_info_get_internal_value("board.display.height_mm", &value);

	if (value)
		free(value);

	if (retcode == SYSTEM_INFO_ERROR_NONE)
		dts_pass(API_NAME_SYSINFO_SUPPORT_CHECK(i), "passed");
	else
		dts_fail(API_NAME_SYSINFO_SUPPORT_CHECK(i), "failed");
}