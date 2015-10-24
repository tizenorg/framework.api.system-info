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
#include <unistd.h>
#include <ctype.h>

#include <system_info.h>
#include <system_info_private.h>
#include <sys/utsname.h>

#define SYSTEM_INFO_MAX -1

API int system_info_get_platform_bool(const char *key, bool *value)
{
	int ret;
	bool *supported;
	char *string = NULL;

	supported = (bool *)value;

	if (access(CONFIG_FILE_PATH, R_OK)) {
		_E("cannot find file %s!!!", CONFIG_FILE_PATH);
		if (errno == EPERM || errno == EACCES)
			return SYSTEM_INFO_ERROR_PERMISSION_DENIED;
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	ret = system_info_get_value_from_config_xml(PLATFORM_TAG, key, BOOL_TYPE, &string);
	if (ret) {
		_E("cannot get %s", key);
		return ret;
	}

	if (!strcmp(string, "true") || !strcmp(string, "TRUE"))
		*supported = true;
	else
		*supported = false;

	free(string);

	return SYSTEM_INFO_ERROR_NONE;
}

API int system_info_get_platform_int(const char *key, int *value)
{
	int ret;
	int *ret_val;
	char *string = NULL;

	ret_val = (int *)value;

	if (access(CONFIG_FILE_PATH, R_OK)) {
		_E("cannot find file %s!!!", CONFIG_FILE_PATH);
		if (errno == EPERM || errno == EACCES)
			return SYSTEM_INFO_ERROR_PERMISSION_DENIED;
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	ret = system_info_get_value_from_config_xml(PLATFORM_TAG, key, INT_TYPE, &string);
	if (ret) {
		_E("cannot get %s", key);
		return ret;
	}

	*ret_val = atoi(string);

	free(string);

	return SYSTEM_INFO_ERROR_NONE;
}

API int system_info_get_platform_double(const char *key, double *value)
{
	int ret;
	double *ret_val;
	char *string = NULL;

	ret_val = (double *)value;

	if (access(CONFIG_FILE_PATH, R_OK)) {
		_E("cannot find file %s!!!", CONFIG_FILE_PATH);
		if (errno == EPERM || errno == EACCES)
			return SYSTEM_INFO_ERROR_PERMISSION_DENIED;
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	ret = system_info_get_value_from_config_xml(PLATFORM_TAG, key, DBL_TYPE, &string);
	if (ret) {
		_E("cannot get %s", key);
		return ret;
	}

	*ret_val = atof(string);

	free(string);

	return SYSTEM_INFO_ERROR_NONE;
}

API int system_info_get_platform_string(const char *key, char **value)
{
	int ret;
	char *string = NULL;

	if (access(CONFIG_FILE_PATH, R_OK)) {
		_E("cannot find file %s!!!", CONFIG_FILE_PATH);
		if (errno == EPERM || errno == EACCES)
			return SYSTEM_INFO_ERROR_PERMISSION_DENIED;
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	ret = system_info_get_no_file(key, (void**)&string);
	if (ret == 0) {
		*value = string;
		return SYSTEM_INFO_ERROR_NONE;
	}

	ret = system_info_get_value_from_config_xml(PLATFORM_TAG, key, STR_TYPE, &string);
	if (ret) {
		_E("cannot get %s", key);
		return ret;
	}

	*value = string;

	return SYSTEM_INFO_ERROR_NONE;
}

API int system_info_get_custom_bool(const char *key, bool *value)
{
	int ret;
	bool *supported;
	char *string = NULL;

	supported = (bool *)value;

	if (access(CONFIG_FILE_PATH, R_OK)) {
		_E("cannot find file %s!!!", CONFIG_FILE_PATH);
		if (errno == EPERM || errno == EACCES)
			return SYSTEM_INFO_ERROR_PERMISSION_DENIED;
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	ret = system_info_get_value_from_config_xml(CUSTOM_TAG, key, BOOL_TYPE, &string);
	if (ret) {
		_I("cannot get %s info from %s!!!", key, CONFIG_FILE_PATH);
		ret = external_get_value(CUSTOM_TAG, key, BOOL_TYPE, &string);
		if (ret) {
			_E("Cannot find key (%s) in the plugin (%d)", key, ret);
			return ret;
		}
	}

	if (!strcmp(string, "true") || !strcmp(string, "TRUE"))
		*supported = true;
	else
		*supported = false;

	free(string);

	return SYSTEM_INFO_ERROR_NONE;
}

API int system_info_get_custom_int(const char *key, int *value)
{
	int ret;
	int *ret_val;
	char *string = NULL;

	ret_val = (int *)value;

	if (access(CONFIG_FILE_PATH, R_OK)) {
		_E("cannot find file %s!!!", CONFIG_FILE_PATH);
		if (errno == EPERM || errno == EACCES)
			return SYSTEM_INFO_ERROR_PERMISSION_DENIED;
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	ret = system_info_get_value_from_config_xml(CUSTOM_TAG, key, INT_TYPE, &string);
	if (ret) {
		_I("cannot get %s info from %s!!!", key, CONFIG_FILE_PATH);
		ret = external_get_value(CUSTOM_TAG, key, INT_TYPE, &string);
		if (ret) {
			_E("Cannot find key (%s) in the plugin (%d)", key, ret);
			return ret;
		}
	}

	*ret_val = atoi(string);

	free(string);

	return SYSTEM_INFO_ERROR_NONE;
}

API int system_info_get_custom_double(const char *key, double *value)
{
	int ret;
	double *ret_val;
	char *string = NULL;

	ret_val = (double *)value;

	if (access(CONFIG_FILE_PATH, R_OK)) {
		_E("cannot find file %s!!!", CONFIG_FILE_PATH);
		if (errno == EPERM || errno == EACCES)
			return SYSTEM_INFO_ERROR_PERMISSION_DENIED;
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	ret = system_info_get_value_from_config_xml(CUSTOM_TAG, key, DBL_TYPE, &string);
	if (ret) {
		_I("cannot get %s info from %s!!!", key, CONFIG_FILE_PATH);
		ret = external_get_value(CUSTOM_TAG, key, DBL_TYPE, &string);
		if (ret) {
			_E("Cannot find key (%s) in the plugin (%d)", key, ret);
			return ret;
		}
	}

	*ret_val = atof(string);

	free(string);

	return SYSTEM_INFO_ERROR_NONE;
}

API int system_info_get_custom_string(const char *key, char **value)
{
	int ret;
	char *string = NULL;

	if (access(CONFIG_FILE_PATH, R_OK)) {
		_E("cannot find file %s!!!", CONFIG_FILE_PATH);
		if (errno == EPERM || errno == EACCES)
			return SYSTEM_INFO_ERROR_PERMISSION_DENIED;
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	ret = system_info_get_value_from_config_xml(CUSTOM_TAG, key, STR_TYPE, &string);
	if (ret) {
		_I("cannot get %s info from %s!!!", key, CONFIG_FILE_PATH);
		ret = external_get_value(CUSTOM_TAG, key, STR_TYPE, &string);
		if (ret) {
			_E("Cannot find key (%s) in the plugin (%d)", key, ret);
			return ret;
		}
	}

	*value = string;

	return SYSTEM_INFO_ERROR_NONE;
}
