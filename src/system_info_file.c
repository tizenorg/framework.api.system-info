/*
 * Copyright (c) 2014 Samsung Electronics Co., Ltd All Rights Reserved
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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <system_info.h>
#include <system_info_private.h>

#define SERIAL_TOK_DELIMITER ","
#define BUF_MAX 256

static int get_tizenid(char **value)
{
	char id[BUF_MAX];
	FILE *fp;

	fp = fopen(TIZEN_ID_PATH, "r");
	if (!fp) {
		_E("Failed to open file (%s)", TIZEN_ID_PATH);
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	if (fgets(id, sizeof(id), fp) == NULL) {
		_E("Failed to get string (errno:%d)", errno);
		fclose(fp);
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	fclose(fp);

	if (strlen(id) == 0) {
		_E("String length of id is 0");
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	*value = strdup(id);

	return 0;
}

static int get_build_info(char *key, char *buf, unsigned int len)
{
	int ret;
	char *val;

	if (!key)
		return -EINVAL;

	ret = system_info_ini_get_string(INFO_FILE_PATH, key, &val);
	if (ret != SYSTEM_INFO_ERROR_NONE) {
		_E("Failed to get build date(%d)", ret);
		return ret;
	}

	if (!val) {
		_E("val == NULL");
		return SYSTEM_INFO_ERROR_OUT_OF_MEMORY;
	}

	if (strlen(val) == 0) {
		_E("Invalid date");
		free(val);
		return SYSTEM_INFO_ERROR_IO_ERROR;
	}

	snprintf(buf, len, "%s", val);
	free(val);

	return ret;
}

static int get_build_date(char **value)
{
	int ret;
	char date[BUF_MAX];

	ret = get_build_info("build:date", date, sizeof(date));
	if (ret != SYSTEM_INFO_ERROR_NONE) {
		_E("Failed to get build date(%d)", ret);
		return ret;
	}

	*value = strdup(date);

	return SYSTEM_INFO_ERROR_NONE;
}

static int get_build_string(char **value)
{
	int ret;
	char str[BUF_MAX];

	ret = get_build_info("version:build", str, sizeof(str));
	if (ret != SYSTEM_INFO_ERROR_NONE) {
		_E("Failed to get build date(%d)", ret);
		return ret;
	}

	*value = strdup(str);

	return SYSTEM_INFO_ERROR_NONE;
}

static int get_build_time(char **value)
{
	int ret;
	char time[BUF_MAX];

	ret = get_build_info("build:time", time, sizeof(time));
	if (ret != SYSTEM_INFO_ERROR_NONE) {
		_E("Failed to get build date(%d)", ret);
		return ret;
	}

	*value = strdup(time);

	return SYSTEM_INFO_ERROR_NONE;
}

int system_info_get_no_file(const char *key, void **value)
{
	char *p_key;

	if (!key || !value)
		return -EINVAL;

	p_key = strstr(key, "http://");
	if (p_key && p_key == key)
		p_key = (char *)key + strlen("http://");
	else
		p_key = (char *)key;

	if (!strncmp(p_key, "tizen.org/system/tizenid", strlen(p_key))) {
		return get_tizenid((char **)value);
	}

	if (!strncmp(p_key, "tizen.org/system/build.date", strlen(p_key))) {
		return get_build_date((char**)value);
	}

	if (!strncmp(p_key, "tizen.org/system/build.string", strlen(p_key))) {
		return get_build_string((char**)value);
	}

	if (!strncmp(p_key, "tizen.org/system/build.time", strlen(p_key))) {
		return get_build_time((char**)value);
	}

	return -ENOENT;
}
